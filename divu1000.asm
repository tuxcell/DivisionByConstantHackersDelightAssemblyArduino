;Optimized division by 1000
;Jose Gama June, 2015
;Assembly code based on the C code from:
;Henry S. Warren, 2012
;Hacker's Delight 2nd ed
;Addison-Wesley Professional
; divu1000
.def	dividendH	=r17		; dividend MSB
.def	dividendL	=r16		; dividend LSB
.def	resultH	=r19		; result MSB
.def	resultL	=r18		; result LSB
.def	tempH	=r21		; temporary data MSB
.def	tempL	=r20		; temporary data LSB
.def	temp2H	=r23		; temporary data MSB
.def	temp2L	=r22		; temporary data LSB

	ldi dividendH, high(37000)
	ldi dividendL, low(37000)
	clr r1

	movw tempL, dividendL	
	lsr tempH
	ror tempL	; (n >> 1)
	movw resultL, tempL	
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
	ror tempL		; (n >> 7)
	movw temp2L, tempL
	lsr tempH
	ror tempL		; (n >> 8)
	add  temp2L, tempL	; t = (n >> 7) + (n >> 8)
	adc temp2H, tempH
	lsr tempH
	ror tempL
	lsr tempH
	ror tempL
	lsr tempH
	ror tempL
	lsr tempH
	ror tempL		; (n >> 12)
	add temp2L, tempL	; t = (n >> 7) + (n >> 8) + (n >> 12)
	adc temp2H, tempH	
	lsr tempH
	ror tempL
	lsr tempH
	ror tempL	
	lsr tempH
	ror tempL		; (n >> 15)	
	add resultL, tempL	; q = (n >> 1) + (n >> 15)
	adc resultH, tempH
	add resultL, temp2L
	adc resultH, temp2H  ; q = ... + t
	lsr temp2H
	ror temp2L
	lsr temp2H
	ror temp2L
	lsr temp2H
	ror temp2L
	lsr temp2H
	ror temp2L
	lsr temp2H
	ror temp2L
	lsr temp2H
	ror temp2L
	lsr temp2H
	ror temp2L
	lsr temp2H
	ror temp2L
	lsr temp2H
	ror temp2L
	lsr temp2H
	ror temp2L
	lsr temp2H
	ror temp2L
	add resultL, temp2L
	adc resultH, temp2H  ; q = ... + (t >> 11)
	lsr temp2H
	ror temp2L
	lsr temp2H
	ror temp2L
	lsr temp2H
	ror temp2L
	add resultL, temp2L
	adc resultH, temp2H  ; q = ... + (t >> 14)	
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
	ror resultL		; q >> 9
	movw tempL, resultL
	movw temp2L, tempL
	lsl temp2L
	rol temp2H
	lsl temp2L
	rol temp2H
	lsl temp2L
	rol temp2H  ; q*8
	movw r0, temp2L
	lsl temp2L
	rol temp2H  ; q*16
	add  r0, temp2L
	adc  r1, temp2H	
	lsl temp2L
	rol temp2H
	lsl temp2L
	rol temp2H
	lsl temp2L
	rol temp2H
	lsl temp2L
	rol temp2H
	lsl temp2L
	rol temp2H
	lsl temp2L
	rol temp2H  ; q*1024
	sub  temp2L, r0
	sbc  temp2H, r1	  ; q*1024 - q*8 - q*16 = q*1000	
	sub dividendL, temp2L
	sbc dividendH, temp2H		; r = n - q*1000
	ldi tempL, 24
	add dividendL, tempL
	adc dividendH, r1	 ; r = r+24
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
	ror dividendL
	asr dividendH
	ror dividendL
	asr dividendH
	ror dividendL
	asr dividendH
	ror dividendL		; r >> 10
	add resultL, dividendL
	adc resultH, dividendH		; from above => q + ((r+24) >> 10)
	
	
