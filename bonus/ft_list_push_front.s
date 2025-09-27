section	.note.GNU-stack
section	.text
global	ft_list_push_front
extern	malloc

ft_list_push_front:
	push	rdi
	push	rsi

	mov		rdi,16
	call	malloc wrt ..plt

	pop		rsi
	pop		rdi

	cmp		rax,0
	je		end

	mov		[rax],rsi
	add		rax,8
	mov		rdx,[rdi]
	mov		[rax],rdx
	sub		rax,8
	mov		[rdi],rax

	end:
	ret
