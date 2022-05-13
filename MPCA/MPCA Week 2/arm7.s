.TEXT ;Adding 1st 5 Natural numbers
LDR R2,=SUM

MOV R1,#1

L1:ADD R0,R0,R1 ;R0 is not initialized. So it will have 0
ADD R1,R1,#1
CMP R1,#6
BNE L1
STR R0,[R2]
SWI 0X011

.DATA
SUM:.WORD 0