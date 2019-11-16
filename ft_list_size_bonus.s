			section	.text
			global	_ft_list_size

; delete RSI, RAX

_ft_list_size:						; rdi = begin
			mov		rsi, rdi
			xor		rax, rax
			jmp		count
increment:
			inc		rax				; total = 0
count:
			cmp		rdi, 0			; begin == NULL
			jz		return
			mov		rdi, [rdi + 8]	; begin = begin.next
			jmp		increment
return:
			mov		rdi, rsi
			ret