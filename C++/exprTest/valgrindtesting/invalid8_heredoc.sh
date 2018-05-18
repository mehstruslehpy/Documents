valgrind ../main <<-ENDOFMESSAGE
	p #proof 

	b
	c
	u
	v
	A
	b
	a
	u
	v
	B
	u
	v
	C
	c

	b
	c
	u
	n
	u
	v
	C
	u
	v
	D
	q
	
	#Conclusion
	b
	c
	b
	a
	u
	v
	B
	u
	n
	u
	v
	D
	u
	v
	A
	c #continue to proof
	ENDOFMESSAGE
