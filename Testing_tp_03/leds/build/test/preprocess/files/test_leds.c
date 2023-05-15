#include "src/leds.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"






void test_LedsInit(void){

    uint16_t puerto_virtual = 0xFFFF;

    ledsInit(&puerto_virtual);

    UnityAssertEqualNumber((UNITY_INT)((0x0000)), (UNITY_INT)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(21), UNITY_DISPLAY_STYLE_INT);

}





void test_prender_un_led(void){

    uint16_t puerto_virtual;

    ledsInit(&puerto_virtual);

    ledsTurnOnSingle(2);

    UnityAssertEqualNumber((UNITY_INT)((0X0002)), (UNITY_INT)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(29), UNITY_DISPLAY_STYLE_INT);

}





void test_prender_y_apagar_un_led(void){

    uint16_t puerto_virtual;

    ledsInit(&puerto_virtual);

    ledsTurnOnSingle(2);

    ledsTurnOffSingle(2);

    UnityAssertEqualNumber((UNITY_INT)((0X0)), (UNITY_INT)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(38), UNITY_DISPLAY_STYLE_INT);

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

   ), (UNITY_UINT)(50), UNITY_DISPLAY_STYLE_INT);

}





void test_encender_todos_los_leds(void){

uint16_t puerto_virtual;

ledsInit(&puerto_virtual);

ledsTurnOnAll();

UnityAssertEqualNumber((UNITY_INT)((0xFFFF)), (UNITY_INT)((puerto_virtual)), (

((void *)0)

), (UNITY_UINT)(58), UNITY_DISPLAY_STYLE_INT);

}





void test_apagar_todos_los_leds(void){

uint16_t puerto_virtual;

ledsInit(&puerto_virtual);

ledsTurnOnAll();

ledsTurnOffAll();

UnityAssertEqualNumber((UNITY_INT)((0x0)), (UNITY_INT)((puerto_virtual)), (

((void *)0)

), (UNITY_UINT)(67), UNITY_DISPLAY_STYLE_INT);

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

), (UNITY_UINT)(78), UNITY_DISPLAY_STYLE_INT);

}





void test_valores_limite_altos(void){

int a = 17;



uint16_t puerto_virtual;

ledsInit(&puerto_virtual);

ledsTurnOnSingle(a);



UnityAssertEqualNumber((UNITY_INT)((0x0)), (UNITY_INT)((puerto_virtual)), (

((void *)0)

), (UNITY_UINT)(89), UNITY_DISPLAY_STYLE_INT);

}





void test_valores_limite_tipos_incorrectos(void){

float a = 14.7;



uint16_t puerto_virtual;

ledsInit(&puerto_virtual);

ledsTurnOnSingle(a);



UnityAssertEqualNumber((UNITY_INT)((0b0010000000000000)), (UNITY_INT)((puerto_virtual)), (

((void *)0)

), (UNITY_UINT)(100), UNITY_DISPLAY_STYLE_INT);

}





void test_valores_limite_tipos_incorrectos_2(void){

char a = 'B';



uint16_t puerto_virtual;

ledsInit(&puerto_virtual);

ledsTurnOnSingle(a);



UnityAssertEqualNumber((UNITY_INT)((0x0)), (UNITY_INT)((puerto_virtual)), (

((void *)0)

), (UNITY_UINT)(111), UNITY_DISPLAY_STYLE_INT);

}
