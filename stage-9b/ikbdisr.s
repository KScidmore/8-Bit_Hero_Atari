		xdef 	_ikbd_isr
		xref	_do_ikbd_isr

_ikbd_isr:	movem.l d0-d2/a0-a2,-(sp)
		jsr	_do_ikbd_isr 
		movem.l (sp)+,d0-d2/a0-a2 
		rte