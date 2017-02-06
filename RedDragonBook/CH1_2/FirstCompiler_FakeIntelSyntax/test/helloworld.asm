; Hello World Program - asmtutor.com
; Compile with: nasm -f elf helloworld.asm
; Link with (64 bit systems require elf_i386 option): ld -m elf_i386 helloworld.o -o helloworld
; Run with: ./helloworld
 
SECTION .data
msg     db      'Hello World!', 0Ah     ; assign msg variable with your message string
 
SECTION .text
global  _start
 
_start:
	PUSH 1
	PUSH 2
	POP EAX			;2
	POP EBX			;1
	SUB EBX, EAX	; EBX = 1 - 2
	PUSH EAX

