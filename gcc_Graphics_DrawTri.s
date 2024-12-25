.text
	.align	2
	.globl	Graphics_DrawFilledTriangle
	.type	 Graphics_DrawFilledTriangle,function
	.thumb_func
Graphics_DrawFilledTriangle:
	push	{r4, r5, r7, lr}
	add	sp, sp, #-76
	mov	r7, sp
	str	r0, [r7]
	str	r1, [r7, #4]
.L194:
	ldr	r0, .L245
	ldrb	r1, [r0]
	cmp	r1, #0
	bne	.L196	@cond_branch
	b	.L195
.L246:
	.align	2
.L245:
	.word	Graphics_TriCount
.L196:
	ldr	r0, [r7]
	ldr	r1, [r0]
	str	r1, [r7, #52]
	ldr	r1, [r7]
	add	r0, r1, #4
	ldr	r1, [r0]
	str	r1, [r7, #56]
	ldr	r1, [r7]
	add	r0, r1, #0
	add	r0, r0, #8
	ldr	r1, [r0]
	str	r1, [r7, #60]
	add	r0, r7, #0
	add	r0, r0, #58
	add	r1, r7, #0
	add	r1, r1, #54
	mov	r2, #0
	ldrsh	r0, [r0, r2]
	mov	r3, #0
	ldrsh	r1, [r1, r3]
	cmp	r0, r1
	bge	.L197	@cond_branch
	ldr	r0, [r7, #56]
	str	r0, [r7, #64]
	ldr	r0, [r7, #52]
	str	r0, [r7, #56]
	ldr	r0, [r7, #64]
	str	r0, [r7, #52]
.L197:
	add	r0, r7, #0
	add	r0, r0, #62
	add	r1, r7, #0
	add	r1, r1, #54
	mov	r4, #0
	ldrsh	r0, [r0, r4]
	mov	r5, #0
	ldrsh	r1, [r1, r5]
	cmp	r0, r1
	bge	.L198	@cond_branch
	ldr	r0, [r7, #60]
	str	r0, [r7, #64]
	ldr	r0, [r7, #52]
	str	r0, [r7, #60]
	ldr	r0, [r7, #64]
	str	r0, [r7, #52]
.L198:
	add	r0, r7, #0
	add	r0, r0, #62
	add	r1, r7, #0
	add	r1, r1, #58
	mov	r2, #0
	ldrsh	r0, [r0, r2]
	mov	r3, #0
	ldrsh	r1, [r1, r3]
	cmp	r0, r1
	bge	.L199	@cond_branch
	ldr	r0, [r7, #56]
	str	r0, [r7, #64]
	ldr	r0, [r7, #60]
	str	r0, [r7, #56]
	ldr	r0, [r7, #64]
	str	r0, [r7, #60]
.L199:
	add	r0, r7, #0
	add	r0, r0, #8
	add	r1, r7, #0
	add	r1, r1, #52
	ldrh	r2, [r1]
	strh	r2, [r0]
	add	r0, r7, #0
	add	r0, r0, #10
	add	r1, r7, #0
	add	r1, r1, #52
	ldrh	r2, [r1]
	strh	r2, [r0]
	add	r0, r7, #0
	add	r0, r0, #58
	add	r1, r7, #0
	add	r1, r1, #54
	mov	r4, #0
	ldrsh	r0, [r0, r4]
	mov	r5, #0
	ldrsh	r1, [r1, r5]
	cmp	r0, r1
	bne	.L200	@cond_branch
	add	r0, r7, #0
	add	r0, r0, #14
	mov	r1, #0
	strh	r1, [r0]
	add	r0, r7, #0
	add	r0, r0, #8
	add	r1, r7, #0
	add	r1, r1, #56
	ldrh	r2, [r1]
	strh	r2, [r0]
	b	.L201
.L200:
	add	r4, r7, #0
	add	r4, r4, #14
	add	r1, r7, #0
	add	r1, r1, #56
	mov	r2, #0
	ldrsh	r0, [r1, r2]
	add	r1, r7, #0
	add	r1, r1, #52
	mov	r3, #0
	ldrsh	r2, [r1, r3]
	sub	r1, r0, r2
	lsl	r0, r1, #8
	add	r2, r7, #0
	add	r2, r2, #58
	mov	r5, #0
	ldrsh	r1, [r2, r5]
	add	r2, r7, #0
	add	r2, r2, #54
	mov	r5, #0
	ldrsh	r3, [r2, r5]
	sub	r1, r1, r3
	bl	__divsi3
	add	r1, r0, #0
	strh	r1, [r4]
.L201:
	add	r0, r7, #0
	add	r0, r0, #62
	add	r1, r7, #0
	add	r1, r1, #54
	mov	r2, #0
	ldrsh	r0, [r0, r2]
	mov	r3, #0
	ldrsh	r1, [r1, r3]
	cmp	r0, r1
	bne	.L202	@cond_branch
	add	r0, r7, #0
	add	r0, r0, #16
	mov	r1, #0
	strh	r1, [r0]
	add	r0, r7, #0
	add	r0, r0, #10
	add	r1, r7, #0
	add	r1, r1, #60
	ldrh	r2, [r1]
	strh	r2, [r0]
	b	.L203
.L202:
	add	r4, r7, #0
	add	r4, r4, #16
	add	r1, r7, #0
	add	r1, r1, #60
	mov	r5, #0
	ldrsh	r0, [r1, r5]
	add	r1, r7, #0
	add	r1, r1, #52
	mov	r3, #0
	ldrsh	r2, [r1, r3]
	sub	r1, r0, r2
	lsl	r0, r1, #8
	add	r2, r7, #0
	add	r2, r2, #62
	mov	r5, #0
	ldrsh	r1, [r2, r5]
	add	r2, r7, #0
	add	r2, r2, #54
	mov	r5, #0
	ldrsh	r3, [r2, r5]
	sub	r1, r1, r3
	bl	__divsi3
	add	r1, r0, #0
	strh	r1, [r4]
.L203:
	mov	r0, #0
	str	r0, [r7, #20]
	mov	r0, #0
	str	r0, [r7, #24]
	add	r0, r7, #0
	add	r0, r0, #14
	mov	r2, #0
	ldrsh	r1, [r0, r2]
	cmp	r1, #0
	bge	.L204	@cond_branch
	add	r0, r7, #0
	add	r0, r0, #28
	mov	r3, #1
	neg	r3, r3
	add	r1, r3, #0
	strh	r1, [r0]
	b	.L205
.L204:
	add	r0, r7, #0
	add	r0, r0, #28
	mov	r1, #1
	strh	r1, [r0]
.L205:
	add	r0, r7, #0
	add	r0, r0, #16
	mov	r4, #0
	ldrsh	r1, [r0, r4]
	cmp	r1, #0
	bge	.L206	@cond_branch
	add	r0, r7, #0
	add	r0, r0, #30
	mov	r5, #1
	neg	r5, r5
	add	r1, r5, #0
	strh	r1, [r0]
	b	.L207
.L206:
	add	r0, r7, #0
	add	r0, r0, #30
	mov	r1, #1
	strh	r1, [r0]
.L207:
	add	r0, r7, #0
	add	r0, r0, #14
	add	r1, r7, #0
	add	r1, r1, #14
	mov	r3, #0
	ldrsh	r2, [r1, r3]
	add	r1, r2, #0
	cmp	r1, #0
	bge	.L208	@cond_branch
	neg	r1, r1
.L208:
	strh	r1, [r0]
	add	r0, r7, #0
	add	r0, r0, #16
	add	r1, r7, #0
	add	r1, r1, #16
	mov	r4, #0
	ldrsh	r2, [r1, r4]
	add	r1, r2, #0
	cmp	r1, #0
	bge	.L209	@cond_branch
	neg	r1, r1
.L209:
	strh	r1, [r0]
	add	r0, r7, #0
	add	r0, r0, #42
	ldr	r1, [r7, #4]
	ldrb	r3, [r1]
	add	r2, r3, #0
	lsl	r1, r2, #8
	ldr	r2, [r7, #4]
	ldrb	r3, [r2]
	add	r2, r3, #0
	orr	r2, r2, r1
	add	r1, r2, #0
	strh	r1, [r0]
	add	r0, r7, #0
	add	r0, r0, #12
	add	r1, r7, #0
	add	r1, r1, #54
	ldrh	r2, [r1]
	strh	r2, [r0]
.L210:
	add	r0, r7, #0
	add	r0, r0, #12
	add	r1, r7, #0
	add	r1, r1, #58
	mov	r5, #0
	ldrsh	r0, [r0, r5]
	mov	r2, #0
	ldrsh	r1, [r1, r2]
	cmp	r0, r1
	blt	.L213	@cond_branch
	b	.L211
.L213:
	add	r0, r7, #0
	add	r0, r0, #14
	mov	r3, #0
	ldrsh	r1, [r0, r3]
	ldr	r0, [r7, #20]
	add	r1, r0, r1
	str	r1, [r7, #20]
.L214:
	ldr	r0, [r7, #20]
	cmp	r0, #255
	bgt	.L216	@cond_branch
	b	.L215
.L216:
	add	r0, r7, #0
	add	r0, r0, #8
	add	r1, r7, #0
	add	r1, r1, #8
	add	r2, r7, #0
	add	r2, r2, #28
	ldrh	r1, [r1]
	ldrh	r2, [r2]
	add	r1, r1, r2
	add	r2, r1, #0
	strh	r2, [r0]
	ldr	r0, [r7, #20]
	ldr	r4, .L247
	add	r1, r0, r4
	str	r1, [r7, #20]
	b	.L214
.L248:
	.align	2
.L247:
	.word	-256
.L215:
	add	r0, r7, #0
	add	r0, r0, #16
	mov	r5, #0
	ldrsh	r1, [r0, r5]
	ldr	r0, [r7, #24]
	add	r1, r0, r1
	str	r1, [r7, #24]
.L217:
	ldr	r0, [r7, #24]
	cmp	r0, #255
	bgt	.L219	@cond_branch
	b	.L218
.L219:
	add	r0, r7, #0
	add	r0, r0, #10
	add	r1, r7, #0
	add	r1, r1, #10
	add	r2, r7, #0
	add	r2, r2, #30
	ldrh	r1, [r1]
	ldrh	r2, [r2]
	add	r1, r1, r2
	add	r2, r1, #0
	strh	r2, [r0]
	ldr	r0, [r7, #24]
	ldr	r2, .L249
	add	r1, r0, r2
	str	r1, [r7, #24]
	b	.L217
.L250:
	.align	2
.L249:
	.word	-256
.L218:
	add	r0, r7, #0
	add	r0, r0, #48
	add	r1, r7, #0
	add	r1, r1, #12
	ldrh	r2, [r1]
	strh	r2, [r0]
	add	r0, r7, #0
	add	r0, r0, #8
	add	r1, r7, #0
	add	r1, r1, #10
	mov	r3, #0
	ldrsh	r0, [r0, r3]
	mov	r4, #0
	ldrsh	r1, [r1, r4]
	cmp	r0, r1
	ble	.L220	@cond_branch
	add	r0, r7, #0
	add	r0, r0, #44
	add	r1, r7, #0
	add	r1, r1, #10
	ldrh	r2, [r1]
	strh	r2, [r0]
	add	r0, r7, #0
	add	r0, r0, #40
	add	r1, r7, #0
	add	r1, r1, #8
	add	r2, r7, #0
	add	r2, r2, #10
	ldrh	r1, [r1]
	ldrh	r2, [r2]
	sub	r1, r1, r2
	add	r2, r1, #0
	strh	r2, [r0]
	b	.L221
.L220:
	add	r0, r7, #0
	add	r0, r0, #44
	add	r1, r7, #0
	add	r1, r1, #8
	ldrh	r2, [r1]
	strh	r2, [r0]
	add	r0, r7, #0
	add	r0, r0, #40
	add	r1, r7, #0
	add	r1, r1, #10
	add	r2, r7, #0
	add	r2, r2, #8
	ldrh	r1, [r1]
	ldrh	r2, [r2]
	sub	r1, r1, r2
	add	r2, r1, #0
	strh	r2, [r0]
.L221:
	add	r0, r7, #0
	add	r0, r0, #40
	ldrh	r1, [r0]
	cmp	r1, #0
	bne	.L222	@cond_branch
	b	.L212
.L222:
	add	r0, r7, #0
	add	r0, r0, #40
	ldrh	r1, [r0]
	mov	r2, #1
	add	r0, r1, #0
	and	r0, r0, r2
	add	r2, r0, #0
	lsl	r1, r2, #16
	lsr	r0, r1, #16
	cmp	r0, #0
	beq	.L223	@cond_branch
	add	r1, r7, #0
	add	r1, r1, #40
	add	r0, r7, #0
	add	r0, r0, #40
	add	r1, r7, #0
	add	r1, r1, #40
	ldrh	r2, [r1]
	add	r1, r2, #1
	add	r2, r1, #0
	strh	r2, [r0]
.L223:
	ldr	r0, .L251
	ldr	r2, .L251+4
	ldrb	r1, [r2]
	add	r3, r1, #0
	lsl	r2, r3, #1
	add	r2, r2, r1
	lsl	r1, r2, #2
	add	r0, r0, r1
	ldr	r1, .L251
	ldr	r3, .L251+4
	ldrb	r2, [r3]
	add	r4, r2, #0
	lsl	r3, r4, #1
	add	r3, r3, r2
	lsl	r2, r3, #2
	add	r3, r1, r2
	ldrb	r1, [r3, #5]
	add	r2, r7, #0
	add	r2, r2, #48
	mov	r5, #0
	ldrsh	r3, [r2, r5]
	mul	r1, r1, r3
	add	r2, r7, #0
	add	r2, r2, #44
	mov	r4, #0
	ldrsh	r3, [r2, r4]
	add	r1, r1, r3
	ldr	r0, [r0]
	add	r1, r0, r1
	str	r1, [r7, #36]
	ldr	r0, [r7, #36]
	mov	r1, #1
	and	r0, r0, r1
	cmp	r0, #0
	beq	.L224	@cond_branch
	ldr	r0, [r7, #36]
	sub	r1, r0, #1
	str	r1, [r7, #36]
.L224:
	add	r0, r7, #0
	add	r0, r0, #68
	add	r1, r7, #0
	add	r1, r1, #42
	ldrh	r2, [r1]
	strh	r2, [r0]
	ldr	r0, .L251+8
	str	r0, [r7, #72]
	ldr	r0, [r7, #72]
	add	r1, r7, #0
	add	r1, r1, #68
	str	r1, [r0]
	ldr	r1, [r7, #72]
	add	r0, r1, #4
	ldr	r1, [r7, #36]
	str	r1, [r0]
	ldr	r1, [r7, #72]
	add	r0, r1, #0
	add	r0, r0, #8
	add	r1, r7, #0
	add	r1, r1, #40
	ldrh	r2, [r1]
	lsr	r1, r2, #1
	add	r3, r1, #0
	lsl	r2, r3, #16
	lsr	r1, r2, #16
	mov	r2, #129
	lsl	r2, r2, #24
	orr	r1, r1, r2
	str	r1, [r0]
.L212:
	add	r1, r7, #0
	add	r1, r1, #12
	add	r0, r7, #0
	add	r0, r0, #12
	add	r1, r7, #0
	add	r1, r1, #12
	ldrh	r2, [r1]
	add	r1, r2, #1
	add	r2, r1, #0
	strh	r2, [r0]
	b	.L210
	.L252:
	.align	2
.L251:
	.word	Graphics_Buffer
	.word	Graphics_ActiveScreen
	.word	67109076
.L211:
	add	r0, r7, #0
	add	r0, r0, #62
	add	r1, r7, #0
	add	r1, r1, #58
	mov	r5, #0
	ldrsh	r0, [r0, r5]
	mov	r2, #0
	ldrsh	r1, [r1, r2]
	cmp	r0, r1
	bne	.L225	@cond_branch
	add	r0, r7, #0
	add	r0, r0, #14
	mov	r1, #0
	strh	r1, [r0]
	add	r0, r7, #0
	add	r0, r0, #8
	add	r1, r7, #0
	add	r1, r1, #60
	ldrh	r2, [r1]
	strh	r2, [r0]
	b	.L226
.L225:
	add	r4, r7, #0
	add	r4, r4, #14
	add	r1, r7, #0
	add	r1, r1, #60
	mov	r3, #0
	ldrsh	r0, [r1, r3]
	add	r1, r7, #0
	add	r1, r1, #56
	mov	r5, #0
	ldrsh	r2, [r1, r5]
	sub	r1, r0, r2
	lsl	r0, r1, #8
	add	r2, r7, #0
	add	r2, r2, #62
	mov	r3, #0
	ldrsh	r1, [r2, r3]
	add	r2, r7, #0
	add	r2, r2, #58
	mov	r5, #0
	ldrsh	r3, [r2, r5]
	sub	r1, r1, r3
	bl	__divsi3
	add	r1, r0, #0
	strh	r1, [r4]
	add	r0, r7, #0
	add	r0, r0, #8
	add	r1, r7, #0
	add	r1, r1, #56
	ldrh	r2, [r1]
	strh	r2, [r0]
	add	r0, r7, #0
	add	r0, r0, #14
	mov	r2, #0
	ldrsh	r1, [r0, r2]
	cmp	r1, #0
	bge	.L227	@cond_branch
	add	r0, r7, #0
	add	r0, r0, #28
	mov	r3, #1
	neg	r3, r3
	add	r1, r3, #0
	strh	r1, [r0]
	b	.L228
.L227:
	add	r0, r7, #0
	add	r0, r0, #28
	mov	r1, #1
	strh	r1, [r0]
.L228:
	add	r0, r7, #0
	add	r0, r0, #14
	add	r1, r7, #0
	add	r1, r1, #14
	mov	r4, #0
	ldrsh	r2, [r1, r4]
	add	r1, r2, #0
	cmp	r1, #0
	bge	.L229	@cond_branch
	neg	r1, r1
.L229:
	strh	r1, [r0]
.L226:
	mov	r0, #0
	str	r0, [r7, #20]
	add	r0, r7, #0
	add	r0, r0, #12
	add	r1, r7, #0
	add	r1, r1, #58
	ldrh	r2, [r1]
	strh	r2, [r0]
.L230:
	add	r0, r7, #0
	add	r0, r0, #12
	add	r1, r7, #0
	add	r1, r1, #62
	mov	r5, #0
	ldrsh	r0, [r0, r5]
	mov	r2, #0
	ldrsh	r1, [r1, r2]
	cmp	r0, r1
	blt	.L233	@cond_branch
	b	.L231
.L233:
	add	r0, r7, #0
	add	r0, r0, #14
	mov	r3, #0
	ldrsh	r1, [r0, r3]
	ldr	r0, [r7, #20]
	add	r1, r0, r1
	str	r1, [r7, #20]
.L234:
	ldr	r0, [r7, #20]
	cmp	r0, #255
	bgt	.L236	@cond_branch
	b	.L235
.L236:
	add	r0, r7, #0
	add	r0, r0, #8
	add	r1, r7, #0
	add	r1, r1, #8
	add	r2, r7, #0
	add	r2, r2, #28
	ldrh	r1, [r1]
	ldrh	r2, [r2]
	add	r1, r1, r2
	add	r2, r1, #0
	strh	r2, [r0]
	ldr	r0, [r7, #20]
	ldr	r4, .L253
	add	r1, r0, r4
	str	r1, [r7, #20]
	b	.L234
.L254:
	.align	2
.L253:
	.word	-256
.L235:
	add	r0, r7, #0
	add	r0, r0, #16
	mov	r5, #0
	ldrsh	r1, [r0, r5]
	ldr	r0, [r7, #24]
	add	r1, r0, r1
	str	r1, [r7, #24]
.L237:
	ldr	r0, [r7, #24]
	cmp	r0, #255
	bgt	.L239	@cond_branch
	b	.L238
.L239:
	add	r0, r7, #0
	add	r0, r0, #10
	add	r1, r7, #0
	add	r1, r1, #10
	add	r2, r7, #0
	add	r2, r2, #30
	ldrh	r1, [r1]
	ldrh	r2, [r2]
	add	r1, r1, r2
	add	r2, r1, #0
	strh	r2, [r0]
	ldr	r0, [r7, #24]
	ldr	r2, .L255
	add	r1, r0, r2
	str	r1, [r7, #24]
	b	.L237
.L256:
	.align	2
.L255:
	.word	-256
.L238:
	add	r0, r7, #0
	add	r0, r0, #48
	add	r1, r7, #0
	add	r1, r1, #12
	ldrh	r2, [r1]
	strh	r2, [r0]
	add	r0, r7, #0
	add	r0, r0, #8
	add	r1, r7, #0
	add	r1, r1, #10
	mov	r3, #0
	ldrsh	r0, [r0, r3]
	mov	r4, #0
	ldrsh	r1, [r1, r4]
	cmp	r0, r1
	ble	.L240	@cond_branch
	add	r0, r7, #0
	add	r0, r0, #44
	add	r1, r7, #0
	add	r1, r1, #10
	ldrh	r2, [r1]
	strh	r2, [r0]
	add	r0, r7, #0
	add	r0, r0, #40
	add	r1, r7, #0
	add	r1, r1, #8
	add	r2, r7, #0
	add	r2, r2, #10
	ldrh	r1, [r1]
	ldrh	r2, [r2]
	sub	r1, r1, r2
	add	r2, r1, #0
	strh	r2, [r0]
	b	.L241
.L240:
	add	r0, r7, #0
	add	r0, r0, #44
	add	r1, r7, #0
	add	r1, r1, #8
	ldrh	r2, [r1]
	strh	r2, [r0]
	add	r0, r7, #0
	add	r0, r0, #40
	add	r1, r7, #0
	add	r1, r1, #10
	add	r2, r7, #0
	add	r2, r2, #8
	ldrh	r1, [r1]
	ldrh	r2, [r2]
	sub	r1, r1, r2
	add	r2, r1, #0
	strh	r2, [r0]
.L241:
	add	r0, r7, #0
	add	r0, r0, #40
	ldrh	r1, [r0]
	cmp	r1, #0
	bne	.L242	@cond_branch
	b	.L232
.L242:
	add	r0, r7, #0
	add	r0, r0, #40
	ldrh	r1, [r0]
	mov	r2, #1
	add	r0, r1, #0
	and	r0, r0, r2
	add	r2, r0, #0
	lsl	r1, r2, #16
	lsr	r0, r1, #16
	cmp	r0, #0
	beq	.L243	@cond_branch
	add	r1, r7, #0
	add	r1, r1, #40
	add	r0, r7, #0
	add	r0, r0, #40
	add	r1, r7, #0
	add	r1, r1, #40
	ldrh	r2, [r1]
	add	r1, r2, #1
	add	r2, r1, #0
	strh	r2, [r0]
.L243:
	ldr	r0, .L257
	ldr	r2, .L257+4
	ldrb	r1, [r2]
	add	r3, r1, #0
	lsl	r2, r3, #1
	add	r2, r2, r1
	lsl	r1, r2, #2
	add	r0, r0, r1
	ldr	r1, .L257
	ldr	r3, .L257+4
	ldrb	r2, [r3]
	add	r4, r2, #0
	lsl	r3, r4, #1
	add	r3, r3, r2
	lsl	r2, r3, #2
	add	r3, r1, r2
	ldrb	r1, [r3, #5]
	add	r2, r7, #0
	add	r2, r2, #48
	mov	r5, #0
	ldrsh	r3, [r2, r5]
	mul	r1, r1, r3
	add	r2, r7, #0
	add	r2, r2, #44
	mov	r4, #0
	ldrsh	r3, [r2, r4]
	add	r1, r1, r3
	ldr	r0, [r0]
	add	r1, r0, r1
	str	r1, [r7, #36]
	ldr	r0, [r7, #36]
	mov	r1, #1
	and	r0, r0, r1
	cmp	r0, #0
	beq	.L244	@cond_branch
	ldr	r0, [r7, #36]
	sub	r1, r0, #1
	str	r1, [r7, #36]
.L244:
	add	r0, r7, #0
	add	r0, r0, #68
	add	r1, r7, #0
	add	r1, r1, #42
	ldrh	r2, [r1]
	strh	r2, [r0]
	ldr	r0, .L257+8
	str	r0, [r7, #72]
	ldr	r0, [r7, #72]
	add	r1, r7, #0
	add	r1, r1, #68
	str	r1, [r0]
	ldr	r1, [r7, #72]
	add	r0, r1, #4
	ldr	r1, [r7, #36]
	str	r1, [r0]
	ldr	r1, [r7, #72]
	add	r0, r1, #0
	add	r0, r0, #8
	add	r1, r7, #0
	add	r1, r1, #40
	ldrh	r2, [r1]
	lsr	r1, r2, #1
	add	r3, r1, #0
	lsl	r2, r3, #16
	lsr	r1, r2, #16
	mov	r2, #129
	lsl	r2, r2, #24
	orr	r1, r1, r2
	str	r1, [r0]
.L232:
	add	r1, r7, #0
	add	r1, r1, #12
	add	r0, r7, #0
	add	r0, r0, #12
	add	r1, r7, #0
	add	r1, r1, #12
	ldrh	r2, [r1]
	add	r1, r2, #1
	add	r2, r1, #0
	strh	r2, [r0]
	b	.L230
.L258:
	.align	2
.L257:
	.word	Graphics_Buffer
	.word	Graphics_ActiveScreen
	.word	67109076
.L231:
	ldr	r0, [r7]
	add	r1, r0, #0
	add	r1, r1, #12
	str	r1, [r7]
	ldr	r0, [r7, #4]
	add	r1, r0, #4
	str	r1, [r7, #4]
	ldr	r1, .L259
	ldr	r0, .L259
	ldr	r1, .L259
	ldrb	r2, [r1]
	sub	r1, r2, #1
	add	r2, r1, #0
	strb	r2, [r0]
	b	.L194
.L260:
	.align	2
.L259:
	.word	Graphics_TriCount
.L195:
.L193:
	add	sp, sp, #76
	pop	{r4, r5, r7, pc}
.Lfe17:
	.size	 Graphics_DrawFilledTriangle,.Lfe17-Graphics_DrawFilledTriangle
	.section .rodata
	.align	2
.LC55:
	.word	Graphics_Buffer
	.align	2
.LC56:
	.word	Graphics_ActiveScreen