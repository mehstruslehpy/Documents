SECTION .data
msg     db      'Mehstruslehpy', 0Ah     ; assign msg variable with your message string
 
SECTION .text
global  _start

;8 / 4 
_start:
PUSH 4
PUSH 8
XOR EAX, EAX
XOR EDX, EDX
POP EDX			;4
POP EBX			;8
IDIV EBX

