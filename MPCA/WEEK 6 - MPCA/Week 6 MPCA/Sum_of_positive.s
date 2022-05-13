;Adding Positive Numbers
		.DATA
A:.WORD -1,-2,1,2,-3,4,-1,-5,7,2
SUM:.WORD 0

		.TEXT
	LDR R0,=A
	LDR R1,=SUM
	MOV R2,#0 ; sum
	MOV R3,#0 ; count
	BL LOOP
	STR R2,[R1] ;final storing
	SWI 0X11
	
LOOP:
	LDR R4,[R0],#4 ; post indecing
	MOVS R4,R4 ; for updating flags
	BPL POSITIVE ; branch with plus(previous instruction should check if it is positive or not)
L1:
	ADD R3,R3,#1 ; if negetive
	CMP R3,#10
	BNE LOOP
	MOV PC,LR ; going back to main function where we brnached and linked 
POSITIVE:
	ADD R2,R2,R4
	B L1

