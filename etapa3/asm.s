.globl a
 	.align 4
  	.type a, @object
  	.size a, 4
a:
  	.long 12
.globl b
 	.align 4
  	.type b, @object
  	.size b, 4
b:
  	.long 2
.LC0:
		.string	"leite\n"
.LC1:
		.string	"vaca"
.LC2:
		.string	"\n"
.LC3:
		.string	"\n"
.LC9999999:
		.string	"%d"
.globl main
 .type main, @function
 main:
 LFB0:
 .cfi_startproc
	pushq %rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6

movl	$.LC0, %edi
	movl	$0, %eax
	call	printf

movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movl a(%rip),%eax
movl %eax, %esi
	movl $.LC9999999, %edi
	movl $0, %eax
	call printf

movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	movl b(%rip),%eax
movl %eax, %esi
	movl $.LC9999999, %edi
	movl $0, %eax
	call printf

movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	movl $0, %eax
	popq %rbp
	.cfi_def_cfa 7, 8
	ret
.cfi_endproc
 .LFE0:
 .size main, .-main
.globl oi
 .type oi, @function
 oi:
 LFB1:
 .cfi_startproc
	pushq %rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl $0, %eax
	popq %rbp
	.cfi_def_cfa 7, 8
	ret
.cfi_endproc
 .LFE1:
 .size oi, .-oi