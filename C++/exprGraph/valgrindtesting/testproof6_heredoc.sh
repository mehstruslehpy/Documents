valgrind ../main <<-ENDOFMESSAGE
	p
	#Proposition 1
	b
	o
	u
	v
	A
	b
	a
	u
	v
	D
	u
	v
	E
	c #continue
	
	#Proposition 2
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
	q #continue

	#Conclusion
	b
	o
	u
	v
	D
	u
	v
	C
	c # continue
	ENDOFMESSAGE
