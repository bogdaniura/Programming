assume ds:date, cs:cod
date segment
	a db 101
	b db 200
	s dw ?
date ends

cod segment
start:
	mov ax, date
	mov ds, ax
	mov al, a
	mov ah, 0
	add al, b
	adc ah, 0
	mov s, ax
	mov ax, 4c00h
	int 21h
cod ends
end start
