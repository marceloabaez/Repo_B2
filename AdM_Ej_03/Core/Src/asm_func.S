.syntax unified
.thumb
.text

.global asm_prodEsc16

.thumb_func
asm_prodEsc16:
	PUSH {R4}
LOOP:
	LDRH R4, [R0], #2
	MUL R4, R4, R3
	STRH R4, [R1], #2
	SUB R2, #1
	CMP R2, #0
	BEQ EXIT
	B LOOP
EXIT:
	BX LR

exit:
	POP {R4}
    BX lr
