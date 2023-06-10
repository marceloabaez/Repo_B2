#ifndef __FUNCIONES_C_H
#define __FUNCIONES_C_H

#include <stdint.h>

void filtroVentana10(uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitudVectorIn);
void pack32to16 (int32_t * vectorIn, int16_t *vectorOut, uint32_t longitud);
uint32_t max (int32_t * vectorIn, uint32_t longitud);

#endif
