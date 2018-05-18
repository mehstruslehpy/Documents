valgrind ../main <<-ENDOFMESSAGE
	p

	#Proposition 1
	b
	o
	u
	v
	B
	u
	v
	A
	c #continue
	
	#Proposition 2
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
	u
	n
	b
	c
	u
	v
	A
	u
	n
	u
	v
	A
	c # continue
	ENDOFMESSAGE
