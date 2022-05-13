.DATA ;Data section
A:.WORD 10,20,30,40,50  ;Input of type Word
B:.WORD 0,0,0,0,0

.TEXT   ;Text section
LDR R1,=A  ;Starting address of A is getting stored in R0 regester
LDR R2,=B

MOV R5,#1  ;Storing 1 in R5 for counter

L1:
LDR R3,[R1]  ; Getting the value stored in the location stored by R0, i.e element 1 of A
STR R3,[R2]  ; Store R3 content to memory with location R2

ADD R1,R1,#4 ; Adding 4 to R1 and storing it back in R1 to point to next location in the memory
ADD R2,R2,#4
ADD R5,R5,#1 ;Increment the counter

CMP R5,#6 ;Comparing the counter value with 6(Number of elements+1)
BNE L1 ;Branching if comparision is not equal

SWI 0X011 ;Software interrupt for termination of program