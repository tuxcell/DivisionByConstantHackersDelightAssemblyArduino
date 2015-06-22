;Optimized division by 3
;Jose Gama June, 2015
;Assembly code based on the C code from:
;Henry S. Warren, 2012
;Hacker's Delight 2nd ed
;Addison-Wesley Professional
; divu3
.def	dividendH	=r17		; dividend MSB
.def	dividendL	=r16		; dividend LSB
.def	resultH	=r19		; result MSB
.def	resultL	=r18		; result LSB
.def	tempH	=r21		; temporary data MSB
.def	tempL	=r20		; temporary data LSB
	ldi dividendH, high(55555)
	ldi dividendL, low(55555)

	movw resultL, dividendL
	lsr resultH
	ror resultL
	lsr resultH
	ror resultL		; (n >> 2)
	movw tempL, dividendL
	lsr tempH
	ror tempL
	lsr tempH
	ror tempL
	lsr tempH
	ror tempL
	lsr tempH
	ror tempL		; (n >> 4)
	add resultL, tempL
	adc resultH, tempH		; q = (n >> 2) + (n >> 4)
	movw tempL, resultL
	lsr resultH
	ror resultL
	lsr resultH
	ror resultL
	lsr resultH
	ror resultL
	lsr resultH
	ror resultL		; (q >> 4)
	add tempL, resultL
	adc tempH, resultH		; q + (q >> 4)
	movw resultL, tempL
	mov resultL, resultH
	clr resultH		; (q >> 8)	
	add tempL, resultL
	adc tempH, resultH		; q + (q >> 8)
	movw resultL, tempL
	sub dividendL, tempL
	sbc dividendH, tempH
	sub dividendL, tempL
	sbc dividendH, tempH
	sub dividendL, tempL
	sbc dividendH, tempH		; n - q*3
	movw tempL, dividendL
	lsr dividendH
	ror dividendL
	lsr dividendH
	ror dividendL
	lsr dividendH
	ror dividendL
	lsr dividendH
	ror dividendL
	lsr dividendH
	ror dividendL		; r >> 5
	lsl dividendL
	rol dividendH
	lsl dividendL
	rol dividendH
	lsl dividendL
	rol dividendH		; 8*r
	add dividendL, tempL
	adc dividendH, tempH
	add dividendL, tempL
	adc dividendH, tempH
	add dividendL, tempL
	adc dividendH, tempH		; +3*r => 11*r
	add resultL, dividendL
	adc resultH, dividendH		; from above => q + (11*r >> 5)
	
	
	
