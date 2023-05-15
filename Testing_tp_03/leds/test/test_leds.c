// Al inciarlizar la biblioteca todos los leds quedan apagados.
// Con todos los leds apagados, prendo el led 2, verifico que se el bit 1 vale 1.
// Con el led 2 prendido, apago el led 2, verifico que se enciende el bit 1 vale 0.
// Con todos los leds apagados, prendo el 3, prendo el 5, apago el 3 y apago el 7,
// deberían quedar el bit 4 en 1 y el resto en 0
// Prendo un led, consulto el estado y tiene que estar prendido.
// Apago un led, consulto el estado y tiene que estar apagado.
// Con todos los leds apagados, prendo todos los leds y verifico que se encienden.
// Con todos los leds prendidor, apagado todos los leds y verifico que se apagan.
// Revisar los valores limites de los argumentos.
// Revisar que pasa con valores erroneos en los argumento.

#include "unity.h"
#include "leds.h"


//Al inicializar la biblioteca todos los LEDs quedan apagados
void test_LedsInit(void){
    uint16_t puerto_virtual = 0xFFFF;
    ledsInit(&puerto_virtual);
    TEST_ASSERT_EQUAL(0x0000, puerto_virtual);
}

//Con todos los LEDs apagados, enciende el número 2
void test_prender_un_led(void){
    uint16_t puerto_virtual;
    ledsInit(&puerto_virtual);
    ledsTurnOnSingle(2);
    TEST_ASSERT_EQUAL(0X0002, puerto_virtual);
}

//Prender y apagar un led
void test_prender_y_apagar_un_led(void){
    uint16_t puerto_virtual;
    ledsInit(&puerto_virtual);
    ledsTurnOnSingle(2);
    ledsTurnOffSingle(2);
    TEST_ASSERT_EQUAL(0X0, puerto_virtual);
}

// Con todos los leds apagados, prendo el 3, prendo el 5, apago el 3 y apago el 7,
// deberían quedar el bit 4 en 1 y el resto en 0
void test_prender_y_apagar_varios_led(void){
    uint16_t puerto_virtual;
    ledsInit(&puerto_virtual);
    ledsTurnOnSingle(3);
    ledsTurnOnSingle(5);
    ledsTurnOffSingle(3);
    ledsTurnOffSingle(7);
    TEST_ASSERT_EQUAL((1 << (4)), puerto_virtual);
}

// Con todos los leds apagados, prendo todos los leds y verifico que se encienden.
void test_encender_todos_los_leds(void){
uint16_t puerto_virtual;
ledsInit(&puerto_virtual);
ledsTurnOnAll();
TEST_ASSERT_EQUAL(0xFFFF, puerto_virtual);
}

// Con todos los leds encendidos, apagar todos los leds y verifico que se apagan.
void test_apagar_todos_los_leds(void){
uint16_t puerto_virtual;
ledsInit(&puerto_virtual);
ledsTurnOnAll();
ledsTurnOffAll();
TEST_ASSERT_EQUAL(0x0, puerto_virtual);
}

// Revisa los valores límite de los argumentos.
void test_valores_limite_bajos(void){
int a = 0;
int b = -2;
uint16_t puerto_virtual;
ledsInit(&puerto_virtual);
ledsTurnOnSingle(a);
ledsTurnOnSingle(b);
TEST_ASSERT_EQUAL(0x0, puerto_virtual);
}

// Revisa los valores límite altos.
void test_valores_limite_altos(void){
int a = 17;
//int b = 20;
uint16_t puerto_virtual;
ledsInit(&puerto_virtual);
ledsTurnOnSingle(a);
//ledsTurnOnSingle(b);
TEST_ASSERT_EQUAL(0x0, puerto_virtual);
}

// Revisa los valores de tipo incorrecto.
void test_valores_limite_tipos_incorrectos(void){
float a = 14.7;
//int b = 20;
uint16_t puerto_virtual;
ledsInit(&puerto_virtual);
ledsTurnOnSingle(a);
//ledsTurnOnSingle(b);
TEST_ASSERT_EQUAL(0b0010000000000000, puerto_virtual);
}

// Revisa los valores de tipo incorrecto 2.
void test_valores_limite_tipos_incorrectos_2(void){
char a = 'B';
//int b = 20;
uint16_t puerto_virtual;
ledsInit(&puerto_virtual);
ledsTurnOnSingle(a);
//ledsTurnOnSingle(b);
TEST_ASSERT_EQUAL(0x0, puerto_virtual);
}