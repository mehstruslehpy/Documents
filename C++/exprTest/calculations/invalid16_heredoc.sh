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
	F
	u
	v
	P
	c

	b
	c
	u
	n
	u
	v
	A
	u
	v
	N
	c

	#Conclusion
	u
	v
	P
	q #continue to proof
	1
	0
	1
	ENDOFMESSAGE
