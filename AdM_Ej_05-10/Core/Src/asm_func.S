/*
 * asm_func.s
 *
 *  Created on: 9 jun. 2023
 *      Author: marcelo
 */
.syntax unified
.thumb
.text

.global asm_filtroVentana10
.global asm_pack32to16
.global asm_max
.global asm_downsampleM
.global asm_invertir
.global asm_eco
.global asm_eco_SIMD
.global asm_eco_SIMD_10
.global asm_corr
.global asm_corr_SIMD

/*
Filtro ventana, cuando los límites de la ventana sobrepasan los del array se repiten los valores
de borde tantas veces como espacios de ventana hayan quedado fuera
R0 : dirección del array de entrada
R1 : dirección del array de salida
R2 : longitud del array, luego utilizado para almacenar el indice mayor del mismo
R3 : índice del número central de la ventana
R4 : índice de los  números barridos en la ventana
R5 : registro auxiliar para cargar los valores desde el array de entrada
R6 : registro auxiliar para almacenar la suma/promedio de los valores de la ventana
R7 : contador del número de elemento dentro de la ventana
R8 : valor superior del array de entrada
R9 : valor inferior del array de entrada
R10 : cantidad de elementos en la ventana
*/
.thumb_func
asm_filtroVentana10:
// cargar valores limite
	PUSH {R3-R10}
	MOV R3, #-1
	SUB R2, #1
	LDRH R9, [R0]
	LDRH R8, [R0, R2, LSL #1]
	MOV R10, #11
// incrementar contador de centro de ventana, comprobar condicion de salida, inicializar cuenta de ventana
FILTRO_VENTANA_LOOP_1:
	ADD R3, #1
	CMP R3, R2
	BHI FILTRO_VENTANA_EXIT
	MOV R6, #0
	SUB R4, R3, #6
	MOV R7, #-1
//Incrementar contadores de ventana, comprobar fin de ventana y guardar
FILTRO_VENTANA_LOOP_2:
	ADD R4, #1
	ADD R7, #1
	CMP r7, #10
	ITTT GT
	UDIVGT R6, R6, R10
	STRHGT R6, [R1, R3, LSL #1]
	BGT FILTRO_VENTANA_LOOP_1
// limite inferior de ventana menior a 0
    CMP R4, #0
    ITT LT
    ADDLT R6, R9
    BLT FILTRO_VENTANA_LOOP_2
//limite superior de ventana mayor a longitud de array
    CMP R4, R2
    ITT GT
    ADDGT R6, R8
    BGT FILTRO_VENTANA_LOOP_2
// valores dentro de rango
    LDRH R5, [R0, R4, LSL #1]
    ADD R6, R5
    B FILTRO_VENTANA_LOOP_2
FILTRO_VENTANA_EXIT:
	POP {R3-R10}
	BX lr


.thumb_func
asm_pack32to16:
PACK32_TO_16_LOOP_2:
	LDR R3,[R0], #4
	ASR R3, #16
	STRH R3, [R1], #2
	SUB R2, #1
	CMP R2, #0
	BNE PACK32_TO_16_LOOP_2
	BX lr



.thumb_func
asm_max:
	PUSH {R4-R5}
	LDR R2, [R0], #4
	MOV R3, #0
	MOV R5, #0
ASM_MAX_LOOP_3:
	SUB R1, #1
	CMP R1, #0
	BEQ ASM_MAX_EXIT
	LDR R4, [R0], #4
	ADD R5, #1
	CMP R2, R4
	BGE ASM_MAX_LOOP_3
	MOV R2, R4
	MOV R3, R5
	B ASM_MAX_LOOP_3
ASM_MAX_EXIT:
	MOV R0, R3
	POP {R4-R5}
	BX lr

/*
Función para aliminar una cada N muestras en un array  de entrada y guardar las restantes
en un array de salida
R0 : dirección del array de entrada, luego utilizado para almacenar sus sucesivas direcciones
R1 : dirección del array de salida,  luego utilizado para almacenar sus sucesivas direcciones
R2 : longitud del array
R3 : N, cantidad de elementos consecutivos de los cuales se elimina el último
R4 : indice del array de entrada
R5 : indice del array de salida
R6 : indice del proximo valor a ser ignorado
R7 : registro auxiliar para cargar los valores a copiar
*/
.thumb_func
asm_downsampleM:
    PUSH {R4-R7}
    MOV R6, R3
    SUB R6, #1
    MOV R4, #0
    MOV r5, #0

asm_downsampleM_loop:
    CMP R4, R2
    BEQ asm_downsampleM_exit

    CMP R6, R4
    ITTT EQ
    ADDEQ R6, R3
    ADDEQ R4, #1
    BEQ asm_downsampleM_loop

    LDR R7, [R0, R4, LSL #2]
    STR R7, [R1, R5, LSL #2]
    ADD R4, #1
    ADD R5, #1
    B asm_downsampleM_loop

asm_downsampleM_exit:
    POP {R4-R7}
    BX lr



/*
Función para invertir el órden de los elementos en un array
R0 : dirección del array de entrada
R1 : longitud del array
R2 : indice inferior para el intercambio
R3 : indice superior para el intercambio
R4 : valor auxiliar para el intercambio
R5 : segundo valor auliliar para el intercambio
R6 : indice limtite a recorrer
*/
.thumb_func
asm_invertir:
	PUSH {R4-R6}
	MOV R2, #0
	SUB R3, R1, #1
	LSR R6, R1, #1

asm_invertir_loop:
    CMP R6, R2
    BLS asm_invertir_exit

    LDRH R4, [R0, R2, LSL #1]
    LDRH R5, [R0, R3, LSL #1]
    STRH R4, [R0, R3, LSL #1]
    STRH R5, [R0, R2, LSL #1]
    ADD R2, #1
    SUB R3, #1
    B asm_invertir_loop

asm_invertir_exit:
	POP {R4-R6}
	BX lr




/*
Función para instroducir un eco en un array de 4096 muestras de audio de 16 bits
las mismas se tomaron con una tasa de muestreo de 44100 muestras/s. La función
introduce un eco de la señal original con la mitad de la amplitud y 20ms de demora
R0 : dirección del array de entrada
R1 : longitud del array
R2 : indice superior de recorrido del array
R3 : indice inferior de recorrido del array
R4 : almacena valor alto
R5 : almacena valor bajo (eco)
*/
.thumb_func
asm_eco:
    PUSH {R2-R5}
    SUB R3, R1, #1
    LSL R3, #1
    ADD R2, R3, R0
    MOV R4, #882
    LSL R4, #1
    SUB R3, R2, R4

asm_eco_loop:
    LDRSH R5, [R3], #-2
    ASR R5, #1
    LDRSH R4, [R2]
    ADD R4, R5
    STRH R4, [R2], #-2
    CMP R0, R3
    BLS asm_eco_loop
    POP {R2-R5}
    BX lr




/*
Función para instroducir un eco en un array de 4096 muestras de audio de 16 bits
las mismas se tomaron con una tasa de muestreo de 44100 muestras/s. La función
introduce un eco de la señal original con la mitad de la amplitud y 20ms de demora
Se utilizan instrucciones SIMD para acelerar el procesamiento
R0 : dirección del array de entrada
R1 : longitud del array
R2 : indice superior de recorrido del array
R3 : indice inferior de recorrido del array
R4 : almacena valor alto
R5 : almacena valor bajo (eco)
R6 : almacena cero para poder dividir por dos los registros bajos con SHADD16
*/
.thumb_func
asm_eco_SIMD:
    PUSH {R2-R6}
    SUB R3, R1, #2
    LSL R3, #1
    ADD R2, R3, R0
    MOV R4, #882
    LSL R4, #1
    SUB R3, R2, R4
    MOV R6, #0

asm_eco_SIMD_loop:
    LDR R5, [R3], #-4
    SHADD16 R5, R5, R6
    LDR R4, [R2]
    SADD16 R4, R4, R5
    STR R4, [R2], #-4
    CMP R0, R3
    BLS asm_eco_SIMD_loop
    POP {R2-R6}
    BX lr



/* SIMD 10 - Sacrifica memoria de programa a cambio de velocidad
Función para instroducir un eco en un array de 4096 muestras de audio de 16 bits
las mismas se tomaron con una tasa de muestreo de 44100 muestras/s. La función
introduce un eco de la señal original con la mitad de la amplitud y 20ms de demora
Se utilizan instrucciones SIMD para acelerar el procesamiento
R0 : dirección del array de entrada
R1 : longitud del array
R2 : indice superior de recorrido del array
R3 : indice inferior de recorrido del array
R4 : almacena valor alto
R5 : almacena valor bajo (eco)
R6 : almacena cero para poder dividir por dos los registros bajos con SHADD16
*/
.thumb_func
asm_eco_SIMD_10:
    PUSH {R2-R7}
    SUB R3, R1, #2
    LSL R3, #1
    ADD R2, R3, R0
    MOV R4, #882
    LSL R4, #1
    SUB R3, R2, R4
    MOV R6, #0
    MOV R7, #44
    ADD R7, R0

asm_eco_SIMD_10_loop:
    LDR R5, [R3], #-4
    SHADD16 R5, R5, R6
    LDR R4, [R2]
    SADD16 R4, R4, R5
    STR R4, [R2], #-4

    LDR R5, [R3], #-4
    SHADD16 R5, R5, R6
    LDR R4, [R2]
    SADD16 R4, R4, R5
    STR R4, [R2], #-4

    LDR R5, [R3], #-4
    SHADD16 R5, R5, R6
    LDR R4, [R2]
    SADD16 R4, R4, R5
    STR R4, [R2], #-4

    LDR R5, [R3], #-4
    SHADD16 R5, R5, R6
    LDR R4, [R2]
    SADD16 R4, R4, R5
    STR R4, [R2], #-4

    LDR R5, [R3], #-4
    SHADD16 R5, R5, R6
    LDR R4, [R2]
    SADD16 R4, R4, R5
    STR R4, [R2], #-4

    LDR R5, [R3], #-4
    SHADD16 R5, R5, R6
    LDR R4, [R2]
    SADD16 R4, R4, R5
    STR R4, [R2], #-4

    LDR R5, [R3], #-4
    SHADD16 R5, R5, R6
    LDR R4, [R2]
    SADD16 R4, R4, R5
    STR R4, [R2], #-4

    LDR R5, [R3], #-4
    SHADD16 R5, R5, R6
    LDR R4, [R2]
    SADD16 R4, R4, R5
    STR R4, [R2], #-4

    LDR R5, [R3], #-4
    SHADD16 R5, R5, R6
    LDR R4, [R2]
    SADD16 R4, R4, R5
    STR R4, [R2], #-4

    LDR R5, [R3], #-4
    SHADD16 R5, R5, R6
    LDR R4, [R2]
    SADD16 R4, R4, R5
    STR R4, [R2], #-4

    CMP R7, R3
    BLS asm_eco_SIMD_10_loop

asm_eco_SIMD_10_loop2:
    LDR R5, [R3], #-4
    SHADD16 R5, R5, R6
    LDR R4, [R2]
    SADD16 R4, R4, R5
    STR R4, [R2], #-4
    CMP R0, R3
    BLS asm_eco_SIMD_10_loop2

    POP {R2-R7}
    BX lr




/*
Función para calcular la correlación cruzada entre los datos de dos arrays de longitud N,
con un desplazamiento de entre 0 y N-1, guardando los resultados en otro array de salida
de longitud N
R0 : dirección del arrayX
R1 : dirección del arrayY
R2 : dirección del array de resultado
R3 : longitud de los array
R4 : almacenamiento del valor X
R5 : almacenamiento del valor Y
R6 : acumulado
R7 : contador n
R8 : contador n-l
R9 : l (contador del vector correlación)
*/
.thumb_func
asm_corr:
    PUSH {R4-R9}
    MOV R9, #0

asm_corr_loop1:
    MOV R6, #0
    MOV R7, #0
    SUB R8, R7, R9
    CMP R9, R3
    BGE asm_corr_exit

asm_corr_loop2:
    CMP R8, #0
    BLT asm_corr_continuar
    CMP R8, R3
    BGE asm_corr_continuar
    LDR R4, [R0, R7, LSL #1]
    LDR R5, [R1, R8, LSL #1]
    SMLABB R6, R4, R5, R6

asm_corr_continuar:
    ADD R7, #1
    ADD R8, #1
    CMP R7, R3
    BLT asm_corr_loop2
    STRH R6, [R2, R9, LSL #1]
    ADD R9, #1
    B asm_corr_loop1

asm_corr_exit:
    POP {R4-R9}
    BX lr




/*
Función para calcular la correlación cruzada entre los datos de dos arrays de longitud N,
con un desplazamiento de entre 0 y N-1, guardando los resultados en otro array de salida
de longitud N
R0 : dirección del arrayX
R1 : dirección del arrayY
R2 : dirección del array de resultado
R3 : longitud de los array
R4 : almacenamiento del valor X
R5 : almacenamiento del valor Y
R6 : acumulado
R7 : contador n
R8 : contador n-l
R9 : l (contador del vector correlación)
*/
.thumb_func
asm_corr_SIMD:
    PUSH {R4-R11}
    MOV R9, #0
    MOV R10, #0xFFFF0000
    SUB R11, R3, #1

asm_corr_SIMD_loop1:
    MOV R6, #0
    MOV R7, #0
    SUB R8, R7, R9
    CMP R9, R3
    BGE asm_corr_SIMD_exit

asm_corr_SIMD_loop2:
    CMP R8, #-1
    BLT asm_corr_SIMD_continuar

    LDRH R4, [R0, R7, LSL #1]
    LDRH R5, [R1, R8, LSL #1]

    CMP R8, #-1
    IT EQ
    ANDEQ R5, R5, R10
    CMP R7, R11
    ITT EQ
    ANDEQ R4, R10, LSR #16
    ANDEQ R5, R10, LSR #16

    SMLADD R6, R4, R5, R6

asm_corr_SIMD_continuar:
    ADD R7, #2
    ADD R8, #2
    CMP R7, R3
    BLT asm_corr_SIMD_loop2
    STRH R6, [R2, R9, LSL #1]
    ADD R9, #1
    B asm_corr_SIMD_loop1

asm_corr_SIMD_exit:
    POP {R4-R9}
    BX lr
