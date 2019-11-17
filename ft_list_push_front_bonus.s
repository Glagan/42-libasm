			section	.text
			global	_ft_list_push_front
			extern	_malloc

; delete RCX, RDX, RAX

_ft_list_push_front:				; rdi = t_list **begin, rsi = void *data
			push	rbp				; save begin
			push	rbx				; save data
			mov		rbp, rdi
			mov		rbx, rsi
			mov		rdi, 16
			call	_malloc			; malloc(sizeof(t_list)) (16)
			mov		rdi, rbp
			mov		rsi, rbx
			cmp		rax, 0
			je		return			; malloc failed
			mov		[rax], rsi		; new.data = data
			mov		rcx, [rdi]
			mov		[rax + 8], rcx	; new.next = *begin
			mov		[rdi], rax		; *begin = new
return:
			pop		rbx
			pop		rbp
			ret