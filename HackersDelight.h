// Optimized division by a constant
// Jose Gama June, 2015
// Assembly code based on the C code from:
// Henry S. Warren, 2012
// Hacker's Delight 2nd ed
// Addison-Wesley Professional


uint16_t divu1000hd(uint16_t dividend)
{
uint16_t result;
__asm__ __volatile__ (
 "	movw r20, %A1	 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" /* (n >> 1)*/ \
 "	movw %A0, r20	 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" /* (n >> 7)*/ \
 "	movw r22, r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" /* (n >> 8)*/ \
 "	add  r22, r20 \n\t" /* t = (n >> 7) + (n >> 8)*/ \
 "	adc r23, r21 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" /* (n >> 12)*/ \
 "	add r22, r20 \n\t" /* t = (n >> 7) + (n >> 8) + (n >> 12)*/ \
 "	adc r23, r21	 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20	 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" /* (n >> 15)	*/ \
 "	add %A0, r20 \n\t" /* q = (n >> 1) + (n >> 15)*/ \
 "	adc %B0, r21 \n\t" \
 "	add %A0, r22 \n\t" \
 "	adc %B0, r23  ; q = ... + t \n\t" \
 "	lsr r23 \n\t" \
 "	ror r22 \n\t" \
 "	lsr r23 \n\t" \
 "	ror r22 \n\t" \
 "	lsr r23 \n\t" \
 "	ror r22 \n\t" \
 "	lsr r23 \n\t" \
 "	ror r22 \n\t" \
 "	lsr r23 \n\t" \
 "	ror r22 \n\t" \
 "	lsr r23 \n\t" \
 "	ror r22 \n\t" \
 "	lsr r23 \n\t" \
 "	ror r22 \n\t" \
 "	lsr r23 \n\t" \
 "	ror r22 \n\t" \
 "	lsr r23 \n\t" \
 "	ror r22 \n\t" \
 "	lsr r23 \n\t" \
 "	ror r22 \n\t" \
 "	lsr r23 \n\t" \
 "	ror r22 \n\t" \
 "	add %A0, r22 \n\t" \
 "	adc %B0, r23  ; q = ... + (t >> 11) \n\t" \
 "	lsr r23 \n\t" \
 "	ror r22 \n\t" \
 "	lsr r23 \n\t" \
 "	ror r22 \n\t" \
 "	lsr r23 \n\t" \
 "	ror r22 \n\t" \
 "	add %A0, r22 \n\t" \
 "	adc %B0, r23  ; q = ... + (t >> 14)	 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" /* q >> 9*/ \
 "	movw r20, %A0 \n\t" \
 "	movw r22, r20 \n\t" \
 "	lsl r22 \n\t" \
 "	rol r23 \n\t" \
 "	lsl r22 \n\t" \
 "	rol r23 \n\t" \
 "	lsl r22 \n\t" \
 "	rol r23  ; q*8 \n\t" \
 "	movw r0, r22 \n\t" \
 "	lsl r22 \n\t" \
 "	rol r23  ; q*16 \n\t" \
 "	add  r0, r22 \n\t" \
 "	adc  r1, r23	 \n\t" \
 "	lsl r22 \n\t" \
 "	rol r23 \n\t" \
 "	lsl r22 \n\t" \
 "	rol r23 \n\t" \
 "	lsl r22 \n\t" \
 "	rol r23 \n\t" \
 "	lsl r22 \n\t" \
 "	rol r23 \n\t" \
 "	lsl r22 \n\t" \
 "	rol r23 \n\t" \
 "	lsl r22 \n\t" \
 "	rol r23  ; q*1024 \n\t" \
 "	sub  r22, r0 \n\t" \
 "	sbc  r23, r1	  ; q*1024 - q*8 - q*16 = q*1000	 \n\t" \
 "	sub %A1, r22 \n\t" \
 "	sbc %B1, r23 \n\t" /* r = n - q*1000*/ \
 "	ldi r20, 24 \n\t" \
 "	add %A1, r20 \n\t" \
 "	adc %B1, r1	 ; r = r+24 \n\t" \
 "	asr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	asr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	asr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	asr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	asr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	asr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	asr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	asr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	asr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	asr %B1 \n\t" \
 "	ror %A1 \n\t" /* r >> 10*/ \
 "	add %A0, %A1 \n\t" \
 "	adc %B0, %B1 \n\t" /* from above => q + ((r+24) >> 10)*/ \
 "	clr r1 \n\t" \
: "=&a" (result) \
: "a" (dividend) \
: "r20", "r21", "r22", "r23"  \
);
return result;
}

uint16_t divu100hd(uint16_t dividend)
{
uint16_t result;
__asm__ __volatile__ (
 "	movw r20, %A1 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" /* (n >> 1)*/ \
 "	movw %A0, r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" /* (n >> 3)*/ \
 "	add	%A0, r20 \n\t" /* q = (n >> 1) + (n >> 3)*/ \
 "	adc %B0, r21 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" /* (n >> 6)*/ \
 "	add	%A0, r20 \n\t" /* q = (n >> 1) + (n >> 3) + (n >> 6)*/ \
 "	adc %B0, r21 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" /* (n >> 10)*/ \
 "	sub	%A0, r20 \n\t" /* q = ... - (n >> 10)*/ \
 "	sbc %B0, r21 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" /* (n >> 12)*/ \
 "	add	%A0, r20 \n\t" /* q = ... + (n >> 12)*/ \
 "	adc %B0, r21 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" /* (n >> 13)*/ \
 "	add	%A0, r20 \n\t" /* q = ... + (n >> 13)*/ \
 "	adc %B0, r21 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0		 ; q >> 6 \n\t" \
 "	movw r20, %A0 \n\t" \
 "	lsl r20 \n\t" \
 "	rol r21 \n\t" \
 "	lsl r20 \n\t" \
 "	rol r21 \n\t" \
 "	movw r22, r20	  ; q*4 \n\t" \
 "	lsl r20 \n\t" \
 "	rol r21 \n\t" \
 "	lsl r20 \n\t" \
 "	rol r21 \n\t" \
 "	lsl r20 \n\t" \
 "	rol r21 \n\t" \
 "	add  r22, r20 \n\t" \
 "	adc  r23, r21	  ; q*4 + q*32 \n\t" \
 "	lsl r20 \n\t" \
 "	rol r21 \n\t" \
 "	add  r22, r20 \n\t" \
 "	adc  r23, r21	  ; q*4 + q*32 + q*64 = q*100 \n\t" \
 "	sub %A1, r22 \n\t" \
 "	sbc %B1, r23 \n\t" /* r = n - q*100*/ \
 "	ldi r20, 28 \n\t" \
 "	add %A1, r20 \n\t" \
 "	adc %B1, r1	 ; r = r+28 \n\t" \
 "	asr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	asr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	asr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	asr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	asr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	asr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	asr %B1 \n\t" \
 "	ror %A1 \n\t" /* r >> 7*/ \
 "	add %A0, %A1 \n\t" \
 "	adc %B0, %B1 \n\t" /* from above => q + ((r+28) >> 7)*/ \
"	clr r1 \n\t" \
: "=&a" (result) \
: "a" (dividend) \
: "r20", "r21", "r22", "r23"  \
);
return result;
}

uint16_t divu11hd(uint16_t dividend)
{
uint16_t result;
__asm__ __volatile__ (
"	movw r20, %A1 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" /* (n >> 1)*/ \
 "	movw %A0, r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" /* (n >> 2)*/ \
 "	add	%A0, r20 \n\t" /* q = (n >> 1) + (n >> 2)*/ \
 "	adc %B0, r21 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" /* (n >> 5)	*/ \
 "	sub %A0, r20 \n\t" \
 "	sbc %B0, r21 \n\t" /* n - (n >> 5)*/ \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" /* (n >> 7)	*/ \
 "	add	%A0, r20 \n\t" /* q + (n >> 7)*/ \
 "	adc %B0, r21	 \n\t" \
 "	movw r20, %A0 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" /* (q >> 10)*/ \
 "	add %A0, r20 \n\t" \
 "	adc %B0, r21 \n\t" /* q = q + (q >> 10)*/ \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" /* (q >> 3)	*/ \
 "	sub %A1, %A0 \n\t" \
 "	sbc %B1, %B0 \n\t" \
 "	sub %A1, %A0 \n\t" \
 "	sbc %B1, %B0 \n\t" \
 "	sub %A1, %A0 \n\t" \
 "	sbc %B1, %B0 \n\t" \
 "	sub %A1, %A0 \n\t" \
 "	sbc %B1, %B0 \n\t" \
 "	sub %A1, %A0 \n\t" \
 "	sbc %B1, %B0 \n\t" \
 "	sub %A1, %A0 \n\t" \
 "	sbc %B1, %B0 \n\t" \
 "	sub %A1, %A0 \n\t" \
 "	sbc %B1, %B0 \n\t" \
 "	sub %A1, %A0 \n\t" \
 "	sbc %B1, %B0 \n\t" \
 "	sub %A1, %A0 \n\t" \
 "	sbc %B1, %B0 \n\t" \
 "	sub %A1, %A0 \n\t" \
 "	sbc %B1, %B0 \n\t" \
 "	sub %A1, %A0 \n\t" \
 "	sbc %B1, %B0 \n\t" /* r = n - q*11*/ \
 "	ldi r20, 5 \n\t" \
 "	add %A1, r20 \n\t" \
 "	adc %B1, r1	 ; r = r+5 \n\t" \
 "	lsr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	lsr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	lsr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	lsr %B1 \n\t" \
 "	ror %A1 \n\t" /* r >> 4*/ \
 "	add %A0, %A1 \n\t" \
 "	adc %B0, %B1 \n\t" /* from above => q + ((r+5) >> 4)*/ \
"	clr r1 \n\t" \
: "=&a" (result) \
: "a" (dividend) \
: "r20", "r21" \
);
return result;
}

uint16_t divu12hd(uint16_t dividend)
{
uint16_t result;
__asm__ __volatile__ (
 "	movw r20, %A1 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" /* (n >> 1)*/ \
 "	movw %A0, r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" /* (n >> 3)*/ \
 "	add	%A0, r20 \n\t" /* q = (n >> 1) + (n >> 3)*/ \
 "	adc %B0, r21 \n\t" \
 "	movw r20, %A0 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" /* (q >> 4)*/ \
 "	add %A0, r20 \n\t" \
 "	adc %B0, r21 \n\t" /* q = q + (q >> 4)*/ \
 "	movw r20, %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" /* (q >> 8)	*/ \
 "	add %A0, r20 \n\t" \
 "	adc %B0, r21 \n\t" /* q = q + (q >> 8)*/ \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" /* q >> 3*/ \
 "	sub %A1, %A0 \n\t" \
 "	sbc %B1, %B0 \n\t" \
 "	sub %A1, %A0 \n\t" \
 "	sbc %B1, %B0 \n\t" \
 "	sub %A1, %A0 \n\t" \
 "	sbc %B1, %B0 \n\t" \
 "	sub %A1, %A0 \n\t" \
 "	sbc %B1, %B0 \n\t" \
 "	sub %A1, %A0 \n\t" \
 "	sbc %B1, %B0 \n\t" \
 "	sub %A1, %A0 \n\t" \
 "	sbc %B1, %B0 \n\t" \
 "	sub %A1, %A0 \n\t" \
 "	sbc %B1, %B0 \n\t" \
 "	sub %A1, %A0 \n\t" \
 "	sbc %B1, %B0 \n\t" \
 "	sub %A1, %A0 \n\t" \
 "	sbc %B1, %B0 \n\t" \
 "	sub %A1, %A0 \n\t" \
 "	sbc %B1, %B0 \n\t" \
 "	sub %A1, %A0 \n\t" \
 "	sbc %B1, %B0 \n\t" \
 "	sub %A1, %A0 \n\t" \
 "	sbc %B1, %B0 \n\t" /* r = n - q*12*/ \
 "	ldi r20, 4 \n\t" \
 "	add %A1, r20 \n\t" \
 "	adc %B1, r1	 ; r = r+4 \n\t" \
 "	lsr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	lsr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	lsr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	lsr %B1 \n\t" \
 "	ror %A1 \n\t" /* r >> 4*/ \
 "	add %A0, %A1 \n\t" \
 "	adc %B0, %B1 \n\t" /* from above => q + ((r+4) >> 4)*/ \
"	clr r1 \n\t" \
: "=&a" (result) \
: "a" (dividend) \
: "r20", "r21" \
);
return result;
}

uint16_t divu13hd(uint16_t dividend)
{
uint16_t result;
__asm__ __volatile__ (
 "	movw r20, %A1 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" /* (n >> 1)*/ \
 "	movw %A0, r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" /* (n >> 4)*/ \
 "	add   %A0, r20 \n\t" /* q = (n >> 1) + (n >> 4)*/ \
 "	adc %B0, r21 \n\t" \
 "	movw r20, %A0 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" /* (q >> 4)*/ \
 "	add %A0, r20 \n\t" \
 "	adc %B0, r21 \n\t" /* q = q + (q >> 4)*/ \
 "	movw r20, %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" /* (q >> 5)	*/ \
 "	add %A0, r20 \n\t" \
 "	adc %B0, r21 \n\t" /* q = q + (q >> 5)*/ \
 "	movw r20, %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" /* (q >> 12)	*/ \
 "	add %A0, r20 \n\t" \
 "	adc %B0, r21 \n\t" /* q = q + (q >> 12)	*/ \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0             ; q >> 3 \n\t" \
 "	sub %A1, %A0 \n\t" \
 "	sbc %B1, %B0 \n\t" \
 "	sub %A1, %A0 \n\t" \
 "	sbc %B1, %B0 \n\t" \
 "	sub %A1, %A0 \n\t" \
 "	sbc %B1, %B0 \n\t" \
 "	sub %A1, %A0 \n\t" \
 "	sbc %B1, %B0 \n\t" \
 "	sub %A1, %A0 \n\t" \
 "	sbc %B1, %B0 \n\t" \
 "	sub %A1, %A0 \n\t" \
 "	sbc %B1, %B0 \n\t" \
 "	sub %A1, %A0 \n\t" \
 "	sbc %B1, %B0 \n\t" \
 "	sub %A1, %A0 \n\t" \
 "	sbc %B1, %B0 \n\t" \
 "	sub %A1, %A0 \n\t" \
 "	sbc %B1, %B0 \n\t" \
 "	sub %A1, %A0 \n\t" \
 "	sbc %B1, %B0 \n\t" \
 "	sub %A1, %A0 \n\t" \
 "	sbc %B1, %B0 \n\t" \
 "	sub %A1, %A0 \n\t" \
 "	sbc %B1, %B0 \n\t" \
 "	sub %A1, %A0 \n\t" \
 "	sbc %B1, %B0 \n\t" /* r = n - q*13*/ \
 "	ldi r20, 3 \n\t" \
 "	add %A1, r20 \n\t" \
 "	adc %B1, r1    ; r = r+3 \n\t" \
 "	asr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	asr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	asr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	asr %B1 \n\t" \
 "	ror %A1 \n\t" /* r >> 4*/ \
 "	add %A0, %A1 \n\t" \
 "	adc %B0, %B1 \n\t" /* from above => q + ((r+3) >> 4)*/ \
"	clr r1 \n\t" \
: "=&a" (result) \
: "a" (dividend) \
: "r20", "r21" \
);
return result;
}

uint16_t divu3hd(uint16_t dividend)
{
uint16_t result;
__asm__ __volatile__ (
"	movw %A0, %A1 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" /* (n >> 2)*/ \
 "	movw r20, %A1 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" /* (n >> 4)*/ \
 "	add %A0, r20 \n\t" \
 "	adc %B0, r21 \n\t" /* q = (n >> 2) + (n >> 4)*/ \
 "	movw r20, %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" /* (q >> 4)*/ \
 "	add r20, %A0 \n\t" \
 "	adc r21, %B0 \n\t" /* q + (q >> 4)*/ \
 "	movw %A0, r20 \n\t" \
 "	mov %A0, %B0 \n\t" \
 "	clr %B0 \n\t" /* (q >> 8)	*/ \
 "	add r20, %A0 \n\t" \
 "	adc r21, %B0 \n\t" /* q + (q >> 8)*/ \
 "	movw %A0, r20 \n\t" \
 "	sub %A1, r20 \n\t" \
 "	sbc %B1, r21 \n\t" \
 "	sub %A1, r20 \n\t" \
 "	sbc %B1, r21 \n\t" \
 "	sub %A1, r20 \n\t" \
 "	sbc %B1, r21 \n\t" /* n - q*3*/ \
 "	movw r20, %A1 \n\t" \
  "	lsl %A1 \n\t" \
 "	rol %B1 \n\t" \
 "	lsl %A1 \n\t" \
 "	rol %B1 \n\t" \
 "	lsl %A1 \n\t" \
 "	rol %B1 \n\t" /* 8*r*/ \
 "	add %A1, r20 \n\t" \
 "	adc %B1, r21 \n\t" \
 "	add %A1, r20 \n\t" \
 "	adc %B1, r21 \n\t" \
 "	add %A1, r20 \n\t" \
 "	adc %B1, r21 \n\t" /* +3*r => 11*r*/ \
 "	lsr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	lsr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	lsr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	lsr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	lsr %B1 \n\t" \
 "	ror %A1 \n\t" /* r >> 5*/ \
 "	add %A0, %A1 \n\t" \
 "	adc %B0, %B1 \n\t" /* from above => q + (11*r) >> 5*/ \
"	clr r1 \n\t" \
: "=&a" (result) \
: "a" (dividend) \
: "r20", "r21" \
);
return result;
}

uint16_t divu5hd(uint16_t dividend)
{
uint16_t result;
__asm__ __volatile__ (
 "	movw %A0, %A1 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" /* (n >> 1)*/ \
 "	movw r20, %A1 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" /* (n >> 2)*/ \
 "	add %A0, r20 \n\t" \
 "	adc %B0, r21 \n\t" /* q = (n >> 1) + (n >> 2)*/ \
 "	movw r20, %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" /* (q >> 4)*/ \
 "	add r20, %A0 \n\t" \
 "	adc r21, %B0 \n\t" /* q + (q >> 4)*/ \
 "	movw %A0, r20 \n\t" \
 "	mov %A0, %B0 \n\t" \
 "	clr %B0 \n\t" /* (q >> 8)	*/ \
 "	add r20, %A0 \n\t" \
 "	adc r21, %B0 \n\t" /* q + (q >> 8)*/ \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" /* (q >> 2)	*/ \
 "	movw %A0, r20 \n\t" \
 "	sub %A1, r20 \n\t" \
 "	sbc %B1, r21 \n\t" \
 "	sub %A1, r20 \n\t" \
 "	sbc %B1, r21 \n\t" \
 "	sub %A1, r20 \n\t" \
 "	sbc %B1, r21 \n\t" \
 "	sub %A1, r20 \n\t" \
 "	sbc %B1, r21 \n\t" \
 "	sub %A1, r20 \n\t" \
 "	sbc %B1, r21 \n\t" /* r = n - q*5*/ \
 "	movw r20, %A1 \n\t" \
 "	lsl %A1 \n\t" \
 "	rol %B1 \n\t" \
 "	lsl %A1 \n\t" \
 "	rol %B1 \n\t" /* 4*r*/ \
 "	add %A1, r20 \n\t" \
 "	adc %B1, r21 \n\t" \
 "	add %A1, r20 \n\t" \
 "	adc %B1, r21 \n\t" \
 "	add %A1, r20 \n\t" \
 "	adc %B1, r21 \n\t" /* +3*r => 7*r*/ \
  "	lsr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	lsr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	lsr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	lsr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	lsr %B1 \n\t" \
 "	ror %A1 \n\t" /* r >> 5*/ \
 "	add %A0, %A1 \n\t" \
 "	adc %B0, %B1 \n\t" /* from above => q + (7*r) >> 5*/ \
"	clr r1 \n\t" \
: "=&a" (result) \
: "a" (dividend) \
: "r20", "r21" \
);
return result;
}

uint16_t divu6hd(uint16_t dividend)
{
uint16_t result;
__asm__ __volatile__ (
 "	movw %A0, %A1 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" /* (n >> 1)*/ \
 "	movw r20, %A1 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" /* (n >> 3)*/ \
 "	add %A0, r20 \n\t" \
 "	adc %B0, r21 \n\t" /* q = (n >> 1) + (n >> 3)*/ \
 "	movw r20, %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" /* (q >> 4)*/ \
 "	add r20, %A0 \n\t" \
 "	adc r21, %B0 \n\t" /* q + (q >> 4)*/ \
 "	movw %A0, r20 \n\t" \
 "	mov %A0, %B0 \n\t" \
 "	clr %B0 \n\t" /* (q >> 8)	*/ \
 "	add r20, %A0 \n\t" \
 "	adc r21, %B0 \n\t" /* q + (q >> 8)*/ \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" /* (q >> 2)	*/ \
 "	movw %A0, r20 \n\t" \
 "	sub %A1, r20 \n\t" \
 "	sbc %B1, r21 \n\t" \
 "	sub %A1, r20 \n\t" \
 "	sbc %B1, r21 \n\t" \
 "	sub %A1, r20 \n\t" \
 "	sbc %B1, r21 \n\t" \
 "	sub %A1, r20 \n\t" \
 "	sbc %B1, r21 \n\t" \
 "	sub %A1, r20 \n\t" \
 "	sbc %B1, r21 \n\t" \
 "	sub %A1, r20 \n\t" \
 "	sbc %B1, r21 \n\t" /* r = n - q*6*/ \
 "	inc %A1 \n\t" \
 "	adc %B1, r1 \n\t" \
 "	inc %A1 \n\t" \
 "	adc %B1, r1    ; r = r+2 \n\t" \
 "	lsr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	lsr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	lsr %B1 \n\t" \
 "	ror %A1 \n\t" /* r >> 3*/ \
 "	add %A0, %A1 \n\t" \
 "	adc %B0, %B1 \n\t" /* from above => q + ((r+2) >> 3)*/ \
"	clr r1 \n\t" \
: "=&a" (result) \
: "a" (dividend) \
: "r20", "r21" \
);
return result;
}

uint16_t divu7hd(uint16_t dividend)
{
uint16_t result;
__asm__ __volatile__ (
 "	movw %A0, %A1 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" /* (n >> 1)*/ \
 "	movw r20, %A1 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" /* (n >> 4)*/ \
 "	add %A0, r20 \n\t" \
 "	adc %B0, r21 \n\t" /* q = (n >> 1) + (n >> 4)*/ \
 "	movw r20, %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" /* (q >> 6)*/ \
 "	add r20, %A0 \n\t" \
 "	adc r21, %B0 \n\t" /* q + (q >> 6)*/ \
 "	movw %A0, r20 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" /* (q >> 12)	*/ \
 "	add r20, %A0 \n\t" \
 "	adc r21, %B0 \n\t" /* q + (q >> 12)*/ \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" /* (q >> 2)	*/ \
 "	movw %A0, r20	 \n\t" \
 "	sub %A1, r20 \n\t" \
 "	sbc %B1, r21 \n\t" \
 "	sub %A1, r20 \n\t" \
 "	sbc %B1, r21 \n\t" \
 "	sub %A1, r20 \n\t" \
 "	sbc %B1, r21 \n\t" \
 "	sub %A1, r20 \n\t" \
 "	sbc %B1, r21 \n\t" \
 "	sub %A1, r20 \n\t" \
 "	sbc %B1, r21 \n\t" \
 "	sub %A1, r20 \n\t" \
 "	sbc %B1, r21 \n\t" \
 "	sub %A1, r20 \n\t" \
 "	sbc %B1, r21 \n\t" /* r = n - q*7*/ \
 "	inc %A1 \n\t" \
 "	adc %B1, r1    ; r = r+1 \n\t" \
 "	lsr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	lsr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	lsr %B1 \n\t" \
 "	ror %A1 \n\t" /* r >> 3*/ \
 "	add %A0, %A1 \n\t" \
 "	adc %B0, %B1 \n\t" /* from above => q + ((r+1) >> 3)*/ \
"	clr r1 \n\t" \
: "=&a" (result) \
: "a" (dividend) \
: "r20", "r21" \
);
return result;
}

uint16_t divu9hd(uint16_t dividend)
{
uint16_t result;
__asm__ __volatile__ (
 "	movw r20, %A1 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" /* (n >> 3)*/ \
 "	movw %A0, %A1 \n\t" \
 "	sub %A0, r20 \n\t" \
 "	sbc %B0, r21 \n\t" /* n - (n >> 3)*/ \
 "	movw r20, %A0 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" /* (q >> 6)*/ \
 "	add %A0, r20 \n\t" \
 "	adc %B0, r21 \n\t" /* q = q + (n >> 6)*/ \
 "	movw r20, %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" \
 "	lsr %B0 \n\t" \
 "	ror %A0 \n\t" /* (q >> 12)*/ \
 "	add r20, %A0 \n\t" \
 "	adc r21, %B0 \n\t" /* q + (q >> 12)*/ \
 "	movw %A0, r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" \
 "	lsr r21 \n\t" \
 "	ror r20 \n\t" /* (q >> 3)	*/ \
 "	movw %A0, r20	 \n\t" \
 "	sub %A1, r20 \n\t" \
 "	sbc %B1, r21 \n\t" \
 "	sub %A1, r20 \n\t" \
 "	sbc %B1, r21 \n\t" \
 "	sub %A1, r20 \n\t" \
 "	sbc %B1, r21 \n\t" \
 "	sub %A1, r20 \n\t" \
 "	sbc %B1, r21 \n\t" \
 "	sub %A1, r20 \n\t" \
 "	sbc %B1, r21 \n\t" \
 "	sub %A1, r20 \n\t" \
 "	sbc %B1, r21 \n\t" \
 "	sub %A1, r20 \n\t" \
 "	sbc %B1, r21 \n\t" \
 "	sub %A1, r20 \n\t" \
 "	sbc %B1, r21 \n\t" \
 "	sub %A1, r20 \n\t" \
 "	sbc %B1, r21 \n\t" /* r = n - q*9*/ \
 "	ldi r20, 7 \n\t" \
 "	add %A1, r20 \n\t" \
 "	adc %B1, r1    ; r = r+7 \n\t" \
 "	lsr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	lsr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	lsr %B1 \n\t" \
 "	ror %A1 \n\t" \
 "	lsr %B1 \n\t" \
 "	ror %A1 \n\t" /* r >> 3*/ \
 "	add %A0, %A1 \n\t" \
 "	adc %B0, %B1 \n\t" /* from above => q + ((r+7) >> 4)*/ \
"	clr r1 \n\t" \
: "=&a" (result) \
: "a" (dividend) \
: "r20", "r21" \
);
return result;
}
