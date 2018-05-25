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
	u
	v
	B
	c
	
	#Conclusion
	b
	c
	u
	v
	A
	u
	v
	C
	q
	0
	0
	1
	ENDOFMESSAGE
