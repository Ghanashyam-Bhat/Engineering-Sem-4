.DATA
	EVEN:.ASCIZ "Even parity"
	ODD:.ASCIZ "Odd Parity"
	A:.WORD 0X123

.TEXT
	LDR R0,=A
	LDR R1,[R0]
	MOV R2,#0
	TST R1,#1 ; sets flag
	BNE L1
	
	MOV R1,R1,LSR #1
	

L1:
	ADD R2,R2,#1