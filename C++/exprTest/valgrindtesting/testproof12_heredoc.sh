valgrind ../main <<-ENDOFMESSAGE
	p

	#Proposition 1
	u
	v
	A
	q #continue

	#Conclusion
	b
	o
	u
	v
	A
	u
	v
	B
	c # continue
	ENDOFMESSAGE
