valgrind ../main <<-ENDOFMESSAGE
	p #p for proof mode not calculator mode

	#Proposition 1
	b
	c
	u
	v
	R
	u
	v
	P
	c #continue to next proposition
	
	#Proposition 2
	u
	n
	u
	v
	R
	q #quit adding propositions, continue to conclusion

	#Conclusion
	u
	n
	u
	v
	P
	c #continue to proof
	ENDOFMESSAGE
