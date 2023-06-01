/*
 * asm_func.S
 *
 *  Created on: 1 jun. 2023
 *      Author: marcelo
 */

.syntax unified
.thumb
.text

.global asm_prodEsc32

.thumb_func
asm_prodEsc32:
	LDR R4, [R0], #4
	MUL R4, R4, R3
	STR R4, [R1], #4
	SUB R2, #1
	CMP R2, #0
	BEQ EXIT
	B asm_prodEsc32
EXIT:
	BX LR

exit:
    BX lr
