# 
#									
#	Copyright (c) 1985,1986,1987,1988,1989,1990,1991,1992   AT&T	
#			All Rights Reserved				
#									
#	  THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T.		
#	    The copyright notice above does not evidence any		
#	   actual or intended publication of such source code.		
#									
# 
	.file	"min.c"
	.def	min;	.val	min;	.scl	2;	.type	044;	.endef
	.globl	min
min:
	MOVW	0(%ap),%r0
	MOVW	4(%ap),%r1
	.ln	2
	cmpw	%r0,%r1
	jge	.L9999
	RET
.L9999:
	MOVW	%r1,%r0
	.ln	3
	RET
	.def	min;	.val	.;	.scl	-1;	.endef

	.def	max;	.val	max;	.scl	2;	.type	044;	.endef
	.globl	max

max:	MOVW	0(%ap),%r0
	MOVW	4(%ap),%r1
	.ln	2
	cmpw	%r0,%r1
	jle	.L9997
	RET
.L9997:
	MOVW	%r1,%r0
	.ln	3
	RET
	.def	max;	.val	.;	.scl	-1;	.endef
