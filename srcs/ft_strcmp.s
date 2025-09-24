section	.note.GNU-stack
section	.text
global	ft_strcmp

ft_strcmp:
	xor		rcx,rcx

	loop:
	movzx	rax,byte[rdi+rcx]
	movzx	rdx,byte[rsi+rcx]
	sub		rax,rdx
	jnz		end
	
	cmp		byte[rdi+rcx],0
	je		end

	inc		rcx
	jmp		loop

	end:
	ret
