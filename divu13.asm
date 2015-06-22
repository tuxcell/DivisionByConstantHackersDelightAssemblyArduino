;Optimized division by 13
;Jose Gama June, 2015
;Assembly code based on the C code from:
;Henry S. Warren, 2012
;Hacker's Delight 2nd ed
;Addison-Wesley Professional
; divu13
.def	dividendH	=r17		; dividend MSB
.def	dividendL	=r16		; dividend LSB
.def	resultH	=r19		; result MSB
.def	resultL	=r18		; result LSB
.def	tempH	=r21		; temporary data MSB
.def	tempL	=r20		; temporary data LSB
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
	ror tempL
	lsr tempH
	ror tempL		; (n >> 4)
	add   resultL, tempL	; q = (n >> 1) + (n >> 4)
	adc resultH, tempH
	movw tempL, resultL
	lsr tempH
	ror tempL
	lsr tempH
	ror tempL
	lsr tempH
	ror tempL
	lsr tempH
	ror tempL		; (q >> 4)
	add resultL, tempL
	adc resultH, tempH		; q = q + (q >> 4)
	movw tempL, resultL
	lsr resultH
	ror resultL
	lsr resultH
	ror resultL
	lsr resultH
	ror resultL
	lsr resultH
	ror resultL
	lsr resultH
	ror resultL		; (q >> 5)	
	add resultL, tempL
	adc resultH, tempH		; q = q + (q >> 5)
	movw tempL, resultL
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
	ror resultL
	lsr resultH
	ror resultL		; (q >> 12)	
	add resultL, tempL
	adc resultH, tempH		; q = q + (q >> 12)	
	lsr resultH
	ror resultL
	lsr resultH
	ror resultL
	lsr resultH
	ror resultL             ; q >> 3
	sub dividendL, resultL
	sbc dividendH, resultH
	sub dividendL, resultL
	sbc dividendH, resultH
	sub dividendL, resultL
	sbc dividendH, resultH
	sub dividendL, resultL
	sbc dividendH, resultH
	sub dividendL, resultL
	sbc dividendH, resultH
	sub dividendL, resultL
	sbc dividendH, resultH
	sub dividendL, resultL
	sbc dividendH, resultH
	sub dividendL, resultL
	sbc dividendH, resultH
	sub dividendL, resultL
	sbc dividendH, resultH
	sub dividendL, resultL
	sbc dividendH, resultH
	sub dividendL, resultL
	sbc dividendH, resultH
	sub dividendL, resultL
	sbc dividendH, resultH
	sub dividendL, resultL
	sbc dividendH, resultH		; r = n - q*13
	ldi tempL, 3
	add dividendL, tempL
	adc dividendH, r1    ; r = r+3
	asr dividendH
	ror dividendL
	asr dividendH
	ror dividendL
	asr dividendH
	ror dividendL
	asr dividendH
	ror dividendL		; r >> 4
	add resultL, dividendL
	adc resultH, dividendH		; from above => q + ((r+3) >> 4)
	
	
	
