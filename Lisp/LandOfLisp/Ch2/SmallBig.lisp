;;clear the window
(screen:clear-window (screen:make-window))

;;;defparameter: keyword that allows you to define global variables
;;;*variable-name*: these are optional they are conventionally used in the definition of global variables (they are called earmuffs) 
(print "Think of a number between 1 and 100.")
(print "The computer will try to guess that number")
(print "Provide feedback to the computer via the commands: (smaller), (bigger), (start-over), and (correct)")
(print "Say: (guess-my-number to begin)")
(defparameter *small* 1)
(defparameter *big* 100)

(defun guess-my-number()
	;;add *small* and *big* then arithmetic shift right by 1 (what -1 means)
	;;this effectively divides by 1
	(ash (+ *small* *big*) -1)
)

(defun smaller()
	(setf *big* (1- (guess-my-number)))
	(guess-my-number))


(defun bigger()
	(setf *small* (1+ (guess-my-number)))
	(guess-my-number)
)

(defun start-over()
	(defparameter *small* 1)
	(defparameter *big* 100)
	(guess-my-number)
)

(defun correct()
	(print "COMPUTER: YAY! :D")
	(print "                 ")
	(print "    #    #       ")
	(print "    #    #       ")
	(print "    #    #       ")
	(print "                 ")
	(print " #          #    ")
	(print "  #        #     ")
	(print "   ########      ")
	(print "                 ")
)
