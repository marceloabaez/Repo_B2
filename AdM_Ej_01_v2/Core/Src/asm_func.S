/*
 * asm_func.S
 *
 *  Created on: 31 may. 2023
 *      Author: marcelo
 */


.syntax unified
.thumb
.text

.global array_init

.thumb_func
array_init:
    MOV R2, #4
    MUL R1, R1, R2
    ADD R1, R0
    MOV R2, #0
LOOP:
    STR R2, [R0], #4
    CMP R0, R1
    BEQ EXIT
    B LOOP
EXIT:
    BX LR
