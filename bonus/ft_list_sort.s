section	.note.GNU-stack
section	.text
global	ft_list_sort

ft_list_sort:
	cmp		rdi,0
	je		return

	mov		rdx,[rdi]

	cmp		rdx,0
	je		return

	mov		r8,rsi
	push	rdx

	main_loop:
	cmp		qword[rdx+8],0
	je		return

	mov		rdi,[rdx]
	mov		rsi,[rdx+8]
	mov		rsi,[rsi]
	push	rdx
	call	r8
	pop		rdx
	test	eax,eax
	jns		swap
	mov		rdx,[rdx+8]
	jmp		main_loop

	swap:
	mov		rcx,[rdx]
	mov		rax,[rdx+8]
	mov		r9,[rax]
	mov		[rdx],r9
	mov		[rax],rcx
	pop		rdx
	push	rdx
	jmp		main_loop

	return:
	pop		rdx
	ret
