;;;a custom repl the game-print command and game-eval command will be written shortly after this
;;;basically read via game-read into the var cmd, then unless game-read == quit continue iterating
(defun game-repl ()
	(let ((cmd (game-read)))
		(unless (eq (car cmd) 'quit)
			(game-print (game-eval cmd))
			(game-repl))))

;;;our game-read function for our repl
;;;read a line, concatenate the line with quotes and parenthesis, define a local func called quote it that adds quotes to its input x
;;; via the list command, pass cons the first part of the cmd list via car, then mapcar quote it to ever other element of cmd using cdr
;;;basically this function takes a plain input from the user and turns it into a command form for our game
(defun game-read ()
	(let ((cmd (read-from-string
					(concatenate 'string "(" (read-line) ")"))))
	(flet ((quote-it (x)
					(list 'quote x)))
		(cons (car cmd) (mapcar #'quote-it (cdr cmd))))))

;;;defining commands that we want to allow the player to use
(defparameter *allowed-commands* '(look walk pickup inventory help attack quit))

;;;writing a wrapper around eval to use in our game-repl above so that we can use eval safely
;;;check if the first argument for the users input is a member of the list *allowed-commands*
;;;if it is then we can use eval on it, if not return the text
(defun game-eval (sexp)
	(if (member (car sexp) *allowed-commands*)	;if (car sexp) is a member of the list of allowed commands
		(eval sexp)								;true
		'(I do not know that command.)))		;nil


;;;this function tweaks our output text, it adds proper capitalization and other decorations
(defun tweak-text(lst caps lit)
	(when lst
	(let ((item (car lst))
		  (rest (cdr lst)))
	(cond ((eql item #\space) (cons item (tweak-text rest caps lit)))
		  ((member item '(#\! #\? #\.)) (cons item (tweak-text rest t lit)))
		  ((eql item #\") (tweak-text rest caps (not lit)))
		  (lit (cons item (tweak-text rest nil lit)))
		  (caps (cons (char-upcase item) (tweak-text rest nil lit)))
		  (t (cons (char-downcase item) (tweak-text rest nil lit)))))))

(defun game-print (lst)
	(princ (coerce (tweak-text (coerce (string-trim "() "
													 (prin1-to-string lst))
										'list)
								t
								nil)
					'string))
	(fresh-line))


;;;clear the window, print a opening message then begin the game
(screen:clear-window (screen:make-window))
(princ "Welcome to **your game here**" (fresh-line))
(princ "                        "(fresh-line))
(princ "    ####        ####    "(fresh-line))
(princ "    ####        ####    "(fresh-line))
(princ "    ####        ####    "(fresh-line))
(princ "					    "(fresh-line))
(princ "##                    ##"(fresh-line))
(princ "##                    ##"(fresh-line))
(princ " ##                  ## "(fresh-line))
(princ "  ##                ##  "(fresh-line))
(princ "   ##################   "(fresh-line))
(princ "    ################    "(fresh-line))
(princ "                        "(fresh-line))
(princ '(type help for a list of commands)(fresh-line))
(game-repl)

