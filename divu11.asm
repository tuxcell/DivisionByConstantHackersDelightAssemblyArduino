;Optimized division by 11
;Jose Gama June, 2015
;Assembly code based on the C code from:
;Henry S. Warren, 2012
;Hacker's Delight 2nd ed
;Addison-Wesley Professional
; divu11
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
	ror tempL		; (n >> 2)
	add	resultL, tempL	; q = (n >> 1) + (n >> 2)
	adc resultH, tempH
	lsr tempH
	ror tempL
	lsr tempH
	ror tempL
	lsr tempH
	ror tempL		; (n >> 5)	
	sub resultL, tempL
	sbc resultH, tempH	; n - (n >> 5)
	lsr tempH
	ror tempL
	lsr tempH
	ror tempL		; (n >> 7)	
	add	resultL, tempL	; q + (n >> 7)
	adc resultH, tempH	
	movw tempL, resultL
	lsr tempH
	ror tempL
	lsr tempH
	ror tempL
	lsr tempH
	ror tempL
	lsr tempH
	ror tempL
	lsr tempH
	ror tempL
	lsr tempH
	ror tempL
	lsr tempH
	ror tempL
	lsr tempH
	ror tempL
	lsr tempH
	ror tempL
	lsr tempH
	ror tempL		; (q >> 10)
	add resultL, tempL
	adc resultH, tempH		; q = q + (q >> 10)
	lsr resultH
	ror resultL
	lsr resultH
	ror resultL
	lsr resultH
	ror resultL		; (q >> 3)	
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
	sbc dividendH, resultH		; r = n - q*11
	ldi tempL, 5
	add dividendL, tempL
	adc dividendH, r1	 ; r = r+5
	lsr dividendH
	ror dividendL
	lsr dividendH
	ror dividendL
	lsr dividendH
	ror dividendL
	lsr dividendH
	ror dividendL		; r >> 4
	add resultL, dividendL
	adc resultH, dividendH		; from above => q + ((r+5) >> 4)
	
	
	
