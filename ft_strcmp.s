			section	.text
			global	_ft_strcmp

_ft_strcmp:
			xor		rcx, rcx				; i = 0
			jmp		check
compare:
			mov		dl, BYTE [rsi+rcx]		; tmp = s2[i]
			cmp		BYTE [rdi+rcx], dl		; s1[i] == tmp
			jne		last_char
increment:
			inc		rcx
check:
			cmp		BYTE [rdi+rcx], 0		; !s1[i]
			je		last_char
			cmp		BYTE [rsi+rcx], 0		; !s2[i]
			je		last_char
			jmp		compare
last_char:
			xor		rdx, rdx				; ret = 0
			mov		dl, BYTE [rdi+rcx]		; ret = s1[i]
			sub		dl, BYTE [rsi+rcx]		; ret -= s2[i]
			cmp		dl, 0					; ret == 0
			jz		equal
			jl		inferior
superior:
			mov		rax, 1
			ret
inferior:
			mov		rax, -1					; ret < 0
			ret
equal:
			mov		rax, 0					; ret > 0
			ret