valgrind ../main <<-ENDOFMESSAGE
	p

	#Proposition 1
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
	n
	u
	v
	C
	c #continue

	#Proposition 2
	u
	v
	C
	c #continue

	#Proposition 3
	b
	o
	b
	a
	u
	v
	D
	u
	n
	u
	v
	E
	u
	v
	A
	q #continue


	#Conclusion
	u
	v
	D
	c # continue
	ENDOFMESSAGE
dot -Tpng OUTPUT_DOTFILE_PROOF.gv > image.png
