	.file	"01cfun.c"
	.text
.globl getmax
	.type	getmax, @function
getmax:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	cmpl	%eax, 12(%ebp)
	cmovge	12(%ebp), %eax
	popl	%ebp
	ret
	.size	getmax, .-getmax
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	$2, 4(%esp)
	movl	$1, (%esp)
	call	getmax
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.4.7-1ubuntu2) 4.4.7"
	.section	.note.GNU-stack,"",@progbits
