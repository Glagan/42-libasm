			section	.text
			global	_ft_strdup
			extern	_ft_strlen, _ft_strcpy, _malloc

; delete RDI, RSI, RDX, RCX, RSP, RAX and everything that malloc destroy

_ft_strdup:									; rdi = src
			cmp		rdi, 0
			jz		error
			call	_ft_strlen
			mov		rcx, rax				; length = _ft_strlen(src)
			inc		rcx						; length++
			push	rdi						; save src
			mov		rdi, rcx
			call	_malloc					; rax = _malloc(length)
			pop		rdi						; restore src
			cmp		rax, 0
			jz		error					; malloc return NULL
			mov		rsi, rdi
			mov		rdi, rax
			call	_ft_strcpy
			jmp		return
error:
			mov		rax, 0
return:
			ret