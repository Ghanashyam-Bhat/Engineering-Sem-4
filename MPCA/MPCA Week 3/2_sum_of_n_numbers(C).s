;Post Indexing
		.DATA
	A:.WORD 10,20,30,40,50
	SUM:.WORD 0
	
	
		.TEXT
	MOV R2,#0
	LDR R1,=A
	LDR R3,=SUM
	MOV R4,#0
	MOV R5,#0

LOOP:
	LDR R4,[R1],#4 ;Post Indexing

	ADD R2,R2,R4
	ADD R6,R6,#1
	CMP R6,#5
	BNE LOOP
STR R2,[R3]

		.END
