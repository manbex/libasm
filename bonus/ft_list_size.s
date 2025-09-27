section	.note.GNU-stack
section	.text
global	ft_list_size

ft_list_size:
	xor		rax,rax

	loop:
	cmp		rdi,0
	je		end
	inc		rax
	mov		rdx,[rdi+8]
	mov		rdi,rdx
	jmp		loop

	end:
	ret
