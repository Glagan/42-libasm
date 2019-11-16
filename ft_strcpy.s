			section	.text
			global	_ft_strcpy

; delete RDX, RCX, RAX

_ft_strcpy:									; dst = rdi, src = rsi
			xor		rcx, rcx				; i = 0
			xor		rdx, rdx				; tmp = 0
			jmp		copy
increment:
			inc		rcx
copy:
			mov		dl, BYTE [rsi + rcx]
			mov		BYTE [rdi + rcx], dl
			cmp		dl, 0
			jnz		increment
done:
			mov		rax, rdi				; return dst
			ret
