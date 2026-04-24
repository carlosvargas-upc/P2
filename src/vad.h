
#ifndef _VAD_H
#define _VAD_H
#include <stdio.h>


/* Estados extendidos de la máquina */
typedef enum {
  ST_UNDEF=0,
  ST_SILENCE,
  ST_VOICE,
  ST_INIT,
  ST_MAYBE_VOICE,
  ST_MAYBE_SILENCE
} VAD_STATE;


const char *state2str(VAD_STATE st);


typedef struct {
  VAD_STATE state;
  float sampling_rate;
  unsigned int frame_length;
  float last_feature;
 
  /* Variables para el seguimiento dinámico del ruido de fondo */
  float noise_power;  
  float noise_zcr;    
  float noise_am;    
 
  /* Contadores para la máquina de estados */
  unsigned int init_count;  
  unsigned int count_voice;
  unsigned int count_sil;  
 
} VAD_DATA;


VAD_DATA *vad_open(float sampling_rate);
unsigned int vad_frame_size(VAD_DATA *);
VAD_STATE vad(VAD_DATA *vad_data, float *x, float alpha0);
VAD_STATE vad_close(VAD_DATA *vad_data);
void vad_show_state(const VAD_DATA *, FILE *);


#endif


