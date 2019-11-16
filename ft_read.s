			section	.text
			global	_ft_read

; delete RDI, RSI, RDX, RAX and all unpreserved registers by _read

_ft_read:								; fd = rdi, buffer = rsi, bytes = rdx
			mov		rax, 0x2000003
			syscall
			ret
