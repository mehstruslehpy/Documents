;;;### globals ###;;;
(defparameter *width* 100)				;the width of the game world
(defparameter *height* 30)				;the height of the game world
(defparameter *jungle* '(45 10 10 10))	;the first two numbers are the x y coords of the jungles top left corner last two are its width and height
(defparameter *plant-energy* 80)		;if an animal eats a plant it gets 80 days worth of energy

(defparameter *plants* (make-hash-table :test #'equal)) 	;we will store plants in hash table of x y coordinates our equality test is
															;set to equal instead of eq

;;;### functions to grow plants ###;;;
(defun random-plant (left top width height)								;creates a random plant within a specified region
  (let ((pos (cons (+ left (random width)) (+ top (random height)))))	;construct a random location store it in pos 
       (setf (gethash pos *plants*) t))) 								;use setf to indicate the existence of it and store t in the hashtable

(defun add-plants ()
  (apply #'random-plant *jungle*)			;for every game day add aplant to the jungle
  (random-plant 0 0 *width* *height*))		;and add a plant somewhere else on the map

;;;### animals ###;;;

(defstruct animal x y energy dir genes)
		;energy is the amount of energy an animal has left if it runs out the animal dies
		;dir is the direction an animal is facing, an animal will move once each day to a nieghbor square the directions are as follows:
						
						;012
						;7A3		;A is the animal itself
						;654
						
		;genes, an animal has eight integer genes these integers represent eight slots that encircle the animal it uses these genes to determine
		;which direction it should move or if it should continue facing the same direction, it does so by choosing randomly from its genes
		;an example set of genes (1 1 3 7 10 2 1 1) for a number greater than 7 the largest direction the animal will face: (dir mod 8) basically
		;the continue loops back around for example (10 mod 8) is 2

;;;create an animals variable with a single animal
(defparameter *animals*
    (list (make-animal :x      (ash *width* -1)    						;x is the width  / 2
	                   :y      (ash *height* -1)   						;y is the height / 2, so basically start at the center
					   :energy 1000
					   :dir    0										;start off facing the upper left
					   :genes  (loop repeat 8
					                 collecting (1+ (random 10))))))	;loop 8 times collecting a random number inside of 1 thru 10

;;;takes an animal as an argument then move it
(defun move (animal)
  (let ((dir (animal-dir animal))		;grab the direction of the input animal
        (x (animal-x animal))			;grab animal-x from the input animal then store in x
		(y (animal-y animal)))			
  (setf (animal-x animal) (mod (+ x										;mod lets us wrap around we are doing mod with width here
                                  (cond ((and (>= dir 2) (< dir 5)) 1)  ;check if 2 3 or 4 if so the expr is (mod (+ x 1)) animal faces east
								        ((or (= dir 1) (= dir 5)) 0)	;check if 1 or 5   if so the expr is (mod (+ x 0)) animal faces north or south
										 (t -1)))						;else the animal faces west (t means true.. don't forget!)
								*width*))
  (setf (animal-y animal) (mod (+ y 
                                 (cond ((and (>= dir 0) (< dir 3)) -1) ;y coord is adjusted similar to x
								       ((and (>= dir 4) (< dir 7)) 1)
									    (t 0)))
							   *height*))
  (decf (animal-energy animal))))										;decrement our animals energy

(defun turn (animal)
  (let ((x (random (apply #'+ (animal-genes animal)))))   				;sum all the genes then pick a random number to assign to x
    (labels ((angle (genes x)											;create a local function called angle that takes genes and x params
	           (let ((xnu (- x (car genes))))							;car genes, sub x from it if xnu < 0 ,xnu like x-new
			     (if (< xnu 0)
				     0													;then 0
					 (1+ (angle (cdr genes) xnu))))))					;else recursive call on the next element and xnu
     		(setf (animal-dir animal)											;set the animals new direction
			      (mod (+ (animal-dir animal) (angle (animal-genes animal) x))	;if necessary mod it
8)))))

;;;handle animal eating 
(defun eat (animal)														;accept an animal as an argument
  (let ((pos (cons (animal-x animal) (animal-y animal))))				;(cons (grab x)(grab y)) = (x . y) =  pos
    (when (gethash pos *plants*)										;check the animals position against the hash table if on plant
	  (incf (animal-energy animal) *plant-energy*)						;increment animal-energy by plant-energy
	  (remhash pos *plants*))))											;remove that plant from the hashtable of plants

;;;handle animal reproduction
(defparameter *reproduction-energy* 200)

(defun reproduce (animal)
  (let ((e (animal-energy animal)))
    (when (>= e *reproduction-energy*)									;when e >= reproduction energy
	  (setf (animal-energy animal) (ash e -1))							;set the animals current energy to half 
	  (let ((animal-nu (copy-structure animal))							;copy the animal to animal-nu
	        (genes (copy-list (animal-genes animal)))					;copy the genes of the parent animal into genes 
			(mutation (random 8)))										;pick a random number from 0 to 7
	    (setf (nth mutation genes)										;select the mutation=nth of genes
		      (max 1 (+ (nth mutation genes) (random 3) -1)))			;select the max number from 1 to (+ numfromgenes (rand 3) -1)
		(setf (animal-genes animal-nu) genes)							;set the new animals genes to the randomly mutated genes variant
		(push animal-nu *animals*)))))									;push the new animal onto the stack of animals

;;;### simulating a day in our world ###;;;
(defun update-world ()
  (setf *animals* (remove-if (lambda (animal)							;remove the dead animals if they have energy less than or equal to 0
                                 (<= (animal-energy animal) 0))
							 *animals*))
  (mapc (lambda (animal)												;map across all animals this sequence of functions
          (turn animal)
		  (move animal)
		  (eat animal)
		  (reproduce animal))
		  *animals*)
  (add-plants))															;add-plants to the world

;;;### drawing the world ###;;;
(defun draw-world ()
  (ext:shell "clear")
  (ext:shell "figlet \"evolution :\"")
  (princ "Daycount: ")
  (princ *daycount*)
  (incf *daycount*)
  (fresh-line)
  (princ "######################################################################################################")
  (fresh-line)
  (loop for y																		;loop through all the rows use y as a variable
        below *height*																
		do (progn (fresh-line)														;jump to a newline
		          (princ "|")														;print a | for the border
				  (loop for x														;loop thru the columns use x as a variable
				        below *width*
						do (princ (cond ((some (lambda (animal)						;check using some if an animal is at the current location 
						                         (and (= (animal-x animal) x)		;if so princ M
												      (= (animal-y animal) y)))
												*animals*)
										#\M)
										((gethash (cons x y) *plants*) #\*)			;if no animal check for a plant
										 (t #\space))))								;if neither print a space
		   (princ "|")))
  (fresh-line)
  (princ "######################################################################################################")
  (fresh-line))
		   																			;adding a top border
;;;### creating a user interface ###;;;
(defun evolution ()
  (draw-world)
  (fresh-line)
  (let ((str (read-line)))
    (cond ((equal str "quit") ())
	(t (let ((x (parse-integer str :junk-allowed t)))
	     (if x
		     (loop for i
			    below x
				do (update-world)
				if (zerop (mod i 1000))
				do (princ #\.))
				(update-world))
		 (evolution))))))

;;;### my custom stuff ###;;;
(defparameter *daycount* 0)

;;;an autoincrementing screen that counts days
(defun evolution-auto ()
  (draw-world)
  (fresh-line)
  (let ((str "notquit"))
    (cond ((eq str "quit") ())
	(t (let ((x (parse-integer str :junk-allowed t)))
	     (if x
		     (loop for i
			    below x
				do (update-world)
				if (zerop (mod i 1000))
				do (princ #\.))
				(update-world))
		 (sleep 15)
		 (evolution-auto))))))

