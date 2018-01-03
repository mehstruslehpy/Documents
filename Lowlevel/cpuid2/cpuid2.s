#cpuid2.s sample program to extract processor Vendor Id
.section .data
output:
	.asciz "The processor vendor id is '%s'\n"
.section .bss
	.lcomm buffer, 12
.section .text
.globl _start
_start:
	movl $0, %eax
	cpuid
	movl $buffer, %edi
	movl %ebx, (%edi)
	movl %edx, 4(%edi)
	movl %ecx, 8(%edi)
	pushl $buffer
 	pushl $output
	call printf
	addl $8, %esp
	pushl $0
	call exit
