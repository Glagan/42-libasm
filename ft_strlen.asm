			section	.text
			global	_ft_strlen

_ft_strlen:
			mov		rsi, rdi
			xor		rax, rax			; i = 0
			jmp		compare
increment:
			inc		rax					; i++
compare:
			cmp		BYTE [rdi + rax], 0	; *str == 0
			jne		increment
done:
			ret							; return i