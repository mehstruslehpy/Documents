;;;clear the window
;(screen:clear-window (screen:make-window))

;;;define a global parameter called nodes containing lists of scenery info
;;;this is called an association list or alist
(defparameter *nodes* '((living-room (you are in the living room. a wizard is snoring loudly on the couch.))
						(garden (you are in a beautiful garden. there is a well in front of you.))
						(attic (you are in the attic. there is a giant welding torch in the corner.))))

;;;define a command/function that describes a location
;;;assoc finds an item in a list based on a key (assoc 'keyname listname)
;;;our function works like this: (describe-location 'keyname listname)
;;;cadr == (car(cdr())) == return everything but the first, then return the first from 
;;;this removes the location name from the assoc command leaving only the description
(defun describe-location (location nodes)
	(cadr (assoc location nodes)))

;;;this is the list of "edges" connecting our graph nodes together... Basically they are paths
;;;between the nodes of our graph like this
;;;
;;;
;;;      [node1]
;;;         |                [node4]
;;;         |edge            /
;;;         |               /edge
;;;         |     edge     /
;;;      [node2]--------[node3]
;;;
;;;
(defparameter *edges* '((living-room (garden west door)
									(attic upstairs ladder))
						(garden (living-room east door))
						(attic (living-room downstairs ladder))))

;;;like previously we will create a function to describe a single path
;;;the ` character changes us to data mode and the , character flips us back
;;; caddr == (car(cdr(cdr()))) && cadr == (car(cdr()))
;;;so really it is a string that becomes: there is a ???? going ???? from here
;;;with the ???? swapped for the expansions on the input variable
;;; ' and ` switch lisp into data mode but only ` can be unquoted from inside of using , characters
(defun describe-path (edge)
	`(there is a ,(caddr edge) going ,(cadr edge) from here.))

;;;this function describes all the paths possible from your current node
;;;it takes in a specific location from the *nodes* global variable and a list of possible edges
;;;(cdr(assoc location edges))
;;;ex: (cdr (assoc 'living room *edges*)) == from our edges variable grab the sublists of the 
;;;'living-room sublist return all but the first(the name)
;;;mapcar: takes a function and a list applies the input function to ever member of the list
;;;ex: (mapcar #'function-name '(listelem1 listelem2 listelem3 list elem4))
(defun describe-paths (location edges)
	(apply #'append (mapcar #'describe-path (cdr (assoc location edges)))))

;;;this global variable will represent a list of objects
(defparameter *objects* '(whiskey bucket frog chain dank-meme))
;;;this global variable tracks the location of various object locations
(defparameter *object-locations* '((whiskey living-room)
								   (bucket living-room)
								   (chain garden)
								   (dank-meme attic)
								   (frog garden)))

;;;a function to list visible objects in a given location
;;;labels command allows you to define a local function in this case at-loc-p
;;;at-loc-p:  take a symbol for an object and return t or nil depending on whether the object is at the location loc
;;;t f functions are called predicates hence why it is called at-loc-p
;;;remove-if-not returns a list for which all things for which at-loc-p does not return true for are removed..
(defun objects-at (loc objs obj-locs)
	(labels ((at-loc-p (obj)
				(eq (cadr (assoc obj obj-locs)) loc)))
		(remove-if-not #'at-loc-p objs)))

;;;describe-objects: describes visible objects
;;;describe-obj describes an individual object
;;;this function is applied to each object returned for objects-at via the mapcar function
;;;this returned from that is appended together via the apply function
(defun describe-objects (loc objs obj-loc)
	(labels ((describe-obj (obj)
			`(you see a ,obj on the floor.)))
		(apply #'append (mapcar #'describe-obj (objects-at loc objs obj-loc)))))

;;;tieing all this together
;;this variable describes the players starting location
(defparameter *location* 'living-room)

;;;look around the current location..
(defun look ()
	(append (describe-location *location* *nodes*)
		(describe-paths *location* *edges*)
		(describe-objects *location* *objects* *object-locations*)))

;;;now we can define a walk function to change our location
;;;first we grab a list of available directions and assign that to next using find
;;;find searches a list for an item and returns that item then we select the item we want using cadr on the return from find
;;;if next is not nil we assign the location to the value of (car next) then call the look function to take a look around the
;;;new location
(defun walk (direction)
	(let ((next (find direction
					(cdr (assoc *location* *edges*))
					:key #'cadr)))
	(if next
		(progn (setf *location* (car next))
			   (look))
		'(you cannot go that way.))))

;;;(pickup 'object): picks up an object
;;;check if the input object is a member of whatever objects-at returns if it is then place the object on the players body
;;;if now print you cannot get that
(defun pickup (object)
	(cond ((member object
				  (objects-at *location* *objects* *object-locations*))
		   (push (list object 'body) *object-locations*)
		   	`(you are now carrying the ,object))
		   (t '(you cannot get that.))))

;;;(inventory): displays the player inventory
(defun inventory()
	(cons 'items- (objects-at 'body *objects* *object-locations*)))

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

;;;an attack function that makes fun of you for now..
(defun attack ()
	'(Hahahahahaha do not be silly!))

;;and a help command for user convenience
(defun help ()
		(princ "COMMANDS: ")
		*allowed-commands*)

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
(princ "Welcome to DungeonSplorer 0.1 :D" (fresh-line))
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

