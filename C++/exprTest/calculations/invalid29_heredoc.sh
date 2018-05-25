valgrind ../main <<-ENDOFMESSAGE
	c #proof 

	b
	c
	u
	v
	P
	u
	v
	Q
	c

	u
	n
	b
	o
	u
	v
	P
	u
	v
	Q
	q #continue to proof
	1
	1
	0
	ENDOFMESSAGE
