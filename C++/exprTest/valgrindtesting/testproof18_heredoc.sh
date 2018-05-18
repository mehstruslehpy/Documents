valgrind ../main <<-ENDOFMESSAGE
	p

	#Proposition 1
	u
	n
	b
	o
	u
	v
	A
	u
	v
	B
	c #continue
	
	#Proposition 2
	b
	o
	u
	v
	C
	u
	v
	B
	c #continue

	#Proposition 3
	u
	n
	b
	a
	u
	v
	D
	u
	v
	C
	q #continue
	
	#Conclusion
	u
	n
	u
	v
	D
	c # continue
	ENDOFMESSAGE
