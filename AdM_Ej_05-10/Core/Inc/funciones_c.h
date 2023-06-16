#ifndef __FUNCIONES_C_H
#define __FUNCIONES_C_H

#include <stdint.h>

void filtroVentana10(uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitudVectorIn);
void pack32to16 (int32_t * vectorIn, int16_t *vectorOut, uint32_t longitud);
uint32_t max (int32_t * vectorIn, uint32_t longitud);
void downsampleM (int32_t * vectorIn, int32_t * vectorOut, uint32_t longitud, uint32_t N);
void invertir(uint16_t * vector, uint32_t longitud);
void eco(int16_t * entrada, uint32_t longitud);

#endif
