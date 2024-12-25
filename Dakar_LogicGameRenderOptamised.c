void	Dakar_Render()
{
	__asm
	{
//	.text
//		.align	2
//		.globl	Dakar_Render
//		.type	 Dakar_Render,function
//		.thumb_func
//	Dakar_Render:
		push	{r4, r5, r6, r7, lr}
		mov	r7, r8
		push	{r7}
		add	sp, sp, #-48
		mov	r7, sp

		// fps = 0
		ldr	r0, .L53
		mov	r1, #0
		strh	r1, [r0]

		// Col.PaletteIndex = 0;
		ldr	r0, .L53+4
		//ldrb	r1, [r0]
		mov	r2, #0
		//and	r1, r1, r2
		//add	r2, r1, #0
		strb	r2, [r0]

		// Function call: Graphics_ClearScreen: r0 = &Col;
		ldr	r1, .L53+4
		ldr	r0, [r1]
		//add	r0, r1, #0
		bl	Graphics_ClearScreen
		
		// Calculate Addr_Store.
		ldr	r0, .L53+8
		ldr	r2, .L53+12
		ldrb	r1, [r2]

		// Multiply r1 by 12 and add r0
	//	add	r3, r1, #0
	//	lsl	r2, r3, #1
	//	add	r2, r2, r1
	//	lsl	r1, r2, #2
	//	add	r0, r0, r1

		// The same in ARM.
		mla	r0, r1, #12, r0	

		// Obtain address and store away in r7+32
		ldr	r1, [r0]
		str	r1, [r7, #32]

	//	add	r0, r7, #0	// Directly access later.
		mov	r1, #0
		strb	r1, [r7]

		b	.L14		// Jump into loop.

	.L54:
		.align	2
	.L53:
		.word	fps
		.word	Col
		.word	Graphics_Buffer
		.word	Graphics_ActiveScreen

	// Rayline loop.
	.L14:
		//add	r0, r7, #0
		ldrb	r1, [r7]
		cmp	r1, #159
	//	bls	.L17	@cond_branch
	//	b	.L15
		bge	.L15	// Jump to .L15 if the value is greater than or equal to 159.
	
	.L17:
		//add	r1, r7, #0
		ldrb	r0, [r7]

		// Multiply r0 by 240 (guessing for C)
		//add	r2, r0, #0
		//lsl	r1, r2, #4
		//sub	r1, r1, r0
		//lsl	r0, r1, #4
		mov	r2, r0
		mul	r0, r0, #240

		// Reference Addr_Store, add r0 and store into r7 + 28 (Addr).
		ldr	r1, [r7, #32]
		add	r0, r1, r0
		str	r0, [r7, #28]

		// mx?
		add	r0, r7, #6
		ldr	r1, .L55
		ldrh	r2, [r1]
		strh	r2, [r0]
		add	r0, r7, #8 // #0
		//add	r0, r0, #8

		// my
		ldr	r1, .L55
		ldrh	r2, [r1, #2]
		strh	r2, [r0]
		add	r0, r7, #8	// #8
		//add	r0, r0, #8

		// Calculate and store plocale.
		ldrh	r1, [r0]
		mov	r2, #254
		lsl	r2, r2, #7
		add	r0, r1, #0
		and	r0, r0, r2
		add	r2, r0, #0
		lsl	r1, r2, #16
		asr	r0, r1, #16
		add	r1, r7, #6
		mov	r3, #0
		ldrsh	r2, [r1, r3]
		asr	r1, r2, #8
		add	r3, r1, #0
		lsl	r2, r3, #16
		asr	r1, r2, #16
		add	r0, r0, r1
		ldr	r1, .L55+4
		add	r1, r1, r0	// Originally loaded into r0...
		str	r1, [r7, #24] // ... and saved r0...

		add	r0, r7, #18
		//add	r0, r0, #18
		//ldr	r1, [r7, #24]	// ... but saves this.


		sub	r2, r1, #1		// r2 = plocale - 1
		ldrb	r1, [r2]	// r1 = *r2.
		add	r2, r7, #6		// r2 = &mx
		ldrh	r3, [r2]	// r3 = mx.
		//mov	r6, #255	
		//add	r2, r3, #0	
		and	r6, r3, #255	// r6 = r3 & 255.
		//add	r6, r2, #0	
		lsl	r3, r6, #16		// r3 = r6 << 16
		asr	r2, r3, #16		// r2 = r3 >> 16
		mov	r3, #256		// was 128
		//lsl	r3, r3, #1	// but then << 1
		sub	r2, r3, r2
		mul	r1, r1, r2

		ldr	r2, [r7, #24]	// r2 = plocale
		add	r3, r2, #1		// r3 = r2 + 1;
		ldrb	r2, [r3]	// r2 = *r3;
		add	r3, r7, #6		// r3 = &mx.
		ldrh	r6, [r3]	// r6 = *r3
		mov	r3, #255
		//mov	r8, r3
		//mov	r3, r8
		and	r3, r3, r6
		//mov	r8, r3
		//mov	r3, r8
		lsl	r6, r3, #16
		asr	r3, r6, #16
		mul	r2, r2, r3
		add	r1, r1, r2

		ldr	r2, [r7, #24]	// plocale
		ldr	r6, .L55+8
		add	r3, r2, r6
		ldrb	r2, [r3]
		add	r3, r7, #0
		add	r3, r3, #8
		ldrh	r6, [r3]

		mov	r3, #255
		//mov	r8, r3
		//mov	r3, r8
		and	r3, r3, r6
		//mov	r8, r3
		//mov	r3, r8
		lsl	r6, r3, #16
		asr	r3, r6, #16
		mov	r6, #256
		//lsl	r6, r6, #1
		sub	r3, r6, r3
		mul	r2, r2, r3
		add	r1, r1, r2

		ldr	r2, [r7, #24]	// plocale
		mov	r6, #256
		//lsl	r6, r6, #1
		add	r3, r2, r6
		ldrb	r2, [r3]
		add	r3, r7, #8
		//add	r3, r3, #8
		ldrh	r6, [r3]
		mov	r3, #255
		//mov	r8, r3
		//mov	r3, r8
		and	r3, r3, r6
		//mov	r8, r3
		//mov	r3, r8
		lsl	r6, r3, #16
		asr	r3, r6, #16
		mul	r2, r2, r3
		add	r1, r1, r2

		// div 2.
		asr	r2, r1, #1
		//add	r1, r2, #0

		mov	r6, #2560
		//lsl	r6, r6, #4

		add	r1, r2, r6
		add	r2, r1, #0
		strh	r1, [r0]

		// Sin / Cos calculations.
		add	r0, r7, #10
		//add	r0, r0, #10
		ldr	r1, .L55+12
		ldr	r3, .L55+16
		mov	r6, #2
		ldrsh	r2, [r3, r6]
		add	r3, r7, #0
		ldrb	r6, [r3]
		//add	r3, r6, #0
		//sub	r3, r3, #80
		sub r3, r6, #80

		asr	r6, r3, #1
		add	r2, r2, r6
		mov	r3, #255
		and	r2, r2, r3
		add	r3, r2, #0
		lsl	r2, r3, #1
		add	r1, r1, r2
		//mov	r3, #0
		ldrsh	r2, [r1, #0]
		asr	r1, r2, #2
		add	r2, r1, #0
		strh	r2, [r0]
		add	r0, r7, #12
		//add	r0, r0, #12

		ldr	r1, .L55+12
		ldr	r3, .L55+16
		mov	r6, #2
		ldrsh	r2, [r3, r6]
		add	r3, r7, #0
		ldrb	r6, [r3]
	//	add	r3, r6, #0
	//	sub	r3, r3, #80
		sub r3, r6, #80

		asr	r6, r3, #1
		add	r2, r2, r6
		mov	r3, #255
		and	r2, r2, r3
		add	r3, r2, #64
		//add	r3, r3, #64
		add	r2, r3, #0
		lsl	r3, r2, #1
		add	r1, r1, r3
		//mov	r3, #0
		ldrsh	r2, [r1, #0]
		asr	r1, r2, #2
		add	r2, r1, #0
		strh	r2, [r0]
		add	r0, r7, #2
		mov	r1, #0
		strh	r1, [r0]
		add	r0, r7, #16
		//add	r0, r0, #16
		mov	r1, #11
		strb	r1, [r0]
	.L18:
		add	r0, r7, #16
		//add	r0, r0, #16
		ldrb	r1, [r0]
		cmp	r1, #29
		bls	.L21	@cond_branch
		b	.L16
	.L56:
		.align	2
	.L55:
		.word	Dakar_ViewPosition
		.word	Map_Alt
		.word	-256
		.word	sin_cos_table
		.word	Dakar_ViewDirection
	.L21:
		add	r0, r7, #6
		add	r1, r7, #6
		add	r2, r7, #0
		add	r2, r2, #10
		ldrh	r1, [r1]
		ldrh	r2, [r2]
		add	r1, r1, r2
		//add	r2, r1, #0
		strh	r1, [r0]
		add	r0, r7, #8
		//add	r0, r0, #8
		add	r1, r7, #8
		//add	r1, r1, #8
		add	r2, r7, #12
		//add	r2, r2, #12
		ldrh	r1, [r1]
		ldrh	r2, [r2]
		add	r2, r1, r2
		//add	r2, r1, #0
		strh	r2, [r0]
		add	r0, r7, #14
		//add	r0, r0, #14
		add	r1, r7, #6
		ldrh	r1, [r1]
		//add	r1, r2, #0
		//mov	r2, #0
		//bic	r1, r1, r2
		//add	r2, r1, #0
		strb	r1, [r0]
		add	r0, r7, #15
		//add	r0, r0, #15
		add	r1, r7, #8
		//add	r1, r1, #8
		ldrh	r1, [r1]
		//add	r1, r2, #0
		//mov	r2, #0
		//bic	r1, r1, r2
		//add	r2, r1, #0
		strb	r1, [r0]
		add	r0, r7, #8
		//add	r0, r0, #8
		ldrh	r1, [r0]
		mov	r2, #254
		lsl	r2, r2, #7
		//add	r0, r1, #0
		and	r0, r1, r2
		add	r2, r0, #0
		lsl	r1, r2, #16
		asr	r0, r1, #16
		add	r1, r7, #6
		//mov	r6, #0
		ldrsh	r2, [r1, #0]
		asr	r1, r2, #8
		add	r3, r1, #0
		lsl	r2, r3, #16
		asr	r1, r2, #16
		add	r0, r0, r1
		ldr	r1, .L57
		add	r0, r1, r0
		str	r0, [r7, #24]
		add	r0, r7, #20
		//add	r0, r0, #20
		ldr	r1, [r7, #24]
		sub	r2, r1, #1
		ldrb	r1, [r2]
		add	r2, r7, #14
		//add	r2, r2, #14
		ldrb	r3, [r2]
		mov	r6, #256
		//lsl	r6, r6, #1
		sub	r2, r6, r3
		mul	r1, r1, r2
		ldr	r2, [r7, #24]
		add	r3, r2, #1
		ldrb	r2, [r3]
		add	r3, r7, #14
		//add	r3, r3, #14
		ldrb	r6, [r3]
		mul	r2, r2, r6
		add	r1, r1, r2
		ldr	r2, [r7, #24]
		ldr	r6, .L57+4
		add	r3, r2, r6
		ldrb	r2, [r3]
		add	r3, r7, #15
		//add	r3, r3, #15
		ldrb	r6, [r3]
		str	r6, [r7, #40]
		mov r3, #256
		//lsl	r3, r3, #1
		mov	r6, r3
		//mov	r6, r8
		ldr	r3, [r7, #40]
		sub	r6, r6, r3
		str	r6, [r7, #44]
		//ldr	r6, [r7, #44]
		mul	r2, r2, r6
		add	r1, r1, r2
		ldr	r2, [r7, #24]
		mov	r6, #256
		//lsl	r6, r6, #1
		add	r3, r2, r6
		ldrb	r2, [r3]
		add	r3, r7, #15
		//add	r3, r3, #15
		ldrb	r6, [r3]
		mul	r2, r2, r6
		add	r1, r1, r2
		asr	r2, r1, #1
		add	r1, r7, #18
		//add	r1, r1, #18
		ldrh	r1, [r1]
		sub	r2, r2, r1
		add	r1, r2, #0
		strh	r1, [r0]
		add	r0, r7, #4
		add	r2, r7, #20
		//add	r2, r2, #20
		mov	r3, #0
		ldrsh	r1, [r2, r3]
		ldr	r2, .L57+8
		add	r3, r7, #16
		//add	r3, r3, #16
		ldrb	r6, [r3]
		add	r3, r6, #0
		lsl	r6, r3, #2
		add	r2, r2, r6
		ldr	r3, [r2]
		mul	r1, r1, r3
		asr	r2, r1, #16
		//asr	r1, r2, #8
		//add	r2, r1, #0
		//add	r1, r2, #0
		add	r1, r2, #53
		add	r2, r1, #0
		strh	r2, [r0]
		add	r0, r7, #4
		mov	r6, #0
		ldrsh	r1, [r0, r6]
		cmp	r1, #0
		bge	.L22	@cond_branch
		b	.L20
	.L58:
		.align	2
	.L57:
		.word	Map_Alt
		.word	-256
		.word	CamScale
	.L22:
		add	r0, r7, #4
		add	r1, r7, #2
		mov	r2, #0
		ldrsh	r0, [r0, r2]
		mov	r3, #0
		ldrsh	r1, [r1, r3]
		cmp	r0, r1
		bgt	.LCB546
		b	.L20	@long jump
	.LCB546:
		ldr	r0, .L59
		ldr	r1, .L59+4
		add	r3, r7, #8
		//add	r3, r3, #8
		mov	r6, #0
		ldrsh	r2, [r3, r6]
		add	r3, r7, #6
		str	r3, [r7, #44]
		//ldr	r6, [r7, #44]
		mov	r6, r3
		mov	r3, #0
		ldrsh	r6, [r6, r3]
		str	r6, [r7, #40]
		//ldr	r6, [r7, #40]
		asr	r3, r6, #8
		//mov	r8, r3
		//mov	r3, r8
		lsl	r6, r3, #16
		asr	r3, r6, #16
		add	r2, r2, r3
		add	r1, r1, r2
		ldrb	r4, [r1]
		add	r1, r7, #0
		add	r1, r1, #16
		ldrb	r2, [r1]
		lsr	r1, r2, #1
		add	r3, r1, #0
		lsl	r2, r3, #24
		lsr	r1, r2, #24
		sub	r4, r4, r1
		add	r4, r4, #40
		add	r1, r7, #6
		mov	r6, #0
		ldrsh	r2, [r1, r6]
		asr	r1, r2, #8
		add	r3, r1, #0
		lsl	r2, r3, #16
		asr	r1, r2, #16	// >> 16
		asr	r2, r1, #31	// >> 47
		lsr	r3, r2, #31	// >> 78
		add	r6, r1, r3	// What the hell? 

		asr	r2, r6, #1
		add	r3, r2, #0
		lsl	r2, r3, #1
		sub	r1, r1, r2
		add	r2, r7, #8
		//add	r2, r2, #8
		mov	r6, #0
		ldrsh	r3, [r2, r6]
		asr	r2, r3, #8
		add	r6, r2, #0
		lsl	r3, r6, #16
		asr	r2, r3, #16
		asr	r3, r2, #31
		lsr	r6, r3, #31
		add	r3, r2, r6
		//mov	r8, r3
		//mov	r6, r8
		asr	r3, r6, #1
		add	r6, r3, #0
		lsl	r3, r6, #1
		sub	r2, r2, r3
		lsl	r3, r1, #16
		asr	r1, r3, #16
		lsl	r3, r2, #16
		asr	r2, r3, #16
		cmp	r1, r2
		beq	.L26	@cond_branch
		add	r1, r4, #10
	//	add	r1, r1, #10
		cmp	r1, #159
		ble	.L27	@cond_branch
		b	.L24
	.L60:
		.align	2
	.L59:
		.word	Col
		.word	Map_Alt
	.L26:
		//add	r1, r4, #0
		//sub	r1, r1, #10
		sub r1, r4, #10
		cmp	r1, #159
		ble	.L27	@cond_branch
		b	.L24
	.L27:
		ldr	r1, .L61
		add	r3, r7, #8
		//add	r3, r3, #8
		mov	r6, #0
		ldrsh	r2, [r3, r6]
		add	r3, r7, #6
		str	r3, [r7, #44]
		ldr	r6, [r7, #44]
		mov	r3, #0
		ldrsh	r6, [r6, r3]
		str	r6, [r7, #40]
		//ldr	r6, [r7, #40]
		asr	r3, r6, #8
		//mov	r8, r3
		//mov	r3, r8
		lsl	r6, r3, #16
		asr	r3, r6, #16
		add	r2, r2, r3
		add	r1, r1, r2
		ldrb	r5, [r1]
		add	r1, r7, #16
		//add	r1, r1, #16
		ldrb	r2, [r1]
		lsr	r1, r2, #1
		add	r3, r1, #0
		lsl	r2, r3, #24
		lsr	r1, r2, #24
		sub	r5, r5, r1
		add	r5, r5, #40
		add	r1, r7, #6
		mov	r6, #0
		ldrsh	r2, [r1, r6]
		asr	r1, r2, #8
		add	r3, r1, #0
		lsl	r2, r3, #16
		asr	r1, r2, #16
		asr	r2, r1, #31
		lsr	r3, r2, #31
		add	r6, r1, r3
		asr	r2, r6, #1
		add	r3, r2, #0
		lsl	r2, r3, #1
		sub	r1, r1, r2
		add	r2, r7, #8
		//add	r2, r2, #8
		mov	r6, #0
		ldrsh	r3, [r2, r6]
		asr	r2, r3, #8
		add	r6, r2, #0
		lsl	r3, r6, #16
		asr	r2, r3, #16
		asr	r3, r2, #31
		lsr	r6, r3, #31
		add	r3, r2, r6
		//mov	r8, r3
		//mov	r6, r8
		mov	r6, r3
		asr	r3, r6, #1
		add	r6, r3, #0
		lsl	r3, r6, #1
		sub	r2, r2, r3
		lsl	r3, r1, #16
		asr	r1, r3, #16
		lsl	r3, r2, #16
		asr	r2, r3, #16
		cmp	r1, r2
		beq	.L28	@cond_branch
		add	r2, r5, #10
		//add	r2, r2, #10
		add	r1, r2, #0
		b	.L29
	.L62:
		.align	2
	.L61:
		.word	Map_Alt
	.L28:
		//add	r2, r5, #0
		//sub	r2, r2, #10
		sub	r2, r5, 10
		add	r1, r2, #0
	.L29:
		b	.L25
	.L24:
		mov	r1, #160
	.L25:
		//ldrb	r2, [r0]
		//mov	r3, #0
		//and	r2, r2, r3
		//add	r3, r2, #0
		//orr	r1, r1, r3
		//add	r2, r1, #0
		//strb	r2, [r0]
		strb	r1, [r0]
		mov r3, #0		// and for safety.

		add	r0, r7, #22
		//add	r0, r0, #22
		add	r1, r7, #4
		add	r2, r7, #2
		ldrh	r1, [r1]
		ldrh	r2, [r2]
		sub	r1, r1, r2
		add	r2, r1, #0
		strh	r2, [r0]
	.L30:
		add	r1, r7, #22
		//add	r1, r1, #22
		add	r0, r7, #22
		//add	r0, r0, #22
		add	r1, r7, #22
		//add	r1, r1, #22
		ldrh	r2, [r1]
		sub	r1, r2, #1
		add	r2, r1, #0
		strh	r2, [r0]
		lsl	r1, r2, #16
		asr	r0, r1, #16
		mov	r1, #1
		cmn	r0, r1
		bne	.L33	@cond_branch
		b	.L31
	.L33:
		ldr	r0, [r7, #28]
		ldr	r1, .L63
		ldrb	r2, [r1]
		strb	r2, [r0]
		ldr	r0, [r7, #28]
		add	r1, r0, #1
		str	r1, [r7, #28]
	.L32:
		b	.L30
	.L64:
		.align	2
	.L63:
		.word	Col
	.L31:
		add	r0, r7, #2
		add	r1, r7, #4
		ldrh	r2, [r1]
		strh	r2, [r0]
		add	r0, r7, #2
		mov	r2, #0
		ldrsh	r1, [r0, r2]
		cmp	r1, #105
		ble	.L20	@cond_branch
		b	.L16
	.L34:
	.L23:
	.L20:
		add	r1, r7, #16
		//add	r1, r1, #16
		add	r0, r7, #16
		//add	r0, r0, #16
		//add	r1, r7, #0
		//add	r1, r1, #16
		ldrb	r2, [r1]
		add	r1, r2, #1
		add	r2, r1, #0
		strb	r2, [r0]
		b	.L18
	.L19:
	.L16:
		add	r0, r7, #0
		add	r1, r7, #0
		ldrb	r2, [r1]
		add	r1, r2, #2
		add	r2, r1, #0
		strb	r2, [r0]
		b	.L14
	.L15:
		ldr	r0, .L65
		ldr	r2, .L65+4
		ldrb	r1, [r2]
		add	r3, r1, #0
		lsl	r2, r3, #1
		add	r2, r2, r1
		lsl	r1, r2, #2
		add	r0, r0, r1
		ldr	r1, [r0]
		str	r1, [r7, #28]
		add	r0, r7, #22
		//add	r0, r0, #22
		mov	r1, #80
		strh	r1, [r0]
	.L35:
		add	r1, r7, #22
		//add	r1, r1, #22
		add	r0, r7, #22
		//add	r0, r0, #22
		//add	r1, r7, #0
		//add	r1, r1, #22
		ldrh	r2, [r1]
		sub	r1, r2, #1
		add	r2, r1, #0
		strh	r2, [r0]
		lsl	r1, r2, #16
		asr	r0, r1, #16
		mov	r1, #1
		cmn	r0, r1
		bne	.L38	@cond_branch
		b	.L36
	.L66:
		.align	2
	.L65:
		.word	Graphics_Buffer
		.word	Graphics_ActiveScreen
	.L38:
		ldr	r0, .L67
		str	r0, [r7, #36]
		ldr	r0, [r7, #36]
		ldr	r1, [r7, #28]
		str	r1, [r0]
		ldr	r1, [r7, #36]
		add	r0, r1, #4
		ldr	r1, [r7, #28]
		add	r2, r1, #240
		//add	r2, r2, #240
		str	r2, [r0]
		ldr	r1, [r7, #36]
		add	r0, r1, #8
		//add	r0, r0, #8
		ldr	r1, .L67+4
		str	r1, [r0]
		ldr	r0, [r7, #28]
		mov	r3, #240
		lsl	r3, r3, #1
		add	r1, r0, r3
		str	r1, [r7, #28]
	.L37:
		b	.L35
	.L68:
		.align	2
	.L67:
		.word	67109076
		.word	-2147483595
	.L36:
		ldr	r0, .L69
		ldrb	r1, [r0]
		//mov	r2, #0
		//and	r1, r1, r2
		//add	r2, r1, #0
		mov	r3, #1
		//add	r1, r2, #0
		orr	r1, r1, r3
		add	r2, r1, #0
		strb	r2, [r0]
		add	r0, r7, #22
		//add	r0, r0, #22
		mov	r1, #0
		strh	r1, [r0]
	.L39:
		add	r0, r7, #22
		//add	r0, r0, #22
		mov	r6, #0
		ldrsh	r1, [r0, r6]
		cmp	r1, #99
		ble	.L42	@cond_branch
		b	.L40
	.L70:
		.align	2
	.L69:
		.word	Col
	.L42:
		add	r0, r7, #22
		//add	r0, r0, #22
		mov	r1, #0
		ldrsh	r2, [r0, r1]
		ldr	r3, .L71
		mov	r0, #90
		mov	r1, #100
		bl	Graphics_DrawHorizontal
	.L41:
		add	r0, r7, #22
		//add	r0, r0, #22
		add	r1, r7, #22
		//add	r1, r1, #22
		ldrh	r2, [r1]
		add	r1, r2, #5
		add	r2, r1, #0
		strh	r2, [r0]
		b	.L39
	.L72:
		.align	2
	.L71:
		.word	Col
	.L40:
		ldr	r0, .L73
		mov	r2, #0
		ldrsh	r1, [r0, r2]
		cmp	r1, #0
		ble	.L43	@cond_branch
		add	r0, r7, #22
		//add	r0, r0, #22
		mov	r1, #0
		strh	r1, [r0]
	.L44:
		add	r0, r7, #22
		//add	r0, r0, #22
		mov	r3, #0
		ldrsh	r6, [r0, r3]
		ldr	r0, .L73
		mov	r2, #0
		ldrsh	r1, [r0, r2]
		mov	r0, #60
		bl	__divsi3
		cmp	r6, r0
		blt	.L47	@cond_branch
		b	.L43
	.L74:
		.align	2
	.L73:
		.word	fps
	.L47:
		add	r0, r7, #22
		//add	r0, r0, #22
		mov	r3, #0
		ldrsh	r2, [r0, r3]
		ldr	r3, .L75
		mov	r0, #92
		mov	r1, #98
		bl	Graphics_DrawHorizontal
	.L46:
		add	r1, r7, #22
		//add	r1, r1, #22
		add	r0, r7, #22
		//add	r0, r0, #22
		//add	r1, r7, #0
		//add	r1, r1, #22
		ldrh	r2, [r1]
		add	r1, r2, #1
		add	r2, r1, #0
		strh	r2, [r0]
		b	.L44
	.L76:
		.align	2
	.L75:
		.word	Col
	.L45:
	.L43:
		ldr	r0, .L77
		mov	r1, #0
		ldrsb	r1, [r0, r1]
		cmp	r1, #0
		beq	.L48	@cond_branch
		add	r0, r7, #22
		//add	r0, r0, #22
		mov	r1, #150
		strh	r1, [r0]
	.L49:
		add	r0, r7, #22
		//add	r0, r0, #22
		mov	r6, #0
		ldrsh	r1, [r0, r6]
		cmp	r1, #159
		ble	.L52	@cond_branch
		b	.L48
	.L78:
		.align	2
	.L77:
		.word	method
	.L52:
		add	r0, r7, #22
		//add	r0, r0, #22
		mov	r1, #0
		ldrsh	r2, [r0, r1]
		ldr	r3, .L79
		mov	r0, #92
		mov	r1, #98
		bl	Graphics_DrawHorizontal
	.L51:
		add	r1, r7, #22
		//add	r1, r1, #22
		add	r0, r7, #22
		//add	r0, r0, #22
		//add	r1, r7, #0
		//add	r1, r1, #22	// Terminally thick compiler syndrome.
		ldrh	r2, [r1]
		add	r1, r2, #1
		add	r2, r1, #0
		strh	r2, [r0]
		b	.L49
	.L80:
		.align	2
	.L79:
		.word	Col
	.L50:
	.L48:
		bl	Graphics_SwapScreens
	.L13:
		add	sp, sp, #48
		pop	{r3}
		mov	r8, r3
		pop	{r4, r5, r6, r7, pc}
	.Lfe4:
		.size	 Dakar_Render,.Lfe4-Dakar_Render
	}
}