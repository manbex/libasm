section	.note.GNU-stack
section	.text
global	ft_atoi_base

ft_check_duplicate:
	xor		rcx,rcx
	movzx	rdi,byte[rdi]

	loop_check_duplicate:
	cmp		byte[rsi],0
	je		end_check_duplicate

	cmp		rcx,rdx
	je		skip_same_character

	movzx	rax,byte[rsi]
	sub		rax,rdi
	jz		duplicate_found

	skip_same_character:
	inc		rcx
	inc		rsi
	jmp		loop_check_duplicate

	duplicate_found:
	mov		rax,1
	ret

	end_check_duplicate:
	mov		rax,0
	ret


ft_check_base:
	xor		rcx,rcx

	loop_check_base:
	cmp		byte[rdi],0
	je		end_check_base

	cmp		byte[rdi],'+'
	je		error_check_base
	cmp		byte[rdi],'-'
	je		error_check_base
	cmp		byte[rdi],'!'
	jl		error_check_base
	cmp		byte[rdi],'~'
	jg		error_check_base

	push	rdi
	push	rsi
	push	rcx

	mov		rdx,rcx

	call	ft_check_duplicate

	pop		rcx
	pop		rsi
	pop		rdi

	cmp		rax,1
	je		error_check_base

	inc		rcx
	inc		rdi
	jmp		loop_check_base

	end_check_base:
	cmp		rcx,1
	je		error_check_base

	mov		rax,rcx
	ret

	error_check_base:
	mov		rax,0
	ret


ft_skip_whitespaces:
	cmp		byte[rdi],0
	je		end_skip_whitespaces

	cmp		byte[rdi],' '
	je		continue_skip_whitespaces

	cmp		byte[rdi],13
	jg		end_skip_whitespaces

	cmp		byte[rdi],9
	jl		end_skip_whitespaces

	continue_skip_whitespaces:
	inc		rdi
	jmp		ft_skip_whitespaces

	end_skip_whitespaces:
	ret


ft_check_sign:
	mov		rax,1

	loop_check_sign:
	cmp		byte[rdi],0
	je		end_check_sign

	cmp		byte[rdi],'+'
	je		continue_loop_check_sign

	cmp		byte[rdi],'-'
	jne		end_check_sign

	neg		rax

	continue_loop_check_sign:
	inc		rdi
	jmp		loop_check_sign

	end_check_sign:
	ret



ft_search_base:
	xor		rcx,rcx
	mov		rax,-1
	movzx	rdi,byte[rdi]

	loop_search_base:
	cmp		byte[rsi],0
	je		end_search_base

	movzx	rdx,byte[rsi]
	sub		rdx,rdi
	jz		character_found
	
	inc		rcx
	inc		rsi
	jmp		loop_search_base

	character_found:
	mov		rax,rcx

	end_search_base:
	ret


ft_atoi_base:
	xor		rax,rax

	test	rdi,rdi
	jz		return_atoi_base
	test	rsi,rsi
	jz		return_atoi_base

	push	rdi
	push	rsi

	mov		rdi,rsi
	call	ft_check_base

	pop		rsi
	pop		rdi

	cmp		rax,0
	je		return_atoi_base

	xor		rcx,rcx
	mov		rdx,rax

	call	ft_skip_whitespaces
	push	rdx
	call	ft_check_sign
	pop		rdx
	push	rax

	loop_atoi_base:
	cmp		byte[rdi],0
	je		end_loop_atoi_base

	push	rdi
	push	rsi
	push	rcx
	push	rdx

	call	ft_search_base

	pop		rdx
	pop		rcx
	pop		rsi
	pop		rdi

	cmp		rax,-1
	je		end_loop_atoi_base

	push	rax
	push	rdx

	mov		rax,rcx
	mul		rdx
	mov		rcx,rax

	pop		rdx
	pop		rax
	add		rcx,rax

	inc		rdi
	jmp		loop_atoi_base

	end_loop_atoi_base:
	pop		rax
	imul	rcx

	return_atoi_base:
	ret
