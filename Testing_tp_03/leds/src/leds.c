
#include "leds.h"

static uint16_t * puerto_virtual;

int ledsInit(uint16_t * direccion){
    if(direccion == NULL){
        return 1;
    }
    puerto_virtual = direccion;
    *puerto_virtual = 0;
}

void ledsTurnOnSingle(uint8_t led){
    if (led < 1 || led >= 17){
        return;
    }
    *puerto_virtual |= (1 << (led-1));
}

void ledsTurnOffSingle(uint8_t led){
      if (led < 1 || led >= 17){
        return;
    }
    *puerto_virtual &= (~(1 <<(led-1)));
}

void ledsTurnOnAll(){
    *puerto_virtual = 0xFFFF;
}

void ledsTurnOffAll(){
    *puerto_virtual = 0x0;
}
