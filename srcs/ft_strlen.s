section	.note.GNU-stack
section	.text
global	ft_strlen

ft_strlen:
	mov		rcx,0

	loop:
	cmp		BYTE[rdi],0
	je		end

	inc		rcx
	inc		rdi
	jmp		loop

	end:
	mov		rax,rcx
	ret
