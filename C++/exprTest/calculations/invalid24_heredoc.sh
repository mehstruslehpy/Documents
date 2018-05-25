valgrind ../main <<-ENDOFMESSAGE
	c #proof 

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
	c

	b
	o
	u
	v
	B
	u
	n
	b
	c
	u
	v
	C
	u
	v
	D
	c

	#Conclusion
	b
	c
	u
	v
	D
	u
	n
	b
	o
	u
	v
	A
	u
	v
	B
	q #continue to proof
	1
	0
	0
	1
	1
	ENDOFMESSAGE
