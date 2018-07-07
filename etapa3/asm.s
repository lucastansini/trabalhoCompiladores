
.globl main
 .type main, @function
 main:
 LFB0:
 .section	.rodata
.LC0:
		.string	"leite"
    .cfi_startproc
    	pushq	%rbp
    	.cfi_def_cfa_offset 16
    	.cfi_offset 6, -16
    	movq	%rsp, %rbp
    	.cfi_def_cfa_register 6
    	movl	$.LC0, %edi
    	movl	$0, %eax
    	call	printf

    	movl	$0, %eax
    	popq	%rbp
    	.cfi_def_cfa 7, 8
    	ret
    	.cfi_endproc
  .LFE0:
 .size main, .-main
.globl oi
 .type oi, @function
 oi:
 LFB1:
.LFE1:
 .size oi, .-oi
