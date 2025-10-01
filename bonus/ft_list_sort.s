section	.note.GNU-stack
section	.text
global	ft_list_sort

ft_insert:
	ret


ft_list_sort:
	cmp		rdi,0
	je		return

	mov		rcx,[rdi]

	cmp		rcx,0
	je		return
	cmp		qword[rcx+8],0
	je		return

	mov		r8,rsi
	push	rdi
	mov		rax,[rcx+8]
	mov		rdx,[rax+8]
	mov		qword[rax+8],0

	mov		rdi,rcx
	mov		rsi,[rcx+8]
	push	rcx
	push	rdx
	call	r8
	pop		rdx
	pop		rcx
	cmp		rax,0
	jle		main_loop

	mov		rax,rcx
	mov		rcx,[rcx+8]
	mov		[rcx+8],rax
	mov		qword[rax+8],0

	main_loop:
	mov		r9,rdx
	mov		rdx,[rdx+8]
	mov		qword[r9+8],0
	call	ft_insert
	;jmp		main_loop

	end:
	pop		rax
	mov		[rax],rcx

	return:
	ret
