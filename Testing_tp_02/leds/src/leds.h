#ifndef LEDS_H
#define LEDS_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef enum {
  ON_HIGH,
  ON_LOW,
} logica;

typedef enum {
  SUCCESS,
  FAIL,
} retorno;

int ledsInit(uint16_t *direccion, bool logica);
void ledsTurnOnSingle(uint8_t led);
void ledsTurnOffSingle(uint8_t led);
void ledsTurnOnAll();
void ledsTurnOffAll();
bool ledsIsTurnedOn(uint8_t led);
#endif
