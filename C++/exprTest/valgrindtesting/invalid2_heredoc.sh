valgrind ../main <<-ENDOFMESSAGE
	p 
	
	u
	v
	T
	c #continue to next proposition
	
	b
	c
	u
	v
	T
	b
	o
	u
	v
	B
	u
	v
	M
	c

	b
	c
	u
	v
	M
	u
	v
	H
	q

	#Conclusion
	u
	v
	B
	c #continue to proof
	ENDOFMESSAGE
