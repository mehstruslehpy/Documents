valgrind ../main <<-ENDOFMESSAGE
	p

	#Proposition 1
	b
	a
	b
	c
	u
	v
	A
	u
	v
	B
	b
	c
	u
	v
	B
	u
	v
	A
	q #continue
	
	#Conclusion
	b
	c
	u
	v
	A
	b
	a
	u
	v
	A
	u
	v
	B
	c # continue
	ENDOFMESSAGE
