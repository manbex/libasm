section	.note.GNU-stack
section	.text
global	ft_strcpy

ft_strcpy:
	xor		rcx,rcx

	loop:
	movzx	rdx,byte[rsi+rcx]
	mov		[rdi+rcx],dl

	cmp		byte[rsi+rcx],0
	je		end

	inc		rcx
	jmp		loop

	end:
	mov		rax,rdi
	ret
