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
	u
	n
	u
	v
	C
	u
	v
	D
	c
	
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
	q #continue to proof
	1
	1
	0
	ENDOFMESSAGE
