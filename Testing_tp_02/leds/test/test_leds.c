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
// Poder utilizar lógica directa e inversa.
// Consultar el estado de un LED

#include "unity.h"
#include "leds.h"


//Al inicializar la biblioteca todos los LEDs quedan apagados
void test_LedsInit(void){
    bool logica_leds = ON_HIGH;
    uint16_t puerto_virtual = 0xFFFF;
    ledsInit(&puerto_virtual, ON_HIGH);
    TEST_ASSERT_EQUAL(0x0000, puerto_virtual);
}

//Con todos los LEDs apagados, enciende el número 2
void test_prender_un_led(void){
    uint16_t puerto_virtual;
    ledsInit(&puerto_virtual, ON_HIGH);
    ledsTurnOnSingle(2);
    TEST_ASSERT_EQUAL(0X0002, puerto_virtual);
}

//Prender y apagar un led
void test_prender_y_apagar_un_led(void){
    uint16_t puerto_virtual;
    ledsInit(&puerto_virtual, ON_HIGH);
    ledsTurnOnSingle(2);
    ledsTurnOffSingle(2);
    TEST_ASSERT_EQUAL(0X0, puerto_virtual);
}

// Con todos los leds apagados, prendo el 3, prendo el 5, apago el 3 y apago el 7,
// deberían quedar el bit 4 en 1 y el resto en 0
void test_prender_y_apagar_varios_led(void){
    uint16_t puerto_virtual;
    ledsInit(&puerto_virtual, ON_HIGH);
    ledsTurnOnSingle(3);
    ledsTurnOnSingle(5);
    ledsTurnOffSingle(3);
    ledsTurnOffSingle(7);
    TEST_ASSERT_EQUAL((1 << (4)), puerto_virtual);
}

// Con todos los leds apagados, prendo todos los leds y verifico que se encienden.
void test_encender_todos_los_leds(void){
uint16_t puerto_virtual;
ledsInit(&puerto_virtual, ON_HIGH);
ledsTurnOnAll();
TEST_ASSERT_EQUAL(0xFFFF, puerto_virtual);
}

// Con todos los leds encendidos, apagar todos los leds y verifico que se apagan.
void test_apagar_todos_los_leds(void){
uint16_t puerto_virtual;
ledsInit(&puerto_virtual, ON_HIGH);
ledsTurnOnAll();
ledsTurnOffAll();
TEST_ASSERT_EQUAL(0x0, puerto_virtual);
}

// Revisa los valores límite de los argumentos.
void test_valores_limite_bajos(void){
int a = 0;
int b = -2;
uint16_t puerto_virtual;
ledsInit(&puerto_virtual, ON_HIGH);
ledsTurnOnSingle(a);
ledsTurnOnSingle(b);
TEST_ASSERT_EQUAL(0x0, puerto_virtual);
}

// Revisa los valores límite altos.
void test_valores_limite_altos(void){
int a = 17;
uint16_t puerto_virtual;
ledsInit(&puerto_virtual, ON_HIGH);
ledsTurnOnSingle(a);
TEST_ASSERT_EQUAL(0x0, puerto_virtual);
}

// Revisa los valores de tipo incorrecto.
void test_valores_limite_tipos_incorrectos(void){
uint16_t puerto_virtual;
float a = 14.7;
ledsInit(&puerto_virtual, ON_HIGH);
ledsTurnOnSingle(a);
TEST_ASSERT_EQUAL(0b0010000000000000, puerto_virtual);
}

// Revisa los valores de tipo incorrecto 2.
void test_valores_limite_tipos_incorrectos_2(void){
uint16_t puerto_virtual;
//En algunos compiladores da error y en otros no, aquí parece desbordar y
//empezar en 0 luego de los 64 bits, en todo caso para solucionar se
//filtraron los valores incorrectos
char a = 'B';
ledsInit(&puerto_virtual, ON_HIGH);
ledsTurnOnSingle(a);
TEST_ASSERT_EQUAL(0x0, puerto_virtual);
}

// Revisa los valores de tipo incorrecto 3.
void test_valores_limite_tipos_incorrectos_3(void){
uint16_t puerto_virtual;
uint16_t * c = NULL;
TEST_ASSERT_EQUAL(0x1, ledsInit(c, ON_HIGH));
}

//Consulta el estado de un LED
void test_consulta_estado(void){
uint16_t puerto_virtual;
ledsInit(&puerto_virtual, ON_HIGH);
ledsTurnOnSingle(4);
ledsTurnOnSingle(15);
TEST_ASSERT_EQUAL(1, ledsConsult(4));
TEST_ASSERT_EQUAL(1, ledsConsult(15));
}

//-------------------------------------------------------
//Tests con lógica invertida


//Al inicializar la biblioteca todos los LEDs quedan apagados
void test_LedsInit_LI(void){
    uint16_t puerto_virtual = 0x0000;
    ledsInit(&puerto_virtual, ON_LOW);
    TEST_ASSERT_EQUAL(0xFFFF, puerto_virtual);
}

//Con todos los LEDs apagados, enciende el número 2
void test_prender_un_led_LI(void){
    uint16_t puerto_virtual;
    ledsInit(&puerto_virtual, ON_LOW);
    ledsTurnOnSingle(2);
    TEST_ASSERT_EQUAL(0b1111111111111101, puerto_virtual);
}

//Prender y apagar un led
void test_prender_y_apagar_un_led_LI(void){
    uint16_t puerto_virtual;
    ledsInit(&puerto_virtual, ON_LOW);
    ledsTurnOnSingle(2);
    ledsTurnOffSingle(2);
    TEST_ASSERT_EQUAL(0XFFFF, puerto_virtual);
}

// Con todos los leds apagados, prendo el 3, prendo el 5, apago el 3 y apago el 7,
// deberían quedar el bit 4 en 1 y el resto en 0
void test_prender_y_apagar_varios_led_LI(void){
    uint16_t puerto_virtual;
    ledsInit(&puerto_virtual, ON_LOW);
    ledsTurnOnSingle(3);
    ledsTurnOnSingle(5);
    ledsTurnOffSingle(3);
    ledsTurnOffSingle(7);
    TEST_ASSERT_EQUAL(0b1111111111101111, puerto_virtual);
}


// Con todos los leds apagados, prendo todos los leds y verifico que se encienden.
void test_encender_todos_los_leds_LI(void){
uint16_t puerto_virtual;
ledsInit(&puerto_virtual, ON_LOW);
ledsTurnOnAll();
TEST_ASSERT_EQUAL(0x0000, puerto_virtual);
}

//Consulta el estado de un LED
void test_consulta_estado_LI(void){
uint16_t puerto_virtual;
ledsInit(&puerto_virtual, ON_LOW);
ledsTurnOnSingle(4);
ledsTurnOnSingle(15);
TEST_ASSERT_EQUAL(0, ledsConsult(4));
TEST_ASSERT_EQUAL(0, ledsConsult(15));
}