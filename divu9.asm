;Optimized division by 9
;Jose Gama June, 2015
;Assembly code based on the C code from:
;Henry S. Warren, 2012
;Hacker's Delight 2nd ed
;Addison-Wesley Professional
; divu9
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
	ror tempL
	lsr tempH
	ror tempL
	lsr tempH
	ror tempL		; (n >> 3)
	movw resultL, dividendL
	sub resultL, tempL
	sbc resultH, tempH	; n - (n >> 3)
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
	ror tempL		; (q >> 6)
	add resultL, tempL
	adc resultH, tempH		; q = q + (n >> 6)
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
	add tempL, resultL
	adc tempH, resultH		; q + (q >> 12)
	movw resultL, tempL
	lsr tempH
	ror tempL
	lsr tempH
	ror tempL
	lsr tempH
	ror tempL		; (q >> 3)	
	movw resultL, tempL	
	sub dividendL, tempL
	sbc dividendH, tempH
	sub dividendL, tempL
	sbc dividendH, tempH
	sub dividendL, tempL
	sbc dividendH, tempH
	sub dividendL, tempL
	sbc dividendH, tempH
	sub dividendL, tempL
	sbc dividendH, tempH
	sub dividendL, tempL
	sbc dividendH, tempH
	sub dividendL, tempL
	sbc dividendH, tempH
	sub dividendL, tempL
	sbc dividendH, tempH
	sub dividendL, tempL
	sbc dividendH, tempH		; r = n - q*9
	ldi tempL, 7
	add dividendL, tempL
	adc dividendH, r1    ; r = r+7
	lsr dividendH
	ror dividendL
	lsr dividendH
	ror dividendL
	lsr dividendH
	ror dividendL
	lsr dividendH
	ror dividendL		; r >> 3
	add resultL, dividendL
	adc resultH, dividendH		; from above => q + ((r+7) >> 4)
	
	
	
	
