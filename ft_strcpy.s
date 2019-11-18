			section	.text
			global	_ft_strcpy

; delete RDX, RCX, RAX

_ft_strcpy:									; dst = rdi, src = rsi
			xor		rcx, rcx				; i = 0
			xor		rdx, rdx				; tmp = 0
			cmp		rsi, 0					; !rsi
			jz		return
			jmp		copy
increment:
			inc		rcx
copy:
			mov		dl, BYTE [rsi + rcx]
			mov		BYTE [rdi + rcx], dl
			cmp		dl, 0
			jnz		increment
return:
			mov		rax, rdi				; return dst
			ret
