# libasm

## Registers

```
; 64-bit
R0  R1  R2  R3  R4  R5  R6  R7  R8  R9  R10  R11  R12  R13  R14  R15
RAX RCX RDX RBX RSP RBP RSI RDI

; 32-bit
R0D R1D R2D R3D R4D R5D R6D R7D R8D R9D R10D R11D R12D R13D R14D R15D
EAX ECX EDX EBX ESP EBP ESI EDI

; 16-bit
R0W R1W R2W R3W R4W R5W R6W R7W R8W R9W R10W R11W R12W R13W R14W R15W
AX  CX  DX  BX  SP  BP  SI  DI

; 8-bit
R0B R1B R2B R3B R4B R5B R6B R7B R8B R9B R10B R11B R12B R13B R14B R15B
AL  CL  DL  BL  SPL BPL SIL DIL

; 128-bit
XMM0 ... XMM15
```

## Constants

```
	db    0x55                ; just the byte 0x55
	db    0x55,0x56,0x57      ; three bytes in succession
	db    'a',0x55            ; character constants are OK
	db    'hello',13,10,'$'   ; so are string constants
	dw    0x1234              ; 0x34 0x12
	dw    'a'                 ; 0x61 0x00 (it's just a number)
	dw    'ab'                ; 0x61 0x62 (character constant)
	dw    'abc'               ; 0x61 0x62 0x63 0x00 (string)
	dd    0x12345678          ; 0x78 0x56 0x34 0x12
	dd    1.234567e20         ; floating-point constant
	dq    0x123456789abcdef0  ; eight byte constant
	dq    1.234567e20         ; double-precision float
	dt    1.234567e20         ; extended-precision float
```

## Number affixes

```
200          ; decimal
0200         ; still decimal - the leading 0 does not make it octal
0200d        ; explicitly decimal - d suffix
0d200        ; also decimal - 0d prefex
0c8h         ; hex - h suffix, but leading 0 is required because c8h looks like a var
0xc8         ; hex - the classic 0x prefix
0hc8         ; hex - for some reason NASM likes 0h
310q         ; octal - q suffix
0q310        ; octal - 0q prefix
11001000b    ; binary - b suffix
0b1100_1000  ; binary - 0b prefix, and by the way, underscores are allowed
```

## Functions

```
; Parameters registers
RDI RSI RDX RCX R8 R9

; Register to preserve
RBP RBX R12 R13 R14 R15

;
call	FUNCTION

; Return register
RAX

; syscall registers
mov		rax, CODE	; Then RDI, RSI etc.. for params
```

## Common

```
; Save register
push	REG
pop		REG

; Set register value
mov		REG, value

; Common operations
add		DEST, VALUE
sub		-
inc		REG
dec		-
and		DEST, REG
xor		-

; Dereferenced value
[REG]

; Compare
cmp	REG, VALUE

; Label
label:
		jmp	label	; next jumps depends on compare flags
		je	-		; is equal
		jne	-		; is not equal
		jl	-		; < VALUE
		jle	-		; <= VALUE
		jz	-		; = 0
		jnz	-		; != 0
		jg	-		; > VALUE
		jge	-		; >= VALUE

; Constants
	section	.data
name:	db	{byte, byte, ...}	; Strings end with 0 ; 10 is newline
```

## Ressources

* [syscalls MacOS](https://opensource.apple.com/source/xnu/xnu-1504.3.12/bsd/kern/syscalls.master)
* [Linux syscalls](http://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/)
* [Hello, world!](https://gist.github.com/FiloSottile/7125822)
* [NASM Tutorial](https://cs.lmu.edu/~ray/notes/nasmtutorial/)
* [AMD64 Cheatsheet](http://web.archive.org/web/20160801075139/www.x86-64.org/documentation/abi.pdf)
* [ASM Tutorial](https://github.com/0xAX/asm)
* [Some code](https://www.conradk.com/codebase/2017/06/06/x86-64-assembly-from-scratch/)
* [Weird Chinese copy](http://www.voidcn.com/article/p-tvlwrlcp-bq.html)
