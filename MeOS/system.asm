; Listing generated by Microsoft (R) Optimizing Compiler Version 19.00.23918.0 

	TITLE	C:\Users\michalis\Documents\Visual Studio 2015\Projects\MeOS\MeOS\system.c
	.686P
	.XMM
	include listing.inc
	.model	flat

INCLUDELIB MSVCRTD
INCLUDELIB OLDNAMES

PUBLIC	_inportb
PUBLIC	_inportw
PUBLIC	_inportl
PUBLIC	_outportb
PUBLIC	_outportw
PUBLIC	_outportl
; Function compile flags: /Odtpy
_TEXT	SEGMENT
__port$ = 8						; size = 2
__data$ = 12						; size = 4
_outportl PROC
; File c:\users\michalis\documents\visual studio 2015\projects\meos\meos\system.c
; Line 67
	push	ebp
	mov	ebp, esp
; Line 70
	mov	dx, WORD PTR __port$[ebp]
; Line 71
	mov	eax, DWORD PTR __data$[ebp]
; Line 73
	out	dx, ax
; Line 75
	pop	ebp
	ret	0
_outportl ENDP
_TEXT	ENDS
; Function compile flags: /Odtpy
_TEXT	SEGMENT
__port$ = 8						; size = 2
__data$ = 12						; size = 2
_outportw PROC
; File c:\users\michalis\documents\visual studio 2015\projects\meos\meos\system.c
; Line 56
	push	ebp
	mov	ebp, esp
; Line 59
	mov	dx, WORD PTR __port$[ebp]
; Line 60
	mov	ax, WORD PTR __data$[ebp]
; Line 62
	out	dx, ax
; Line 64
	pop	ebp
	ret	0
_outportw ENDP
_TEXT	ENDS
; Function compile flags: /Odtpy
_TEXT	SEGMENT
__port$ = 8						; size = 2
__data$ = 12						; size = 1
_outportb PROC
; File c:\users\michalis\documents\visual studio 2015\projects\meos\meos\system.c
; Line 45
	push	ebp
	mov	ebp, esp
; Line 48
	mov	dx, WORD PTR __port$[ebp]
; Line 49
	mov	al, BYTE PTR __data$[ebp]
; Line 51
	out	dx, al
; Line 53
	pop	ebp
	ret	0
_outportb ENDP
_TEXT	ENDS
; Function compile flags: /Odtpy
_TEXT	SEGMENT
_rv$ = -4						; size = 4
__port$ = 8						; size = 2
_inportl PROC
; File c:\users\michalis\documents\visual studio 2015\projects\meos\meos\system.c
; Line 32
	push	ebp
	mov	ebp, esp
	push	ecx
; Line 36
	mov	dx, WORD PTR __port$[ebp]
; Line 38
	in	eax, dx
; Line 39
	mov	DWORD PTR _rv$[ebp], eax
; Line 41
	mov	eax, DWORD PTR _rv$[ebp]
; Line 42
	mov	esp, ebp
	pop	ebp
	ret	0
_inportl ENDP
_TEXT	ENDS
; Function compile flags: /Odtpy
_TEXT	SEGMENT
_rv$ = -4						; size = 2
__port$ = 8						; size = 2
_inportw PROC
; File c:\users\michalis\documents\visual studio 2015\projects\meos\meos\system.c
; Line 19
	push	ebp
	mov	ebp, esp
	push	ecx
; Line 23
	mov	dx, WORD PTR __port$[ebp]
; Line 25
	in	ax, dx
; Line 26
	mov	WORD PTR _rv$[ebp], ax
; Line 28
	mov	ax, WORD PTR _rv$[ebp]
; Line 29
	mov	esp, ebp
	pop	ebp
	ret	0
_inportw ENDP
_TEXT	ENDS
; Function compile flags: /Odtpy
_TEXT	SEGMENT
_rv$ = -1						; size = 1
__port$ = 8						; size = 2
_inportb PROC
; File c:\users\michalis\documents\visual studio 2015\projects\meos\meos\system.c
; Line 4
	push	ebp
	mov	ebp, esp
	push	ecx
; Line 9
	mov	dx, WORD PTR __port$[ebp]
; Line 10
	in	al, dx
; Line 12
	mov	BYTE PTR _rv$[ebp], al
; Line 15
	mov	al, BYTE PTR _rv$[ebp]
; Line 16
	mov	esp, ebp
	pop	ebp
	ret	0
_inportb ENDP
_TEXT	ENDS
END