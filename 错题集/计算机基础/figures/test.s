_square:                               ; @square
	mul	w0, w0, w0
	ret
_cube:                                  ; @cube
	stp	x29, x30, [sp, #32]  ; 前索引寻址            
	mov	x29, sp
	str x19, [sp, #16]
	mov w19, w0
	bl	_square
	mul	w0, w0, w19
	ldr x19, [sp, #16]
	ldp x29, x30, [sp], 32   ;后索引寻址
	ret
