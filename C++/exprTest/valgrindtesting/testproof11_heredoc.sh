valgrind ../main <<-ENDOFMESSAGE
	p

	#Proposition 1
	b
	c
	u
	v
	A
	u
	v
	B
	q #continue

	#Conclusion
	b
	c
	u
	n
	u
	v
	B
	u
	n
	u
	v
	A
	c # continue
	ENDOFMESSAGE
