valgrind ../main <<-ENDOFMESSAGE
	p #proof 
	
	b
	c
	u
	v
	A
	u
	v
	B
	q
	
	#Conclusion
	b
	c
	u
	v
	B
	u
	v
	A
	c #continue to proof
	ENDOFMESSAGE
