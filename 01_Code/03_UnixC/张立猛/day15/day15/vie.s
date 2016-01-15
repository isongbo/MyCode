	.file	"vie.c"
.globl g_cn
	.bss
	.align 4
	.type	g_cn, @object
	.size	g_cn, 4
g_cn:
	.zero	4
	.text
.globl thread_proc
	.type	thread_proc, @function
thread_proc:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	$0, -4(%ebp)
	jmp	.L2
.L3:
	movl	g_cn, %eax
	addl	$1, %eax
	movl	%eax, g_cn
	addl	$1, -4(%ebp)
.L2:
	cmpl	$99999999, -4(%ebp)
	jbe	.L3
	movl	$0, %eax
	leave
	ret
	.size	thread_proc, .-thread_proc
	.section	.rodata
.LC0:
	.string	"g_cn = %u\n"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$32, %esp
	movl	$0, 12(%esp)
	movl	$thread_proc, 8(%esp)
	movl	$0, 4(%esp)
	leal	28(%esp), %eax
	movl	%eax, (%esp)
	call	pthread_create
	movl	$0, 12(%esp)
	movl	$thread_proc, 8(%esp)
	movl	$0, 4(%esp)
	leal	24(%esp), %eax
	movl	%eax, (%esp)
	call	pthread_create
	movl	28(%esp), %eax
	movl	$0, 4(%esp)
	movl	%eax, (%esp)
	call	pthread_join
	movl	24(%esp), %eax
	movl	$0, 4(%esp)
	movl	%eax, (%esp)
	call	pthread_join
	movl	g_cn, %edx
	movl	$.LC0, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$0, %eax
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.4.7-1ubuntu2) 4.4.7"
	.section	.note.GNU-stack,"",@progbits
