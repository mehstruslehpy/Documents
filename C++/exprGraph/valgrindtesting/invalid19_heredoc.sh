valgrind ../main <<-ENDOFMESSAGE
	p #proof 
	
	b
	c
	u
	v
	A
	u
	v
	B
	c

	b
	c
	u
	v
	C
	b
	a
	u
	n
	u
	v
	D
	u
	v
	E
	q

	#Conclusion
	b
	o
	u
	v
	D
	u
	v
	F
	c #continue to proof
	ENDOFMESSAGE
