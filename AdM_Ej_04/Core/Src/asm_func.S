/*
 * asm_func.S
 *
 *  Created on: 1 jun. 2023
 *      Author: marcelo
 */
.syntax unified
.thumb
.text

.global asm_prodEsc12

.thumb_func
asm_prodEsc12:
	PUSH {R0-R5}
	MOV R5, #4095
LOOP:
	LDRH R4, [R0], #2
	MUL R4, R4, R3
	CMP R4, R5
	BHI SATURATED
CONTINUE:
	STRH R4, [R1], #2
	SUB R2, #1
	CMP R2, #0
	BEQ EXIT
	B LOOP
EXIT:
	POP {R0-R5}
	BX LR

SATURATED:
    MOV R4, R5
    B CONTINUE

