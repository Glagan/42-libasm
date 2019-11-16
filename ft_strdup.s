			section	.text
			global	_ft_strdup
			extern	_malloc

; delete RDX, RCX, RAX and everything that malloc destroy

_ft_strdup:									; rdi = src
			cmp		rdi, 0
			jz		error					; src is NULL
len_start:
			xor		rcx, rcx				; i = 0
			jmp		len_compare
len_increment:
			inc		rcx						; i++
len_compare:
			cmp		BYTE [rdi + rcx], 0		; str[i] == 0
			jne		len_increment
malloc_start:
			inc		rcx						; length++
			push	rdi						; save src
			mov		rdi, rcx
			call	_malloc					; rax = _malloc(length)
			pop		rdi						; restore src
			cmp		rax, 0
			jz		error					; malloc return NULL
copy_start:
			xor		rcx, rcx				; i = 0
			xor		rdx, rdx				; tmp = 0
			jmp		copy_copy
copy_increment:
			inc		rcx
copy_copy:
			mov		dl, BYTE [rdi + rcx]
			mov		BYTE [rax + rcx], dl
			cmp		dl, 0
			jnz		copy_increment
			jmp		return
error:
			xor		rax, rax
return:
			ret