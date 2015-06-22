;Optimized division by 100
;Jose Gama June, 2015
;Assembly code based on the C code from:
;Henry S. Warren, 2012
;Hacker's Delight 2nd ed
;Addison-Wesley Professional
; divu100
.def	dividendH	=r17		; dividend MSB
.def	dividendL	=r16		; dividend LSB
.def	resultH	=r19		; result MSB
.def	resultL	=r18		; result LSB
.def	tempH	=r21		; temporary data MSB
.def	tempL	=r20		; temporary data LSB
.def	temp2H	=r23		; temporary data 2 MSB
.def	temp2L	=r22		; temporary data 2 LSB
	ldi dividendH, high(37000)
	ldi dividendL, low(37000)
	clr r1

	movw tempL, dividendL
	lsr tempH
	ror tempL		; (n >> 1)
	movw resultL, tempL
	lsr tempH
	ror tempL
	lsr tempH
	ror tempL		; (n >> 3)
	add	resultL, tempL	; q = (n >> 1) + (n >> 3)
	adc resultH, tempH
	lsr tempH
	ror tempL
	lsr tempH
	ror tempL
	lsr tempH
	ror tempL		; (n >> 6)
	add	resultL, tempL	; q = (n >> 1) + (n >> 3) + (n >> 6)
	adc resultH, tempH
	lsr tempH
	ror tempL
	lsr tempH
	ror tempL
	lsr tempH
	ror tempL
	lsr tempH
	ror tempL		; (n >> 10)
	sub	resultL, tempL	; q = ... - (n >> 10)
	sbc resultH, tempH
	lsr tempH
	ror tempL
	lsr tempH
	ror tempL		; (n >> 12)
	add	resultL, tempL	; q = ... + (n >> 12)
	adc resultH, tempH
	lsr tempH
	ror tempL		; (n >> 13)
	add	resultL, tempL	; q = ... + (n >> 13)
	adc resultH, tempH
	lsr resultH
	ror resultL
	lsr resultH
	ror resultL
	lsr resultH
	ror resultL
	lsr resultH
	ror resultL
	lsr resultH
	ror resultL
	lsr resultH
	ror resultL		 ; q >> 6
	movw tempL, resultL
	lsl tempL
	rol tempH
	lsl tempL
	rol tempH
	movw temp2L, tempL	  ; q*4
	lsl tempL
	rol tempH
	lsl tempL
	rol tempH
	lsl tempL
	rol tempH
	add  temp2L, tempL
	adc  temp2H, tempH	  ; q*4 + q*32
	lsl tempL
	rol tempH
	add  temp2L, tempL
	adc  temp2H, tempH	  ; q*4 + q*32 + q*64 = q*100
	sub dividendL, temp2L
	sbc dividendH, temp2H		; r = n - q*100
	ldi tempL, 28
	add dividendL, tempL
	adc dividendH, r1	 ; r = r+28
	asr dividendH
	ror dividendL
	asr dividendH
	ror dividendL
	asr dividendH
	ror dividendL
	asr dividendH
	ror dividendL
	asr dividendH
	ror dividendL
	asr dividendH
	ror dividendL
	asr dividendH
	ror dividendL		; r >> 7
	add resultL, dividendL
	adc resultH, dividendH		; from above => q + ((r+28) >> 7)
	
	
