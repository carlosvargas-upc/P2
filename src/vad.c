
#include <math.h>
#include <stdlib.h>
#include <stdio.h>


#include "vad.h"
#include "pav_analysis.h"


const float FRAME_TIME = 10.0F;


const unsigned int INIT_FRAMES = 10;
const unsigned int HANG_IN = 3;      
const unsigned int HANG_OVER = 10;  


const float ALPHA_ZCR = 2000.0F;
const float MULTIPLIER_AM = 5.0F;


const float HYSTERESIS_DB = 2.0F;


const float ZCR_NOISE_FLOOR_MARGIN = 0.0F;


const float NOISE_UPDATE_RATE = 0.01F;


const char *state_str[] = {
  "UNDEF", "S", "V", "INIT", "S", "V"
};


const char *state2str(VAD_STATE st) {
  return state_str[st];
}


typedef struct {
  float zcr;
  float p;
  float am;
} Features;


Features compute_features(const float *x, int N, float fm) {
  Features feat;
  feat.p = compute_power(x, N);
  feat.zcr = compute_zcr(x, N, fm);
  feat.am = compute_am(x, N);
  return feat;
}


VAD_DATA * vad_open(float rate) {
  VAD_DATA *vad_data = malloc(sizeof(VAD_DATA));
  vad_data->state = ST_INIT;
  vad_data->sampling_rate = rate;
  vad_data->frame_length = rate * FRAME_TIME * 1e-3;
 
  vad_data->noise_power = 0.0f;
  vad_data->noise_zcr = 0.0f;
  vad_data->noise_am = 0.0f;
 
  vad_data->init_count = 0;
  vad_data->count_voice = 0;
  vad_data->count_sil = 0;
 
  return vad_data;
}


VAD_STATE vad_close(VAD_DATA *vad_data) {
  VAD_STATE state = vad_data->state;
  free(vad_data);
  return state;
}


unsigned int vad_frame_size(VAD_DATA *vad_data) {
  return vad_data->frame_length;
}


VAD_STATE vad(VAD_DATA *vad_data, float *x, float alpha0) {


  Features f = compute_features(x, vad_data->frame_length, vad_data->sampling_rate);
  vad_data->last_feature = f.p;
 
 
  float thresh_p_on  = vad_data->noise_power + alpha0;
  float thresh_am_on = vad_data->noise_am * MULTIPLIER_AM;
 
  float thresh_p_off  = thresh_p_on - HYSTERESIS_DB;
  float thresh_am_off = thresh_am_on * 0.8F;
 
  float thresh_zcr = vad_data->noise_zcr + ALPHA_ZCR;
 
  int zcr_is_valid = (f.p >= (vad_data->noise_power - ZCR_NOISE_FLOOR_MARGIN));
  int zcr_active = (f.zcr > thresh_zcr) && zcr_is_valid;
 
  int is_active_on  = (f.p > thresh_p_on)  || zcr_active || (f.am > thresh_am_on);
  int is_active_off = (f.p > thresh_p_off) || zcr_active || (f.am > thresh_am_off);


  switch (vad_data->state) {
  case ST_INIT:
    vad_data->noise_power += f.p;
    vad_data->noise_zcr += f.zcr;
    vad_data->noise_am += f.am;
    vad_data->init_count++;
   
    if (vad_data->init_count >= INIT_FRAMES) {
      vad_data->noise_power /= INIT_FRAMES;
      vad_data->noise_zcr /= INIT_FRAMES;
      vad_data->noise_am /= INIT_FRAMES;
      vad_data->state = ST_SILENCE;
    }
    break;


  case ST_SILENCE:
    if (is_active_on) {
      vad_data->state = ST_MAYBE_VOICE;
      vad_data->count_voice = 1;
    } else {
      vad_data->noise_power = (1.0F - NOISE_UPDATE_RATE) * vad_data->noise_power + NOISE_UPDATE_RATE * f.p;
      vad_data->noise_zcr   = (1.0F - NOISE_UPDATE_RATE) * vad_data->noise_zcr   + NOISE_UPDATE_RATE * f.zcr;
      vad_data->noise_am    = (1.0F - NOISE_UPDATE_RATE) * vad_data->noise_am    + NOISE_UPDATE_RATE * f.am;
    }
    break;


  case ST_MAYBE_VOICE:
    if (is_active_on) {
      vad_data->count_voice++;
      if (vad_data->count_voice >= HANG_IN) {
        vad_data->state = ST_VOICE;
      }
    } else {
      vad_data->state = ST_SILENCE;
    }
    break;


  case ST_VOICE:
    if (!is_active_off) {
      vad_data->state = ST_MAYBE_SILENCE;
      vad_data->count_sil = 1;
    }
    break;


  case ST_MAYBE_SILENCE:
    if (!is_active_off) {
      vad_data->count_sil++;
      if (vad_data->count_sil >= HANG_OVER) {
        vad_data->state = ST_SILENCE;
      }
    } else {
      vad_data->state = ST_VOICE;
    }
    break;


  case ST_UNDEF:
    break;
  }


  if (vad_data->state == ST_VOICE || vad_data->state == ST_MAYBE_SILENCE) {
    return ST_VOICE;
  } else {
    return ST_SILENCE;
  }
}


void vad_show_state(const VAD_DATA *vad_data, FILE *out) {
  VAD_STATE effective_state = (vad_data->state == ST_VOICE || vad_data->state == ST_MAYBE_SILENCE) ? ST_VOICE : ST_SILENCE;
  fprintf(out, "%d\t%f\n", effective_state, vad_data->last_feature);
}


