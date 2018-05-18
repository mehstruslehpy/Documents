valgrind ../main <<-ENDOFMESSAGE
	p #proof 
	
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
	c
	
	b
	c
	b
	o
	u
	v
	C
	u
	v
	D
	u
	n
	u
	v
	E
	q

	#Conclusion
	u
	n
	b
	a
	u
	v
	A
	u
	v
	E
	c #continue to proof
	ENDOFMESSAGE
