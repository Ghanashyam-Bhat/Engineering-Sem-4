.DATA
	A:.WORD 10, 20, 30 ,40, 50, 60, 70, 80, 90
	B:.WORD 1, 2, 3, 4, 5, 6, 7, 8, 9
	C:.WORD 1, 1, 1, 1, 1, 1, 1, 1, 1
.TEXT
	LDR R1,=A
	LDR R2,=B
	LDR R7,=C
	
	LDR R8,[R1]
	LDR R9,[R2]
	LDR R3,[R7]
	
	MOV R5,#0
	
SECOND:
	MOV R6,#0	
FIRST:
	MUL R4,R8,R9
	ADD R3,R3,R4
	STR R3,[R7]
	
	
	ADD R6,R6,#1
	LDR R9,[R2,#4]!
	LDR R3,[R7,#4]!
	CMP R6,#3
	BNE FIRST
	
	ADD R5,R5,#1
	LDR R8,[R1,#4]!
	CMP R5,#3
	BNE SECOND
	SWI 0X011
