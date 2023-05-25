
#include "leds.h"

#define ALL_BITS_SETED 0xFFFF
#define ALL_BITS_CLEARED 0x0
#define NUM_LEDS 16

static uint16_t all_leds_off;
static uint16_t *puerto_virtual;
bool logica_leds;

// inicializa todos los leds apagados
int ledsInit(uint16_t *direccion, bool logica) {
  if (direccion == NULL) {
    return FAIL;
  }
  logica_leds = logica;
  puerto_virtual = direccion;
  if (logica_leds == ON_HIGH) {
    all_leds_off = ALL_BITS_CLEARED;
  } else if (logica_leds == ON_LOW) {
    all_leds_off = ALL_BITS_SETED;
  }
  ledsTurnOffAll();
  return SUCCESS;
}

// enciende un solo led
void ledsTurnOnSingle(uint8_t led) {
  if (led < 1 || led >= (NUM_LEDS + 1)) {
    return;
  }
  if (logica_leds == ON_HIGH) {
    *puerto_virtual |= (1 << (led - 1));
  } else if (logica_leds == ON_LOW) {
    *puerto_virtual &= (~(1 << (led - 1)));
  }
}

// apaga un solo led
void ledsTurnOffSingle(uint8_t led) {
  if (led < 1 || led >= (NUM_LEDS + 1)) {
    return;
  }
  if (logica_leds == ON_HIGH) {
    *puerto_virtual &= (~(1 << (led - 1)));
  } else if (logica_leds == ON_LOW) {
    *puerto_virtual |= (1 << (led - 1));
  }
}

// enciende todos los leds
void ledsTurnOnAll() {
  *puerto_virtual = ~ all_leds_off;
}

// apaga todos los leds
void ledsTurnOffAll() {
  *puerto_virtual = all_leds_off;
}

// consulta si un led de encuentra encendido o apagado
bool ledsIsTurnedOn(uint8_t led) {
  bool aux = NULL;
  if (led < 1 || led >= (NUM_LEDS + 1)) {
    return NULL;
  }
  if (logica_leds == ON_HIGH) {
    if (*puerto_virtual && (1 << (led - 1))) {
      return 1;
    } else {
      return 0;
    }
  }

  else if (logica_leds == ON_LOW) {
    if (!(*puerto_virtual && (1 << (led - 1)))) {
      return 1;
    } else {
      return 0;
    }
  }

  else {
    return NULL;
  }
}