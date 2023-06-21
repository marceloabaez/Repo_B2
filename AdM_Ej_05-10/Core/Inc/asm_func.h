#pragma once

#include <stdint.h>

void asm_filtroVentana10(uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitudVectorIn);
void asm_pack32to16 (int32_t * vectorIn, int16_t *vectorOut, uint32_t longitud);
uint32_t asm_max (int32_t * vectorIn, uint32_t longitud);
void asm_downsampleM (int32_t * vectorIn, int32_t * vectorOut, uint32_t longitud, uint32_t N);
void asm_invertir(uint16_t * vector, uint32_t longitud);
void asm_eco(int16_t * entrada, uint32_t longitud);
void asm_eco_SIMD(int16_t * entrada, uint32_t longitud);
void asm_eco_SIMD_10(int16_t * entrada, uint32_t longitud);
void corr(int16_t * vectorX, int16_t * vectorY, int16_t * vectorCorr, uint32_t longitud);
void corr_SIMD(int16_t * vectorX, int16_t * vectorY, int16_t * vectorCorr, uint32_t longitud);
