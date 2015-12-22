	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 10
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	xorl	%eax, %eax
	movl	$0, -4(%rbp)
	popq	%rbp
	retq
	.cfi_endproc

	.section	__DATA,__data
	.globl	_dx                     ## @dx
	.align	4
_dx:
	.long	1                       ## 0x1
	.long	0                       ## 0x0
	.long	4294967295              ## 0xffffffff
	.long	0                       ## 0x0

	.globl	_dy                     ## @dy
	.align	4
_dy:
	.long	0                       ## 0x0
	.long	1                       ## 0x1
	.long	0                       ## 0x0
	.long	4294967295              ## 0xffffffff


.subsections_via_symbols
