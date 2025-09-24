section	.note.GNU-stack
section	.text
global	ft_strcmp

ft_strcmp:
	mov		rcx,0

	loop:
	movzx	rax,byte[rdi+rcx]
	movzx	rdx,byte[rsi+rcx]
	sub		rax,rdx
	jnz		end
	
	cmp		byte[rdi+rcx],0
	je		end
	cmp		byte[rsi+rcx],0
	je		end

	inc		rcx
	jmp		loop

	end:
	ret
