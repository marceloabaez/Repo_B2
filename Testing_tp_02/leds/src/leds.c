
#include "leds.h"

static uint16_t * puerto_virtual;
bool logica_leds = 0;

//inicializa todos los leds apagados
int ledsInit(uint16_t * direccion, bool logica){
    if(direccion == NULL){
        return 1;
    }
    logica_leds = logica;
    puerto_virtual = direccion;
    if (logica_leds == ON_HIGH){
    *puerto_virtual = 0;
    return 0;
    }
    else if(logica_leds == ON_LOW){
    *puerto_virtual = 0xFFFF;
    return 0;
    }
    else{
        return 1;
    }
}

//enciende un solo led
void ledsTurnOnSingle(uint8_t led){
    if (led < 1 || led >= 17){
        return;
    }
    if(logica_leds == ON_HIGH){
    *puerto_virtual |= (1 << (led-1));
    return;
    }
    else if(logica_leds == ON_LOW){
        *puerto_virtual &= (~(1 <<(led-1)));
    }
}

//apaga un solo led
void ledsTurnOffSingle(uint8_t led){
      if (led < 1 || led >= 17){
        return;
    }
    if(logica_leds == ON_HIGH){
    *puerto_virtual &= (~(1 <<(led-1)));
    return;
    }
    else if(logica_leds == ON_LOW){
    *puerto_virtual |= (1 << (led-1));
    return;
    }   
}

//enciende todos los leds
void ledsTurnOnAll(){
    if(logica_leds == ON_HIGH){
    *puerto_virtual = 0xFFFF;
    return;
    }
    else if(logica_leds == ON_LOW){
    *puerto_virtual = 0x0000;
    return;
    }
}

//apaga todos los leds
void ledsTurnOffAll(){
    if(logica_leds == ON_HIGH){
    *puerto_virtual = 0x0;
    return;
    }
    else if(logica_leds == ON_LOW){
    *puerto_virtual = 0xFFFF;
    return;
    }
}

//consulta si un led de encuentra encendido o apagado
bool ledsConsult(uint8_t led){
bool aux = NULL;
if (led < 1 || led >= 17){
        return NULL;
    }
if(logica_leds == ON_HIGH){
    if (*puerto_virtual && (1<<(led-1))){
        return 1;
    }
    else{
        return 0;
    }}

else if(logica_leds == ON_LOW){
    if (!(*puerto_virtual && (1<<(led-1)))){
        return 1;
    }
    else{
        return 0;
    }}

else{
    return NULL;
}
    }