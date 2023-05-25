#include "build/test/mocks/mock_API_uart.h"
#include "build/test/mocks/mock_API_RTC_port.h"
#include "src/API_RTC.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


extern int estado;

extern char i2c_msg[];

extern uint8_t buff[];

extern char fecha_i[];

extern char hora_i[];

uint8_t hora_inicial_bcd[] = {21,69,32};

uint8_t fecha_inicial_bcd[] = {21,4,35};

extern uint8_t hora[3];

extern uint8_t fecha[3];





void test_inicializar_RTC(void){

    int a = -1;

    I2C_Write_CMockIgnore();

    RTC_init();

    a = memcmp(buff,hora_inicial_bcd,3);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((a)), (

   ((void *)0)

   ), (UNITY_UINT)(45), UNITY_DISPLAY_STYLE_INT);

}





void test_leer_desde_RTC(void){

    int a = -1;

    I2C_Write_CMockIgnore();

    I2C_Read_CMockIgnore();

    RTC_send_fecha(fecha_i);

    RTC_leer_fecha();

    a = memcmp(i2c_msg,fecha_i,8);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((a)), (

   ((void *)0)

   ), (UNITY_UINT)(56), UNITY_DISPLAY_STYLE_INT);

}







void test_transiciones_entre_estado_MEF(void){

    I2C_Write_CMockIgnore();

    I2C_Read_CMockIgnore();

    uartSendString_CMockIgnore();

    RTC_init();



    UnityAssertEqualNumber((UNITY_INT)((estado)), (UNITY_INT)((RTC_inactivo)), (

   ((void *)0)

   ), (UNITY_UINT)(67), UNITY_DISPLAY_STYLE_INT);



    RTC_estado('A');

    UnityAssertEqualNumber((UNITY_INT)((estado)), (UNITY_INT)((RTC_inactivo)), (

   ((void *)0)

   ), (UNITY_UINT)(70), UNITY_DISPLAY_STYLE_INT);

    RTC_estado('B');

    UnityAssertEqualNumber((UNITY_INT)((estado)), (UNITY_INT)((RTC_inactivo)), (

   ((void *)0)

   ), (UNITY_UINT)(72), UNITY_DISPLAY_STYLE_INT);

    RTC_estado('C');

    UnityAssertEqualNumber((UNITY_INT)((estado)), (UNITY_INT)((RTC_inactivo)), (

   ((void *)0)

   ), (UNITY_UINT)(74), UNITY_DISPLAY_STYLE_INT);

    RTC_estado('D');

    UnityAssertEqualNumber((UNITY_INT)((estado)), (UNITY_INT)((RTC_activo)), (

   ((void *)0)

   ), (UNITY_UINT)(76), UNITY_DISPLAY_STYLE_INT);







    RTC_estado('C');

    UnityAssertEqualNumber((UNITY_INT)((estado)), (UNITY_INT)((RTC_activo)), (

   ((void *)0)

   ), (UNITY_UINT)(81), UNITY_DISPLAY_STYLE_INT);

    RTC_estado('A');

    UnityAssertEqualNumber((UNITY_INT)((estado)), (UNITY_INT)((RTC_set_hora)), (

   ((void *)0)

   ), (UNITY_UINT)(83), UNITY_DISPLAY_STYLE_INT);

    RTC_estado('B');

    UnityAssertEqualNumber((UNITY_INT)((estado)), (UNITY_INT)((RTC_set_hora)), (

   ((void *)0)

   ), (UNITY_UINT)(85), UNITY_DISPLAY_STYLE_INT);

    RTC_estado('D');

    UnityAssertEqualNumber((UNITY_INT)((estado)), (UNITY_INT)((RTC_set_hora)), (

   ((void *)0)

   ), (UNITY_UINT)(87), UNITY_DISPLAY_STYLE_INT);

    RTC_estado('A');

    UnityAssertEqualNumber((UNITY_INT)((estado)), (UNITY_INT)((RTC_set_hora)), (

   ((void *)0)

   ), (UNITY_UINT)(89), UNITY_DISPLAY_STYLE_INT);

    RTC_estado('C');

    UnityAssertEqualNumber((UNITY_INT)((estado)), (UNITY_INT)((RTC_activo)), (

   ((void *)0)

   ), (UNITY_UINT)(91), UNITY_DISPLAY_STYLE_INT);

    RTC_estado('C');

    UnityAssertEqualNumber((UNITY_INT)((estado)), (UNITY_INT)((RTC_activo)), (

   ((void *)0)

   ), (UNITY_UINT)(93), UNITY_DISPLAY_STYLE_INT);

    RTC_estado('B');

    UnityAssertEqualNumber((UNITY_INT)((estado)), (UNITY_INT)((RTC_set_fecha)), (

   ((void *)0)

   ), (UNITY_UINT)(95), UNITY_DISPLAY_STYLE_INT);

    RTC_estado('A');

    UnityAssertEqualNumber((UNITY_INT)((estado)), (UNITY_INT)((RTC_set_fecha)), (

   ((void *)0)

   ), (UNITY_UINT)(97), UNITY_DISPLAY_STYLE_INT);

    RTC_estado('D');

    UnityAssertEqualNumber((UNITY_INT)((estado)), (UNITY_INT)((RTC_set_fecha)), (

   ((void *)0)

   ), (UNITY_UINT)(99), UNITY_DISPLAY_STYLE_INT);

    RTC_estado('B');

    UnityAssertEqualNumber((UNITY_INT)((estado)), (UNITY_INT)((RTC_set_fecha)), (

   ((void *)0)

   ), (UNITY_UINT)(101), UNITY_DISPLAY_STYLE_INT);

    RTC_estado('C');

    UnityAssertEqualNumber((UNITY_INT)((estado)), (UNITY_INT)((RTC_activo)), (

   ((void *)0)

   ), (UNITY_UINT)(103), UNITY_DISPLAY_STYLE_INT);





    RTC_estado('C');

    UnityAssertEqualNumber((UNITY_INT)((estado)), (UNITY_INT)((RTC_activo)), (

   ((void *)0)

   ), (UNITY_UINT)(107), UNITY_DISPLAY_STYLE_INT);

    RTC_estado('D');

    UnityAssertEqualNumber((UNITY_INT)((estado)), (UNITY_INT)((RTC_inactivo)), (

   ((void *)0)

   ), (UNITY_UINT)(109), UNITY_DISPLAY_STYLE_INT);

}





void test_set_hora(void){

    I2C_Write_CMockIgnore();

    I2C_Read_CMockIgnore();

    uartSendString_CMockIgnore();

    RTC_init();

    RTC_estado('D');

    RTC_estado('A');

    hora[0] = 59;

    hora[1] = 59;

    hora[2] = 23;

    RTC_estado('2');

    UnityAssertEqualNumber((UNITY_INT)((hora[2])), (UNITY_INT)((0)), (

   ((void *)0)

   ), (UNITY_UINT)(124), UNITY_DISPLAY_STYLE_INT);

    RTC_estado('8');

    UnityAssertEqualNumber((UNITY_INT)((hora[2])), (UNITY_INT)((23)), (

   ((void *)0)

   ), (UNITY_UINT)(126), UNITY_DISPLAY_STYLE_INT);

    RTC_estado('4');

    RTC_estado('8');

    UnityAssertEqualNumber((UNITY_INT)((hora[2])), (UNITY_INT)((22)), (

   ((void *)0)

   ), (UNITY_UINT)(129), UNITY_DISPLAY_STYLE_INT);

    RTC_estado('6');

    RTC_estado('2');

    UnityAssertEqualNumber((UNITY_INT)((hora[1])), (UNITY_INT)((0)), (

   ((void *)0)

   ), (UNITY_UINT)(132), UNITY_DISPLAY_STYLE_INT);

    RTC_estado('8');

    UnityAssertEqualNumber((UNITY_INT)((hora[1])), (UNITY_INT)((59)), (

   ((void *)0)

   ), (UNITY_UINT)(134), UNITY_DISPLAY_STYLE_INT);

    RTC_estado('6');

    RTC_estado('2');

    UnityAssertEqualNumber((UNITY_INT)((hora[0])), (UNITY_INT)((0)), (

   ((void *)0)

   ), (UNITY_UINT)(137), UNITY_DISPLAY_STYLE_INT);

    RTC_estado('8');

    UnityAssertEqualNumber((UNITY_INT)((hora[0])), (UNITY_INT)((59)), (

   ((void *)0)

   ), (UNITY_UINT)(139), UNITY_DISPLAY_STYLE_INT);

    RTC_estado('6');

    RTC_estado('8');

    UnityAssertEqualNumber((UNITY_INT)((hora[0])), (UNITY_INT)((58)), (

   ((void *)0)

   ), (UNITY_UINT)(142), UNITY_DISPLAY_STYLE_INT);

}







void test_set_fecha(void){

    I2C_Write_CMockIgnore();

    I2C_Read_CMockIgnore();

    uartSendString_CMockIgnore();

    RTC_init();

    RTC_estado('D');

    RTC_estado('B');

    fecha[0] = 30;

    fecha[1] = 12;

    fecha[2] = 99;

    RTC_estado('6');

    RTC_estado('2');

    UnityAssertEqualNumber((UNITY_INT)((fecha[1])), (UNITY_INT)((1)), (

   ((void *)0)

   ), (UNITY_UINT)(159), UNITY_DISPLAY_STYLE_INT);

    RTC_estado('8');

    UnityAssertEqualNumber((UNITY_INT)((fecha[1])), (UNITY_INT)((12)), (

   ((void *)0)

   ), (UNITY_UINT)(161), UNITY_DISPLAY_STYLE_INT);

    RTC_estado('6');

    RTC_estado('2');

    UnityAssertEqualNumber((UNITY_INT)((fecha[2])), (UNITY_INT)((0)), (

   ((void *)0)

   ), (UNITY_UINT)(164), UNITY_DISPLAY_STYLE_INT);

    RTC_estado('8');

    UnityAssertEqualNumber((UNITY_INT)((fecha[2])), (UNITY_INT)((99)), (

   ((void *)0)

   ), (UNITY_UINT)(166), UNITY_DISPLAY_STYLE_INT);

}





void test_set_fecha_mes_30_(void){

    I2C_Write_CMockIgnore();

    I2C_Read_CMockIgnore();

    uartSendString_CMockIgnore();

    RTC_init();

    RTC_estado('D');

    RTC_estado('B');

    fecha[0] = 31;

    fecha[1] = 1;

    fecha[2] = 99;

    RTC_estado('2');

    UnityAssertEqualNumber((UNITY_INT)((fecha[0])), (UNITY_INT)((1)), (

   ((void *)0)

   ), (UNITY_UINT)(181), UNITY_DISPLAY_STYLE_INT);

    RTC_estado('8');

    UnityAssertEqualNumber((UNITY_INT)((fecha[0])), (UNITY_INT)((31)), (

   ((void *)0)

   ), (UNITY_UINT)(183), UNITY_DISPLAY_STYLE_INT);

    fecha[1] = 4;

    fecha[0] = 30;

    RTC_estado('2');

    UnityAssertEqualNumber((UNITY_INT)((fecha[0])), (UNITY_INT)((1)), (

   ((void *)0)

   ), (UNITY_UINT)(187), UNITY_DISPLAY_STYLE_INT);

}





void test_dias_mes_febrero_no_bisiesto(void){

    I2C_Write_CMockIgnore();

    I2C_Read_CMockIgnore();

    uartSendString_CMockIgnore();

    RTC_init();

    RTC_estado('D');

    RTC_estado('B');

    fecha[0] = 28;

    fecha[1] = 2;

    fecha[2] = 3;

    RTC_estado('2');

    UnityAssertEqualNumber((UNITY_INT)((fecha[0])), (UNITY_INT)((1)), (

   ((void *)0)

   ), (UNITY_UINT)(202), UNITY_DISPLAY_STYLE_INT);

}





void test_dias_mes_febrero_bisiesto(void){

    I2C_Write_CMockIgnore();

    I2C_Read_CMockIgnore();

    uartSendString_CMockIgnore();

    RTC_init();

    RTC_estado('D');

    RTC_estado('B');

    fecha[0] = 28;

    fecha[1] = 2;

    fecha[2] = 4;

    RTC_estado('2');

    UnityAssertEqualNumber((UNITY_INT)((fecha[0])), (UNITY_INT)((29)), (

   ((void *)0)

   ), (UNITY_UINT)(217), UNITY_DISPLAY_STYLE_INT);

    RTC_estado('2');

    UnityAssertEqualNumber((UNITY_INT)((fecha[0])), (UNITY_INT)((1)), (

   ((void *)0)

   ), (UNITY_UINT)(219), UNITY_DISPLAY_STYLE_INT);

}
