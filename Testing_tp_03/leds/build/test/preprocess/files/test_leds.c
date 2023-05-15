#include "src/leds.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"






void test_LedsInit(void){

    uint16_t puerto_virtual = 0xFFFF;

    ledsInit(&puerto_virtual);

    UnityAssertEqualNumber((UNITY_INT)((0x0000)), (UNITY_INT)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(22), UNITY_DISPLAY_STYLE_INT);

}





void test_prender_un_led(void){

    uint16_t puerto_virtual;

    ledsInit(&puerto_virtual);

    ledsTurnOnSingle(2);

    UnityAssertEqualNumber((UNITY_INT)((0X0002)), (UNITY_INT)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(30), UNITY_DISPLAY_STYLE_INT);

}





void test_prender_y_apagar_un_led(void){

    uint16_t puerto_virtual;

    ledsInit(&puerto_virtual);

    ledsTurnOnSingle(2);

    ledsTurnOffSingle(2);

    UnityAssertEqualNumber((UNITY_INT)((0X0)), (UNITY_INT)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(39), UNITY_DISPLAY_STYLE_INT);

}







void test_prender_y_apagar_varios_led(void){

    uint16_t puerto_virtual;

    ledsInit(&puerto_virtual);

    ledsTurnOnSingle(3);

    ledsTurnOnSingle(5);

    ledsTurnOffSingle(3);

    ledsTurnOffSingle(7);

    UnityAssertEqualNumber((UNITY_INT)(((1 << (4)))), (UNITY_INT)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(51), UNITY_DISPLAY_STYLE_INT);

}





void test_encender_todos_los_leds(void){

uint16_t puerto_virtual;

ledsInit(&puerto_virtual);

ledsTurnOnAll();

UnityAssertEqualNumber((UNITY_INT)((0xFFFF)), (UNITY_INT)((puerto_virtual)), (

((void *)0)

), (UNITY_UINT)(59), UNITY_DISPLAY_STYLE_INT);

}





void test_apagar_todos_los_leds(void){

uint16_t puerto_virtual;

ledsInit(&puerto_virtual);

ledsTurnOnAll();

ledsTurnOffAll();

UnityAssertEqualNumber((UNITY_INT)((0x0)), (UNITY_INT)((puerto_virtual)), (

((void *)0)

), (UNITY_UINT)(68), UNITY_DISPLAY_STYLE_INT);

}





void test_valores_limite_bajos(void){

int a = 0;

int b = -2;

uint16_t puerto_virtual;

ledsInit(&puerto_virtual);

ledsTurnOnSingle(a);

ledsTurnOnSingle(b);

UnityAssertEqualNumber((UNITY_INT)((0x0)), (UNITY_INT)((puerto_virtual)), (

((void *)0)

), (UNITY_UINT)(79), UNITY_DISPLAY_STYLE_INT);

}





void test_valores_limite_altos(void){

int a = 17;

uint16_t puerto_virtual;

ledsInit(&puerto_virtual);

ledsTurnOnSingle(a);

UnityAssertEqualNumber((UNITY_INT)((0x0)), (UNITY_INT)((puerto_virtual)), (

((void *)0)

), (UNITY_UINT)(88), UNITY_DISPLAY_STYLE_INT);

}





void test_valores_limite_tipos_incorrectos(void){

uint16_t puerto_virtual;

float a = 14.7;

ledsInit(&puerto_virtual);

ledsTurnOnSingle(a);

UnityAssertEqualNumber((UNITY_INT)((0b0010000000000000)), (UNITY_INT)((puerto_virtual)), (

((void *)0)

), (UNITY_UINT)(97), UNITY_DISPLAY_STYLE_INT);

}





void test_valores_limite_tipos_incorrectos_2(void){

uint16_t puerto_virtual;







char a = 'B';

ledsInit(&puerto_virtual);

ledsTurnOnSingle(a);

UnityAssertEqualNumber((UNITY_INT)((0x0)), (UNITY_INT)((puerto_virtual)), (

((void *)0)

), (UNITY_UINT)(109), UNITY_DISPLAY_STYLE_INT);

}





void test_valores_limite_tipos_incorrectos_3(void){

uint16_t puerto_virtual;

uint16_t * c = 

              ((void *)0)

                  ;

UnityAssertEqualNumber((UNITY_INT)((0x1)), (UNITY_INT)((ledsInit(c))), (

((void *)0)

), (UNITY_UINT)(116), UNITY_DISPLAY_STYLE_INT);

}
