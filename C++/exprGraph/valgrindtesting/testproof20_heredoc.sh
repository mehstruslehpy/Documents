valgrind ../main <<-ENDOFMESSAGE
	p

	#Proposition 1
	b
	c
	u
	v
	A
	b
	c
	u
	v
	B
	u
	v
	C
	q #continue
	
	#Conclusion
	b
	c
	b
	a
	u
	v
	A
	u
	v
	B
	u
	v
	C
	c # continue
	ENDOFMESSAGE
