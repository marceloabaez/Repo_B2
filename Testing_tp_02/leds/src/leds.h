#ifndef LEDS_H
#define LEDS_H

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

typedef enum{
    ON_HIGH,
    ON_LOW,
}logica;

int ledsInit(uint16_t * direccion, bool logica);
void ledsTurnOnSingle(uint8_t led);
void ledsTurnOffSingle(uint8_t led);
void ledsTurnOnAll();
void ledsTurnOffAll();
bool ledsConsult(uint8_t led);
#endif