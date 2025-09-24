section	.note.GNU-stack
section	.text
global	ft_strlen

ft_strlen:
	xor		rax,rax

	loop:
	cmp		byte[rdi],0
	je		end

	inc		rax
	inc		rdi
	jmp		loop

	end:
	ret
