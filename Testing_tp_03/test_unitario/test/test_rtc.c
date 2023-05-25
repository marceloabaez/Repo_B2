/*La API maneja un RTC externo mediante comandos recibidos desde un teclado
4x4. La comunicación por i2c con el RTC se maneja mediante un wrapper de las
funciones de la HAL utilizadas para el envío y recepción de datos.
Los parámetros para el manejo del RTC se reciben desde la función main en 
formato char, los cuales contienen la tecla que fue pulsada en el teclado y
NULL en caso de no haberse presionado ninguna tecla. Los caracteres que se 
utilizan son:
'A' para entrar en el estado RTC_set_hora desde el esatdo RTC_activo.
'B' para entrar en el estado RTC_set_fecha desde el esatdo RTC_activo.
'C' para volver de alguno de los modos de seteo al esatdo RTC_activo.
'D' alternar entre el estado RTC_inactivo y RTC_activo.
'2' y '8' para incrementar o decrementar el parámetro que se esté seteando.
'4' y '6' para alternar entre los parámetros que se esté seteando.
*/

// La función set-hora recibe la hora como un char string "hh:mm:ss" y la
// envía mediante la función externa I2C_Wrire al registro correspondiente del RTC
// formateada al RTC

// 
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "unity.h"
#include "API_RTC.h"
#include "mock_API_RTC_port.h"
#include "mock_API_uart.h"

extern int estado;
extern char i2c_msg[];
extern uint8_t buff[];
extern char fecha_i[]; //Fecha inicial utilizada porque la bateria esta agotada
extern char hora_i[]; //Hora inicial utilizada porque la bateria está agotada
uint8_t hora_inicial_bcd[] = {21,69,32}; // Hora inicial en formato BSD
uint8_t fecha_inicial_bcd[] = {21,4,35}; // Fecha inicial en formato BSD
extern uint8_t hora[3]; // [ss, mm, hh]
extern uint8_t fecha[3]; //

// El programa almacena traduce y almacena correctamente a formato bsd
void test_inicializar_RTC(void){
    int a = -1;
    I2C_Write_Ignore();
    RTC_init();
    a = memcmp(buff,hora_inicial_bcd,3);   
    TEST_ASSERT_EQUAL(0, a);
}

// El programa almacena lee correctamente desde formato bsd
void test_leer_desde_RTC(void){
    int a = -1;
    I2C_Write_Ignore();
    I2C_Read_Ignore();
    RTC_send_fecha(fecha_i);
    RTC_leer_fecha();
    a = memcmp(i2c_msg,fecha_i,8);   
    TEST_ASSERT_EQUAL(0, a);
}

// Se prueban la MEF que maneja el RTC, verificando que los comandos válidos
//  producen el cambio de estado y los incorrectos no conllevan ningún cambio. 
void test_transiciones_entre_estado_MEF(void){
    I2C_Write_Ignore();
    I2C_Read_Ignore();
    uartSendString_Ignore();
    RTC_init();
    //Al ejecutar RTC_init() el estado se debe fijar en inactivo
    TEST_ASSERT_EQUAL(estado, RTC_inactivo);
    //Solamente el comando 'D' debe cambiar el estado a activo
    RTC_estado('A');
    TEST_ASSERT_EQUAL(estado, RTC_inactivo);
    RTC_estado('B');
    TEST_ASSERT_EQUAL(estado, RTC_inactivo);
    RTC_estado('C');
    TEST_ASSERT_EQUAL(estado, RTC_inactivo);
    RTC_estado('D');
    TEST_ASSERT_EQUAL(estado, RTC_activo);
    // Del estado RTC_activo se pasa al estado RTC_set_hora y RTC_set_fecha
    // con los comandos 'A' y 'B', volviendo de ambos con 'C'. Deben ignorarse
    // los comandos incorrectos
    RTC_estado('C');
    TEST_ASSERT_EQUAL(estado, RTC_activo);
    RTC_estado('A'); // se cambia al estado RTC_set_hora
    TEST_ASSERT_EQUAL(estado, RTC_set_hora);
    RTC_estado('B');
    TEST_ASSERT_EQUAL(estado, RTC_set_hora);
    RTC_estado('D');
    TEST_ASSERT_EQUAL(estado, RTC_set_hora);
    RTC_estado('A');
    TEST_ASSERT_EQUAL(estado, RTC_set_hora);
    RTC_estado('C');
    TEST_ASSERT_EQUAL(estado, RTC_activo);
    RTC_estado('C');
    TEST_ASSERT_EQUAL(estado, RTC_activo);
    RTC_estado('B'); // se cambia al estado RTC_set_fecha
    TEST_ASSERT_EQUAL(estado, RTC_set_fecha);
    RTC_estado('A');
    TEST_ASSERT_EQUAL(estado, RTC_set_fecha);
    RTC_estado('D');
    TEST_ASSERT_EQUAL(estado, RTC_set_fecha);
    RTC_estado('B');
    TEST_ASSERT_EQUAL(estado, RTC_set_fecha);
    RTC_estado('C');
    TEST_ASSERT_EQUAL(estado, RTC_activo);
    // En estado inactivo debe ingnorarse el comando 'C' y se pasa a estado
    // inactivo mediante el comando 'D'
    RTC_estado('C');
    TEST_ASSERT_EQUAL(estado, RTC_activo);
    RTC_estado('D');
    TEST_ASSERT_EQUAL(estado, RTC_inactivo);
}

// Pruebas de seteo de hora, las variavles deben desbordar correctamente
void test_set_hora(void){
    I2C_Write_Ignore();
    I2C_Read_Ignore();
    uartSendString_Ignore();
    RTC_init();
    RTC_estado('D');
    RTC_estado('A'); // RTC_set_hora
    hora[0] = 59;
    hora[1] = 59;
    hora[2] = 23;
    RTC_estado('2'); // Incrementando la hora debe desbordar a 0
    TEST_ASSERT_EQUAL(hora[2], 0);
    RTC_estado('8'); // Decrementando la hora debe desbordar a 23
    TEST_ASSERT_EQUAL(hora[2], 23);
    RTC_estado('4'); // No hay parametro anterior, se debería mantener en hora
    RTC_estado('8');
    TEST_ASSERT_EQUAL(hora[2], 22);
    RTC_estado('6'); // Configurar minutos
    RTC_estado('2'); // Debe desbordar a 0
    TEST_ASSERT_EQUAL(hora[1], 0);
    RTC_estado('8'); // Debe desbordar a 59
    TEST_ASSERT_EQUAL(hora[1], 59);
    RTC_estado('6'); // Configurar segundos
    RTC_estado('2'); // Debe desbordar a 0
    TEST_ASSERT_EQUAL(hora[0], 0);
    RTC_estado('8'); // Debe desbordar a 59
    TEST_ASSERT_EQUAL(hora[0], 59);
    RTC_estado('6'); // No hay parametro posterior, se debería mantener en segundos
    RTC_estado('8');
    TEST_ASSERT_EQUAL(hora[0], 58);
}


// Pruebas de seteo de fecha: años y meses
void test_set_fecha(void){
    I2C_Write_Ignore();
    I2C_Read_Ignore();
    uartSendString_Ignore();
    RTC_init();
    RTC_estado('D');
    RTC_estado('B'); // RTC_set_fecha
    fecha[0] = 30;
    fecha[1] = 12;
    fecha[2] = 99;
    RTC_estado('6'); // Setear meses
    RTC_estado('2'); // Incrementar, debe desbordar a 1
    TEST_ASSERT_EQUAL(fecha[1], 1);
    RTC_estado('8'); // Decrementar, debe desbordar a 12
    TEST_ASSERT_EQUAL(fecha[1], 12);
    RTC_estado('6'); // Setear años
    RTC_estado('2'); // Incrementar, debe desbordar a 0
    TEST_ASSERT_EQUAL(fecha[2], 0);
    RTC_estado('8'); // Decrementar, debe desbordar a 99
    TEST_ASSERT_EQUAL(fecha[2], 99);
}

// Pruebas de seteo de dias, meses de 31 y 30 dias
void test_set_fecha_mes_30_(void){
    I2C_Write_Ignore();
    I2C_Read_Ignore();
    uartSendString_Ignore();
    RTC_init();
    RTC_estado('D');
    RTC_estado('B'); // RTC_set_fecha
    fecha[0] = 31;
    fecha[1] = 1; // Mes de 31 dias
    fecha[2] = 99;
    RTC_estado('2'); // Incrementar, debe desbordar a 1
    TEST_ASSERT_EQUAL(fecha[0], 1);
    RTC_estado('8'); // Decrementar, debe desbordar a 31
    TEST_ASSERT_EQUAL(fecha[0], 31);
    fecha[1] = 4; // Mes de 30 días
    fecha[0] = 30; // Ultimo dia del mes
    RTC_estado('2'); // Incrementar, debe desbordar a 1
    TEST_ASSERT_EQUAL(fecha[0], 1);
}

// Prueba dias febrero
void test_dias_mes_febrero_no_bisiesto(void){
    I2C_Write_Ignore();
    I2C_Read_Ignore();
    uartSendString_Ignore();
    RTC_init();
    RTC_estado('D');
    RTC_estado('B'); // RTC_set_fecha
    fecha[0] = 28;
    fecha[1] = 2;
    fecha[2] = 3; // Año no bisiesto
    RTC_estado('2'); // Incrementar, debe desbordar a 1
    TEST_ASSERT_EQUAL(fecha[0], 1);
}

// Prueba dias febrero
void test_dias_mes_febrero_bisiesto(void){
    I2C_Write_Ignore();
    I2C_Read_Ignore();
    uartSendString_Ignore();
    RTC_init();
    RTC_estado('D');
    RTC_estado('B'); // RTC_set_fecha
    fecha[0] = 28;
    fecha[1] = 2;
    fecha[2] = 4; // Año bisiesto
    RTC_estado('2'); // Incrementar, debe fijar dia en 29
    TEST_ASSERT_EQUAL(fecha[0], 29);
    RTC_estado('2'); // Incrementar, debe desbordar a 1
    TEST_ASSERT_EQUAL(fecha[0], 1);
}