.syntax unified
.thumb
.text

.global asm_prodEsc16

.thumb_func
asm_prodEsc16:
	LDR R4, [R0], #4
	MUL R4, R4, R3
	STRH R4, [R1], #4
	SUB R2, #1
	CMP R2, #0
	BEQ EXIT
	B asm_prodEsc16
EXIT:
	BX LR

exit:
    BX lr
