;;clear the window
(screen:clear-window (screen:make-window))

;;local functions
;;
;;(flet ((function_name (arguments)
;;		...function body...
;;		...function body...
;;		...function body...))
;;) 

(print "Function one:")
;;a function that adds 10 to its input
(flet ((add-ten (n)
		(+ n 10)))
	 
	;;now that it is defined locally we can use it locally
	(print (add-ten 5)  )
	(print (add-ten 10) )
	(print (add-ten 15) )
	(print (add-ten 20) )
)

;;this would fail because it is not local to where add-ten is defined
;;(print (add-ten 20) )

;;declaring multiple functions at once with a single flet then using them in combination
(print "")
(print "Function two:")
(flet ((f (n)
		  (+ n 10))
	   (g (n)
	   	  (- n 3)))
	   (print (g(f 5)))
	   (print (f(g 4)))
	   (print (g(f 3)))
	   (print (f(g 2)))
	   (print (g(f 1))))

;;to make function names available in defined functions we can use the labels command similarly
(print "")
(print "Function three:")
(labels ((a (n)	;;this is a function that adds 5 to a number
			(+ n 5))
		(b (n)	;; this is a function that calls a and adds 6 to that
			(+ (a n) 6)))
(print (b 10))  ;;in use
(print (b 15))	;;in use
(print (b 20)))	;;in use
