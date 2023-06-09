#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"
#include "src/leds.h"




void test_LedsInit(void) {

  

 _Bool 

      logica_leds = ON_HIGH;

  uint16_t puerto_virtual = 0xFFFF;

  ledsInit(&puerto_virtual, ON_HIGH);

  UnityAssertEqualNumber((UNITY_INT)((0x0000)), (UNITY_INT)((puerto_virtual)), (

 ((void *)0)

 ), (UNITY_UINT)(21), UNITY_DISPLAY_STYLE_INT);

}





void test_prender_un_led(void) {

  uint16_t puerto_virtual;

  ledsInit(&puerto_virtual, ON_HIGH);

  ledsTurnOnSingle(2);

  UnityAssertEqualNumber((UNITY_INT)((0X0002)), (UNITY_INT)((puerto_virtual)), (

 ((void *)0)

 ), (UNITY_UINT)(29), UNITY_DISPLAY_STYLE_INT);

}





void test_prender_y_apagar_un_led(void) {

  uint16_t puerto_virtual;

  ledsInit(&puerto_virtual, ON_HIGH);

  ledsTurnOnSingle(2);

  ledsTurnOffSingle(2);

  UnityAssertEqualNumber((UNITY_INT)((0X0)), (UNITY_INT)((puerto_virtual)), (

 ((void *)0)

 ), (UNITY_UINT)(38), UNITY_DISPLAY_STYLE_INT);

}







void test_prender_y_apagar_varios_led(void) {

  uint16_t puerto_virtual;

  ledsInit(&puerto_virtual, ON_HIGH);

  ledsTurnOnSingle(3);

  ledsTurnOnSingle(5);

  ledsTurnOffSingle(3);

  ledsTurnOffSingle(7);

  UnityAssertEqualNumber((UNITY_INT)(((1 << (4)))), (UNITY_INT)((puerto_virtual)), (

 ((void *)0)

 ), (UNITY_UINT)(50), UNITY_DISPLAY_STYLE_INT);

}







void test_encender_todos_los_leds(void) {

  uint16_t puerto_virtual;

  ledsInit(&puerto_virtual, ON_HIGH);

  ledsTurnOnAll();

  UnityAssertEqualNumber((UNITY_INT)((0xFFFF)), (UNITY_INT)((puerto_virtual)), (

 ((void *)0)

 ), (UNITY_UINT)(59), UNITY_DISPLAY_STYLE_INT);

}







void test_apagar_todos_los_leds(void) {

  uint16_t puerto_virtual;

  ledsInit(&puerto_virtual, ON_HIGH);

  ledsTurnOnAll();

  ledsTurnOffAll();

  UnityAssertEqualNumber((UNITY_INT)((0x0)), (UNITY_INT)((puerto_virtual)), (

 ((void *)0)

 ), (UNITY_UINT)(69), UNITY_DISPLAY_STYLE_INT);

}





void test_valores_limite_bajos(void) {

  int a = 0;

  int b = -2;

  uint16_t puerto_virtual;

  ledsInit(&puerto_virtual, ON_HIGH);

  ledsTurnOnSingle(a);

  ledsTurnOnSingle(b);

  UnityAssertEqualNumber((UNITY_INT)((0x0)), (UNITY_INT)((puerto_virtual)), (

 ((void *)0)

 ), (UNITY_UINT)(80), UNITY_DISPLAY_STYLE_INT);

}





void test_valores_limite_altos(void) {

  int a = 17;

  uint16_t puerto_virtual;

  ledsInit(&puerto_virtual, ON_HIGH);

  ledsTurnOnSingle(a);

  UnityAssertEqualNumber((UNITY_INT)((0x0)), (UNITY_INT)((puerto_virtual)), (

 ((void *)0)

 ), (UNITY_UINT)(89), UNITY_DISPLAY_STYLE_INT);

}





void test_valores_limite_tipos_incorrectos(void) {

  uint16_t puerto_virtual;

  float a = 14.7;

  ledsInit(&puerto_virtual, ON_HIGH);

  ledsTurnOnSingle(a);

  UnityAssertEqualNumber((UNITY_INT)((0b0010000000000000)), (UNITY_INT)((puerto_virtual)), (

 ((void *)0)

 ), (UNITY_UINT)(98), UNITY_DISPLAY_STYLE_INT);

}





void test_valores_limite_tipos_incorrectos_2(void) {

  uint16_t puerto_virtual;







  char a = 'B';

  ledsInit(&puerto_virtual, ON_HIGH);

  ledsTurnOnSingle(a);

  UnityAssertEqualNumber((UNITY_INT)((0x0)), (UNITY_INT)((puerto_virtual)), (

 ((void *)0)

 ), (UNITY_UINT)(110), UNITY_DISPLAY_STYLE_INT);

}





void test_valores_limite_tipos_incorrectos_3(void) {

  uint16_t puerto_virtual;

  uint16_t *c = 

               ((void *)0)

                   ;

  UnityAssertEqualNumber((UNITY_INT)((0x1)), (UNITY_INT)((ledsInit(c, ON_HIGH))), (

 ((void *)0)

 ), (UNITY_UINT)(117), UNITY_DISPLAY_STYLE_INT);

}





void test_consulta_estado(void) {

  uint16_t puerto_virtual;

  ledsInit(&puerto_virtual, ON_HIGH);

  ledsTurnOnSingle(4);

  ledsTurnOnSingle(15);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((ledsIsTurnedOn(4))), (

 ((void *)0)

 ), (UNITY_UINT)(126), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((ledsIsTurnedOn(15))), (

 ((void *)0)

 ), (UNITY_UINT)(127), UNITY_DISPLAY_STYLE_INT);

}











void test_LedsInit_LI(void) {

  uint16_t puerto_virtual = 0x0000;

  ledsInit(&puerto_virtual, ON_LOW);

  UnityAssertEqualNumber((UNITY_INT)((0xFFFF)), (UNITY_INT)((puerto_virtual)), (

 ((void *)0)

 ), (UNITY_UINT)(137), UNITY_DISPLAY_STYLE_INT);

}





void test_prender_un_led_LI(void) {

  uint16_t puerto_virtual;

  ledsInit(&puerto_virtual, ON_LOW);

  ledsTurnOnSingle(2);

  UnityAssertEqualNumber((UNITY_INT)((0b1111111111111101)), (UNITY_INT)((puerto_virtual)), (

 ((void *)0)

 ), (UNITY_UINT)(145), UNITY_DISPLAY_STYLE_INT);

}





void test_prender_y_apagar_un_led_LI(void) {

  uint16_t puerto_virtual;

  ledsInit(&puerto_virtual, ON_LOW);

  ledsTurnOnSingle(2);

  ledsTurnOffSingle(2);

  UnityAssertEqualNumber((UNITY_INT)((0XFFFF)), (UNITY_INT)((puerto_virtual)), (

 ((void *)0)

 ), (UNITY_UINT)(154), UNITY_DISPLAY_STYLE_INT);

}







void test_prender_y_apagar_varios_led_LI(void) {

  uint16_t puerto_virtual;

  ledsInit(&puerto_virtual, ON_LOW);

  ledsTurnOnSingle(3);

  ledsTurnOnSingle(5);

  ledsTurnOffSingle(3);

  ledsTurnOffSingle(7);

  UnityAssertEqualNumber((UNITY_INT)((0b1111111111101111)), (UNITY_INT)((puerto_virtual)), (

 ((void *)0)

 ), (UNITY_UINT)(166), UNITY_DISPLAY_STYLE_INT);

}







void test_encender_todos_los_leds_LI(void) {

  uint16_t puerto_virtual;

  ledsInit(&puerto_virtual, ON_LOW);

  ledsTurnOnAll();

  UnityAssertEqualNumber((UNITY_INT)((0x0000)), (UNITY_INT)((puerto_virtual)), (

 ((void *)0)

 ), (UNITY_UINT)(175), UNITY_DISPLAY_STYLE_INT);

}





void test_consulta_estado_LI(void) {

  uint16_t puerto_virtual;

  ledsInit(&puerto_virtual, ON_LOW);

  ledsTurnOnSingle(4);

  ledsTurnOnSingle(15);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ledsIsTurnedOn(4))), (

 ((void *)0)

 ), (UNITY_UINT)(184), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ledsIsTurnedOn(15))), (

 ((void *)0)

 ), (UNITY_UINT)(185), UNITY_DISPLAY_STYLE_INT);

}
