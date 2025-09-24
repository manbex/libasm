section	.note.GNU-stack
section	.text
global	ft_strdup
extern	malloc
extern	ft_strlen
extern	ft_strcpy

ft_strdup:
	push	rdi
	call	ft_strlen
	pop		rdi

	mov		rsi,rdi
	mov		rdi,rax
	inc		rdi

	push	rsi
	call	malloc wrt ..plt
	pop		rsi

	cmp		rax,0
	je		end

	mov		rdi,rax
	call	ft_strcpy

	end:
	ret
