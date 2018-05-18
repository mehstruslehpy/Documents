valgrind ../main <<-ENDOFMESSAGE
	p #proof 

	b
	c
	u
	v
	P
	u
	v
	Q
	q

	#Conclusion
	b
	o
	u
	v
	P
	u
	v
	Q
	c #continue to proof
	ENDOFMESSAGE
