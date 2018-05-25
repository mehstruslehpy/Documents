valgrind ../main <<-ENDOFMESSAGE
	c #proof 
	
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
	b
	c
	u
	v
	D
	u
	v
	E
	u
	v
	A
	c

	#Conclusion
	b
	o
	u
	v
	E
	u
	v
	C
	q #continue to proof
	1
	0
	1
	0
	ENDOFMESSAGE
