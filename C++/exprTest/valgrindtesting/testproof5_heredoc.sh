valgrind ../main <<-ENDOFMESSAGE
	p
	#Proposition 1
	b
	c
	u
	v
	B
	u
	v
	A
	c #continue
	
	#Proposition 2
	u
	n
	b
	a
	u
	v
	A
	u
	v
	C
	c #continue
	
	#Proposition 3
	b
	o
	u
	v
	B
	u
	v
	C
	q #continue

	#Conclusion
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
	c # continue
	ENDOFMESSAGE
