section	.note.GNU-stack
section	.text
global	ft_strcpy

ft_strcpy:
	push	rdi

	loop:
	mov		rcx,[rsi]
	mov		[rdi],rcx
	inc		rsi
	inc		rdi
	cmp		byte[rsi],0
	jne		loop

	pop		rax
	ret
