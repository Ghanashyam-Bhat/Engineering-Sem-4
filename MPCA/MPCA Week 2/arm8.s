.DATA 
A:.WORD 0X12345678
B:.WORD 65
C:.WORD 0

.TEXT
LDR R1,=A
LDR R2,=B
LDR R3,=C

LDR R4,[R1]
ADDS R5,R4, R4, LSL #6 ;Logical left shift by 6 (LSL)
;Shifting R4 6 times (Multiply by 64) and adding R4 once, later storing it in R5
STR R5,[R3]
SWI 0X011