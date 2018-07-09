.LC0:
		.string	"leite"
.LC1:
		.string	"vaca"

.globl main
 .type main, @function
 main:
 LFB0:
 .cfi_startproc

movl	$.LC0, %edi
	movl	$0, %eax
	call	printf

movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
.cfi_endproc
 .LFE0:
 .size main, .-main
.globl oi
 .type oi, @function
 oi:
 LFB1:
 .cfi_startproc
.cfi_endproc
 .LFE1:
 .size oi, .-oi
