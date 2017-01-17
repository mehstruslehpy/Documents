;;;the two local variables a and b are given values then added together
(let ( (a 5) (b 6) )
	 (print (+ a b))
)
;;;this is the common practice way to do this
(let ((a 5)
	 (c 7)
	 (b 6))
	 (print (+ c (+ a b)))
)

