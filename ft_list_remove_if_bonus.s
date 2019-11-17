			section	.text
			global	_ft_list_remove_if
			extern	_free

; delete RDI, R8 and everything that RDX, RCX and free destroy

_ft_list_remove_if:						; rdi = t_list **begin, rsi = *data_ref
										; rdx = int (*cmp)(data, data_ref), rcx = void (*free_fct)(data)
			push	rbp					; save rbp (tmp)
			push	rbx					; save rbx (previous)
			push	r12					; save r12 (first)
			mov		r12, [rdi]			; first = *begin
			xor		rbx, rbx			; previous = NULL
			cmp		rdi, 0				; begin == NULL
			jz		return
			cmp		rdx, 0
			jz		return
			cmp		rcx, 0
			jz		return
			jmp		compare_start
free_elt:
			mov		r8, [rdi]
			mov		rbp, [r8 + 8]		; tmp = (*begin)->next
			push	rsi
			push	rdx
			push	rcx
			push	rdi
			mov		rdx, [rdi]
			mov		rdi, [rdx]
			call	rcx					; (*free_fct)((*begin)->data)
			pop		rdi
			push	rdi
			mov		rdx, [rdi]
			mov		rdi, rdx
			call	_free				; free(*begin)
			pop		rdi
			pop		rcx
			pop		rdx
			pop		rsi
			mov		[rdi], rbp			; *begin = tmp
			cmp		rbx, 0				; previous == NULL
			jnz		set_previous_next
			mov		r12, rbp			; first == tmp
			jmp		compare_start
set_previous_next:
			mov		[rbx + 8], rbp		; previous.next = tmp
			jmp		compare_start
compare_null:
			xor		rdi, rsi
			mov		rax, rdi
			jmp		compare_end
move_next:
			mov		rbx, [rdi]
			mov		r8,	[rbx + 8]		; tmp = (*begin)->next
			mov		[rdi], r8			; *begin = tmp
compare_start:
			cmp		QWORD [rdi], 0		; *begin == NULL
			jz		return
			push	rdi
			push	rsi					; data_ref already in rsi
			push	rdx
			push	rcx
			mov		r8, [rdi]
			mov		rdi, [r8]			; (*begin)->data in rdi
			cmp		rdi, 0				; (*begin)->data == NULL
			jz		compare_null
			call	rdx					; (*cmp)((*begin)->data, data_ref)
compare_end:
			pop		rcx
			pop		rdx
			pop		rsi
			pop		rdi
			cmp		rax, 0				; (*cmp) == 0
			jz		free_elt			; (*free_fct)
			jmp		move_next
return:
			mov		[rdi], r12			; *begin = first
			pop		r12					; restore rbx
			pop		rbx					; restore rbx
			pop		rbp					; restore rbp
			ret