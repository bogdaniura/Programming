ASSUME DS:date, CS:cod
date SEGMENT
	a DW 127
	b DB-12, 39, 260 SHR 1, 254
	c DD 1000, 'a'
	d DB 'xyzt'
	e DW $-b
	  DB 3 DUP (3 LE 7)
date ENDS

cod SEGMENT
	start:
		MOV AX, date
		MOV DS ,AX

		MOV AX, 4C00h
		INT 21h
cod ENDS
END start