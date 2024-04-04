		xdef	_clear_screen
		xdef	_set_video
GEMDOS	equ		1
base	equ		64		; offset from SP, not A6
ADDRESS  equ	$FFFF8201
STACK_OFFSET	equ		8



; ID Header:
;   Authors: 	Andrew Boisvert, Kyle Scidmore, Marc Schroeder
;   Emails: 	abois526@mtroyal.ca, kscid215@mtroyal.ca 
;   File Name:	RAST_ASM.S
;   Citations:  
;     - the function _clear_screen was authored by 
;       Marc Schroeder
;
; Program Purposes:
;   Data Structures: 
;     - TODO
;
;   Functions:
;     - TODO  
; 

;----- FUNCTION: _clear_screen -----
;
; PURPOSE:
;   TODO - purpose, from the caller's perspective (if not
;   perfectly clear from the name)
;
; CALLER INPUT:
;   TODO - the purpose of each input parameter (if not 
;   perfectly clear from the name)
;
; CALLER OUTPUT:
;   TODO - the purose of each output parameter and return 
;   value (if not perfectly clear from the name)
;
; ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
;   - uses movem to reduce fetch-execute cycle overhead 
;   - takes about half the number of clock cycles as the code 
;     in clear.s, and so runs in about 1/100th of a second (at
;     8Mhz) instead of 1/50th
;
;--------------------------------------------------------
_clear_screen:	movem.l		d0-7/a0-6,-(sp)
		lea		zeros,a0
		movem.l		(a0)+,d1-7/a1-6
		movea.l		base(sp),a0
		adda.l		#32000,a0
		move.w		#614,d0
fill_loop:	movem.l		d1-7/a1-6,-(a0)
		dbra		d0,fill_loop
		movem.l		d1-5,-(a0)
		movem.l		(sp)+,d0-7/a0-6
		rts
;---------------------------------------------------------

_set_video:
		link	a6,#0
		movem.l	d0-d2/a0-a2,-(sp)
		
		move.w	STACK_OFFSET(a6),d0		;Get buffer address from stack
		lsr		#8,d0					
		move.l 	#ADDRESS,a0				;Load video base Hi address into a0
		movep.w d0,(a0)					;Set Buffer 
		
		movem.l	(sp)+,d0-d2/a0-a2
		unlk	a6
		rts

;----- FUNCTION: _super_start -----
;
; PURPOSE:
;   Enters supervisor mode
;
;
;----------------------------------------------------------
_super_start:	movem.l	d0,-(sp)	;Save register

				clr.l	-(sp)		;Prepare stack
				move.w	#$20,-(sp)	;Move $20 to the stack
				trap	#GEMDOS		;Invoke GEMDOS
				addq.l	#6,sp		;Clean stack
				move.l	d0,old_ssp	;Save old stack pointer
		
				movem.l	(sp)+,d0	;Restore Register
				rts
;----------------------------------------------------------

;----- FUNCTION: _super_end -----
;
; PURPOSE:
;   Exits supervisor mode
;
;---------------------------------------------------------
_super_end:		movem.l	d0,-(sp)			;Save register

				move.l	old_ssp(pc),-(sp)	;Move old ssp to the stack
				move.w	#$20,-(sp)			;Move $20 to the stack
				trap	#GEMDOS				;Invoke GEMDOS
				addq.l	#6,sp				;Clean Stack
		
				movem.l	(sp)+,d0			;Restore Register
				rts
;----------------------------------------------------------


old_ssp		ds.l 		1
zeros:		ds.l		13