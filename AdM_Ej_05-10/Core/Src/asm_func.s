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

.thumb_func
asm_filtroVentana10:


.thumb_func
asm_pack32to16:
LOOP_2:
	LDR R3,[R0], #4
	LSR R3, #16
	STRH R3, [R1], #2
	SUB R2, #1
	CMP R2, #0
	BNE LOOP_2
	BX lr



.thumb_func
asm_max:
	PUSH {R4-R5}
	LDR R2, [R0], #4
	MOV R3, #0
	MOV R5, #0
LOOP_3:
	SUB R1, #1
	CMP R1, #0
	BEQ EXIT
	LDR R4, [R0], #4
	ADD R5, #1
	CMP R2, R4
	BGE LOOP_3
	MOV R2, R4
	MOV R3, R5
	B LOOP_3
EXIT:
	MOV R0, R3
	POP {R4-R5}
	BX lr
