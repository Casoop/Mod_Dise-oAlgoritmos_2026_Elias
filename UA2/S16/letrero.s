	.file	"letrero.c"
	.text
	.section .rdata,"dr"
	.align 8
.LC0:
	.ascii "MENU DEL DIA - SODA \"LA ESQUINA\"\0"
.LC1:
	.ascii "Platillo\11Precio\0"
.LC2:
	.ascii "Casado\11\11"
	.ascii "3500\0"
.LC3:
	.ascii "Gallo pinto\11"
	.ascii "2000\0"
.LC4:
	.ascii "Refresco\11"
	.ascii "1000\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	call	__main
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	puts
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	puts
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	puts
	leaq	.LC3(%rip), %rax
	movq	%rax, %rcx
	call	puts
	leaq	.LC4(%rip), %rax
	movq	%rax, %rcx
	call	puts
	movl	$0, %eax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (Rev4, Built by MSYS2 project) 16.2.0"
	.def	puts;	.scl	2;	.type	32;	.endef
