;;;### description of robots ###;;;

;;;all robots move towards the player 
;;;robot collisions cause scrap that is deadly
;;;teleport as a last resort

;;;### beginning of code###;;;

(defun robots ()
  (loop named main															;by naming it main we can use "return from" to exit early
        with directions = '((q . 65) (w . -64) (e . -63) (a . -1)			;these are 8 offsets when the gameboard is 64 wide
		                    (d . 1 ) (z .  63) (x .  64) (c . 65))
		for pos = 544
		then (progn (format t "~%qwe/asd/zxc to move, (t)eleport (l)eave:")
		            (force-output)
					(let* ((c (read))
					       (d (assoc c directions)))						;assoc performs a lookup
					  (cond (d (+ pos (cdr d)))
					        ((eq 't c) (random 1024))						;board=64*16=1024, pick a random spot
					        ((eq 'l c) (return-from main 'bye))				;player wants to leave
							(t pos))))										;continuation of picking a random spot
		for monsters = (loop repeat 10										;change this value for more robots
		                     collect (random 1024))
		then (loop for mpos in monsters
		           collect (if (> (count mpos monsters) 1)
				               mpos  ;sort locations based on dist to player then chomp off the closest
							   (cdar (sort (loop for (k . d) in directions
							                     for new-mpos = (+ mpos d)
												 collect (cons (+ (abs (- (mod new-mpos 64) ;this block calcs the "manhattan distance" to player
												                          (mod pos 64)))	;and collects it
																  (abs (- (ash new-mpos -6)
																          (ash pos -6))))
															  new-mpos))
											'<
											:key #'car))))
		when (loop for mpos in monsters										;check if all monsters are scrap
		           always (> (count mpos monsters) 1))						;more than one robot in a spot means they are scrap
		return 'player-wins
		do (format t
		           "~%|~{~<|~%|~,65:;~A~>~}|"
				   (loop for p
				        below 1024											;loop through board positions
						collect (cond ((member p monsters)
						               (cond ((= p pos) (return-from main 'player-loses))	;if player is in the same spot as robot they lose
									         ((> (count p monsters) 1) #\#)					;draw scrap for doubled up robots
									         (t #\A)))
									  ((= p pos)
									   #\@)
									  (t
									   #\ ))))))
										
