	.file	"01hello.c"
	.section	.rodata
	.align 4
.LC0:
	.string	"\346\234\211\351\222\261\345\260\261\346\230\257\344\273\273\346\200\247,\346\262\241\351\222\261\345\260\261\346\230\257\350\256\244\345\221\275"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$16, %esp
	movl	$.LC0, (%esp)
	call	puts
	movl	$0, %eax
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.4.7-1ubuntu2) 4.4.7"
	.section	.note.GNU-stack,"",@progbits
