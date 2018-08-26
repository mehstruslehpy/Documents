valgrind ../main <<-ENDOFMESSAGE
	p #p for proof mode not calculator mode

	#Proposition 1
	#builds: (A -> (B & C))
	b #binary 
    c #conditional
	u #unary (on lhs)
	v #variable
	A #named A
	b #binary (on rhs of conditional)
	a #and
	u #unary (on lhs of and)
	v #variable
	B #named B
	u #unary (on rhs of and)
	v #variable
	C #named C
	c #continue to next proposition
	
	#Proposition 2
	#builds: (B -> (A & C))
	b #binary
    c #conditional
	u #unary (on lhs of conditional)
	v #variable
	B #named B
	b #binary (on rhs of conditional)
	a #and
	u #unary (on lhs of and)
	v #variable
	A #named A
	u #unary (on rhs of and)
	v #variable
	C #named C
	q #quit adding propositions, continue to conclusion

	#Conclusion
	#builds: ((A v B) -> C), which is negated for the proof
	b #binary
	c #conditional
	b #binary (on lhs of conditional)
	o #or
	u #unary (on lhs of or)
	v #variable
	A #named A
	u #unary (on rhs of or)
	v #variable
	B #named B
	u #unary (on rhs of conditional)
	v #variable
	C #named C
	c #continue to proof
	ENDOFMESSAGE
