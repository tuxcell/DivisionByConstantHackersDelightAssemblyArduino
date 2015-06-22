;Optimized division by 12
;Jose Gama June, 2015
;Assembly code based on the C code from:
;Henry S. Warren, 2012
;Hacker's Delight 2nd ed
;Addison-Wesley Professional
; divu12
.def	dividendH	=r17		; dividend MSB
.def	dividendL	=r16		; dividend LSB
.def	resultH	=r19		; result MSB
.def	resultL	=r18		; result LSB
.def	tempH	=r21		; temporary data MSB
.def	tempL	=r20		; temporary data LSB
	ldi dividendH, high(55000)
	ldi dividendL, low(55000)
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
	ror resultL
	lsr resultH
	ror resultL
	lsr resultH
	ror resultL
	lsr resultH
	ror resultL		; (q >> 8)	
	add resultL, tempL
	adc resultH, tempH		; q = q + (q >> 8)
	lsr resultH
	ror resultL
	lsr resultH
	ror resultL
	lsr resultH
	ror resultL		; q >> 3
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
	sbc dividendH, resultH		; r = n - q*12
	ldi tempL, 4
	add dividendL, tempL
	adc dividendH, r1	 ; r = r+4
	lsr dividendH
	ror dividendL
	lsr dividendH
	ror dividendL
	lsr dividendH
	ror dividendL
	lsr dividendH
	ror dividendL		; r >> 4
	add resultL, dividendL
	adc resultH, dividendH		; from above => q + ((r+4) >> 4)
	
	
