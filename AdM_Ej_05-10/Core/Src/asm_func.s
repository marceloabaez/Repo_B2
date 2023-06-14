# 0 "../Core/Src/asm_func.S"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "../Core/Src/asm_func.S"






.syntax unified
.thumb
.text

.global asm_filtroVentana10
.global asm_pack32to16
.global asm_max
# 30 "../Core/Src/asm_func.S"
.thumb_func
asm_filtroVentana10:
 PUSH {R3-R10}
 MOV R3, #-1
 SUB R2, #-1
 LDR R9, [R0]
 LDR R8, [R0, R2, LSL #1]
 LDR R10, #11
FILTRO_VENTANA_LOOP_1:
 ADD R3, #1
 CMP R3, R2
 BHI FILTRO_VENTANA_EXIT
 MOV R6, #0
 SUB R4, R3, #6
 MOV R7, #-1
FILTRO_VENTANA_LOOP_2:
 ADD R4, #1
 ADD R7, #1
 CMP r7, #10
 ITTTT GT
 UDIVGT R6, R6, R10
 STRGT R6, [R1, R3, LSL #1]
 ADDGT R3, #1
 BGT FILTRO_VENTANA_LOOP_1

    CMP R4, #0
    ITT LT
    ADDLT R6, R9
    BLT FILTRO_VENTANA_LOOP_2

    CMP R4, R2
    ITT GT
    ADDGT R6, R8
    BGT FILTRO_VENTANA_LOOP_2

    LDR R5, [R0, R4, LSL #1]
    ADD R6, R5
    B FILTRO_VENTANA_LOOP_2

FILTRO_VENTANA_EXIT:
 POP {R3-R10}
 B LR


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
 BGE LOOP_3
 MOV R2, R4
 MOV R3, R5
 B ASM_MAX_LOOP_3
ASM_MAX_EXIT:
 MOV R0, R3
 POP {R4-R5}
 BX lr
