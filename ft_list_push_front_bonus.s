			section	.text
			global	_ft_list_push_front
			extern	_malloc

; delete RCX, RDX, RAX

_ft_list_push_front:				; rdi = t_list **begin, rsi = void *data
			push	rsp				; align stack
			push	rdi				; save begin
			push	rsi				; save data
			mov		rdi, 16
			xor		rax, rax
			call	_malloc			; malloc(sizeof(t_list)) (16)
			pop		rsi
			pop		rdi
			cmp		rax, 0
			jz		return			; malloc failed
			mov		[rax], rsi		; new.data = data
			mov		rcx, [rdi]
			mov		[rax + 8], rcx	; new.next = *begin
			mov		[rdi], rax		; *begin = new
return:
			pop		rsp				; align stack
			ret