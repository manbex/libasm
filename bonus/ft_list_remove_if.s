section	.note.GNU-stack
section	.text
global	ft_list_remove_if

ft_list_remove_if:
	push	rdi
	push	rsi
	push	rcx

	mov		rax,[rdi]
	mov		rdi,rax

	call	rdx

	pop		rcx
	pop		rsi
	pop		rdi

	ret
