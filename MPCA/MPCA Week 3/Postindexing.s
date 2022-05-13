;Postindexing Mode  - Sum of number at odd position
		.DATA
	A:.WORD 10,20,30,40,50
	SUM_ALT:.WORD 0
	
	
		.TEXT
	MOV R1,#0 ; sum of alternate numbers
	MOV R4,#0 ; temporary register
	MOV R6,#0 ;	loop count
	
	LDR R2,=A
	LDR R3,=SUM_ALT

LOOP:
	LDR R4,[R2],#8
	ADD R1,R1,R4
	ADD R6,R6,#1
	CMP R6,#3
	BNE LOOP
	
STR R1,[R3]

		.END
