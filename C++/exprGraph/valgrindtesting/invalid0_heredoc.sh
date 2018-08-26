valgrind ../main <<-ENDOFMESSAGE
	p #p for proof mode not calculator mode

	#Proposition 1
	b
	c
	u
	v
	A
	u
	v
	B
	c #continue to next proposition
	
	#Proposition 2
	u
	v
	B
	q #quit adding propositions, continue to conclusion

	#Conclusion
	u
	v
	A
	c #continue to proof
	ENDOFMESSAGE
