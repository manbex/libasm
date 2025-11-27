section	.note.GNU-stack
section	.text
global	ft_list_remove_if
extern	free

ft_list_remove_if:
	test	rdi,rdi
	jz		return

	mov		r8,rdi
	mov		rdi,[rdi]

	loop:
	test	rdi,rdi
	jz		return

	push	rdi
	push	rsi
	push	rdx
	push	rcx
	push	r8

	mov		rdi,[rdi]
	xor		rax,rax
	call	rdx

	pop		r8
	pop		rcx
	pop		rdx
	pop		rsi
	pop		rdi

	cmp		rax,0
	je		remove

	add		rdi,8
	mov		r8,rdi
	mov		rdi,[rdi]
	jmp		loop

	remove:
	push	rdi
	push	rsi
	push	rdx
	push	rcx
	push	r8

	mov		rdi,[rdi]
	call	rcx

	pop		r8
	pop		rcx
	pop		rdx
	pop		rsi
	pop		rdi

	mov		qword [rdi],0
	mov		r9,rdi


	add		rdi,8
	mov		rdi,[rdi]
	mov		[r8],rdi

	push	rdi
	push	rsi
	push	rdx
	push	rcx
	push	r8

	mov		rdi,r9
	call	free wrt ..plt

	pop		r8
	pop		rcx
	pop		rdx
	pop		rsi
	pop		rdi
	jmp		loop


	return:
	ret
