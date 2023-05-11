#ifndef LEDS.H
#define LEDS.H

#include <stdint.h>

void ledsInit(uint16_t * direccion);
void ledsTurnOnSingle(uint8_t led);
void ledsTurnOffSingle(uint8_t led);
void ledsTurnOnAll();
void ledsTurnOffAll();
#endif
