#include "leds.h"
#include <stdbool.h>

bool logica = 0; //0 lógica directa, 1 lógica inversa

static uint16_t * puerto_virtual;

void ledsInit(uint16_t * direccion){
    puerto_virtual = direccion;
    *puerto_virtual = 0;
}

void ledsTurnOnSingle(uint8_t led){
     
    *puerto_virtual |= (1 << (led-1));
}

void ledsTurnOffSingle(uint8_t led){
    *puerto_virtual &= (~(1 <<(led-1)));
}

void ledsTurnOnAll(){
    *puerto_virtual = 0xFFFF;
}

void ledsTurnOffAll(){
    *puerto_virtual = 0x0;
}
