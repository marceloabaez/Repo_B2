/*
 * funciones_c.c
 *
 *  Created on: 9 jun. 2023
 *      Author: marcelo
 */


//#include "funciones_c.h"

#include <stdint.h>

#define SIZE_VENTANA 10



void filtroVentana10(uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitudVectorIn){

	int32_t index1 = 0;
	int32_t index2 = 0;

	for(index1 = 0; index1 < longitudVectorIn; index1++){
		uint32_t resultado = 0;
		for(index2 = (index1 - SIZE_VENTANA/2); index2 <= (index1 + SIZE_VENTANA/2) ; index2++){

			if(index2 < 0){
				resultado += vectorIn[0];}
			else if(index2 >= longitudVectorIn){
					resultado += vectorIn[(longitudVectorIn - 1)];}
			else{
				resultado += vectorIn[index2];
			}
		}
		vectorOut[index1] = resultado / (SIZE_VENTANA + 1);
	}}



void pack32to16 (int32_t * vectorIn, int16_t *vectorOut, uint32_t longitud){

	for(uint32_t i = 0; i < longitud; i++){
		vectorOut[i] = (int16_t) (vectorIn[i] >> 16);
	}
}


uint32_t max (int32_t * vectorIn, uint32_t longitud){
	uint32_t posicion = 0;
	int32_t max = vectorIn[0];
	for(uint32_t i = 1; i < longitud; i++){
		if(vectorIn[i] > max){
			max = vectorIn[i];
			posicion = i;
		}
	}
	return posicion;
}

void downsampleM (int32_t * vectorIn, int32_t * vectorOut, uint32_t longitud, uint32_t N){
	uint32_t salto = N;
	uint32_t indiceOut = 0;
	for(uint32_t i = 0; i < longitud; i++){
		if(i == (salto - 1)){
			salto += N;
			continue;
		}
		vectorOut[indiceOut] = vectorIn[i];
		indiceOut ++;
	}
return;
}

