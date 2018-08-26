valgrind ../main <<-ENDOFMESSAGE
	p #proof 

	#a single proposition argument needs a garbage variable
	u
	v
	B
	q

	u
	n
	b
	c
	u
	v
	Q
	b
	a
	u
	v
	P
	u
	n
	u
	v
	P
	c #continue to proof
	ENDOFMESSAGE
