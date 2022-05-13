		.DATA
A: .ASCIZ "My name is Bond"
B: .BYTE 'n'

		.TEXT
	LDR R5,=A
	LDR R6,=B
	MOV R3,#15
	MOV R4,#0
	LDRB R2,[R6]

LOOP:
	LDRB R1,[R5]
	CMP R1,R2
	ADDEQ R4,R4,#1
	SUB R3,R3,#1
	CMP R3,#0
	ADD R5,R5,#1
	BNE LOOP

		.END
