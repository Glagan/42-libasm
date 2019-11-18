			section	.text
			global	_ft_list_sort

; delete RCX, R8 and RAX

_ft_list_sort:							; rdi = t_list **begin, rsi = int (*cmp)(d1, d2)
			push	rbx					; save rbx (next)
			push	r12					; save r12 (first)
			cmp		rdi, 0				; begin == NULL
			jz		restore
			mov		r12, [rdi]			; first = *begin
			cmp		rsi, 0				; cmp == NULL
			jz		return
			jmp		compare_main
increment_main:
			mov		rcx, [rdi]
			mov		rbx, [rcx + 8]
			mov		[rdi], rbx			; *begin = (*begin)->next
compare_main:
			cmp		QWORD [rdi], 0		; !*begin
			jz		return
			mov		rcx, [rdi]
			mov		rbx, [rcx + 8]		; current = (*begin)->next
compare_single:
			cmp		rbx, 0				; !current
			jz		increment_main
compare:
			push	rdi
			push	rsi
			mov		rax, rsi
			mov		rcx, [rdi]
			mov		rdi, [rcx]			; rdi = (*begin)->data
			mov		rsi, [rbx]			; rsi = current->data
			call	rax					; (*cmp)((*begin)->data, current->data)
			pop		rsi
			pop		rdi
			cmp		rax, 0				; cmp > 0
			jg		swap
increment_single:
			mov		rcx, [rbx + 8]
			mov		rbx, rcx			; current = current.next
			jmp		compare_single
swap:
			mov		r8, [rdi]
			mov		rcx, [r8]			; rcx = (*begin)->data
			mov		rax, [rbx]			; rax = current->data
			mov		[r8], rax			; (*begin)->data = current->data
			mov		[rbx], rcx			; current->data = (*begin)->data
			jmp		increment_single
return:
			mov		[rdi], r12			; *begin = first
restore:
			pop		r12					; restore r12
			pop		rbx					; restore rbx
			ret