#ifndef LEDS_H
#define LEDS_H

#include <stdint.h>

typedef enum{
    ON_HIGH,
    ON_LOW,
}logica;

void ledsInit(uint16_t * direccion);
void ledsTurnOnSingle(uint8_t led);
void ledsTurnOffSingle(uint8_t led);
void ledsTurnOnAll();
void ledsTurnOffAll();
#endif
