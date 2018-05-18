valgrind ../main <<-ENDOFMESSAGE
	p
	#Proposition 1
	b
	c
	b
	c
	b
	a
	u
	v
	A
	u
	v
	B
	u
	v
	C
	b
	c
	u
	v
	D
	u
	v
	E
	c #continue
	
	#Proposition 2
	u
	v
	D
	q #continue

	#Conclusion
	b
	c
	u
	v
	C
	u
	v
	E
	c # continue
	ENDOFMESSAGE
