valgrind ../main <<-ENDOFMESSAGE
	c #proof 
	
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
	c

	#Conclusion
	b
	o
	u
	v
	D
	u
	v
	F
	q #continue to proof
	1
	1
	1
	ENDOFMESSAGE
