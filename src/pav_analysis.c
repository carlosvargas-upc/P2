#include <math.h>
#include "pav_analysis.h"

float compute_power(const float *x, unsigned int N) {
   float power = 1e-12;
    for (unsigned int i = 0; i < N; i++) {
        power += x[i] * x[i]; 
    }
    power = power / N; 

    if (power > 0) return 10.0 * log10(power); 
}

float compute_am(const float *x, unsigned int N) {
    float sum = 0;
     for (unsigned int i = 0; i < N; i++) {
        sum += fabsf(x[i]);
     }
    float media = sum / N;
    return media;
}

float compute_zcr(const float *x, unsigned int N, float fm) {
float cuenta = 0;
    for (unsigned int i = 1; i < N; i++) {
        if ((x[i] > 0 && x[i-1] <= 0) || (x[i] <= 0 && x[i-1] > 0)) {
            cuenta++;
        }
    }
    return (fm / 2.0) * (cuenta / (N - 1));
}
