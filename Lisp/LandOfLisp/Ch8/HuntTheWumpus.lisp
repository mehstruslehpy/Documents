;;;load our graph-util tools
(load "graph-util")

;;;set up globals
(defparameter *congestion-city-nodes* nil)
(defparameter *congestion-city-edges* nil)
(defparameter *visited-nodes* nil)
(defparameter *node-num* 30)				;;congestion city has 30 nodes
(defparameter *edge-num* 45)				;;congestion city has 45 edges
(defparameter *worm-num* 3)					;;congestion city has 3 worm teams
(defparameter *cop-odds* 15)				;;each street has a 1 in 15 chance of cop roadblocks

;;;### create a random list of edges to connect all the nodes... ###;;;

;;;the random-node function returns a random node identifier by using the random function which
;;;returns a random natural number less that the integer you pass to it we 1 via the +1 function to that
;;;to ensure our random node is 1 thru 30 and not 0 thru 29
(defun random-node ()
	(1+ (random *node-num*)))

(defun edge-pair (a b)
	(unless (eql a b)
		(list (cons a b) (cons b a))))

;;;the make-edge-list generates the list of random edges it uses loop to loop *edge-num* of times and collects the edges created
;;;the city graph is undirected so we use the helper function edge-pair to create two directed edges between the randomly selected nodes
;;;because a->b & b->a = a<->b or a-b an undirected graph
(defun make-edge-list ()
	(apply #'append (loop repeat *edge-num*
						  collect (edge-pair (random-node) (random-node)))))

;;;### preventing islands ###;;;

;;;finds all the edges in an edge list that start from a node
(defun direct-edges (node edge-list)
	(remove-if-not (lambda (x)
					(eql (car x) node))
					edge-list))

;;;returns a list of all nodes connected to the given node
(defun get-connected (node edge-list)
	(let ((visited nil))
		(labels ((traverse (node)
					(unless (member node visited)
						(push node visited)
						(mapc (lambda (edge)
								(traverse (cdr edge)))
							  (direct-edges node edge-list)))))
		(traverse node))
	visited))

;;;takes all nodes and a list of edges returns a list of islands
;;;it has a local function called find-island that pushes an island to a list and
;;;recurses for every time that we find an island then after all the islands are found
;;;it returns the list of islands
(defun find-islands (nodes edge-list)
	(let ((islands nil))
		(labels ((find-island (nodes)
					(let* ((connected (get-connected (car nodes) edge-list))
						   (unconnected (set-difference nodes connected)))
					  (push connected islands)
					  (when unconnected
					  	(find-island unconnected)))))
		(find-island nodes))
	islands))

;;;when their are islands we return an edge pair to connect the new islands
(defun connect-with-bridges (islands)
	(when (cdr islands)
		(append (edge-pair (caar islands) (caadr islands))
				(connect-with-bridges (cdr islands)))))

;;;tie our island prevention functions into one function which takes a list of nodes and edges and returns a fully connected landmass
(defun connect-all-islands (nodes edge-list)
	(append (connect-with-bridges (find-islands nodes edge-list)) edge-list))

;;;### build the final edges for the city ###;;;

;;;
(defun make-city-edges ()
	(let* ((nodes (loop for i from 1 to *node-num*
						collect i))										;;;create a list of nodes
			(edge-list (connect-all-islands nodes (make-edge-list)))	;;;make a list of edges using the nodes
			(cops (remove-if-not (lambda(x) 							
								   (zerop (random *cop-odds*)))			;;;randomly create a list of the edges that contain cops
								  edge-list)))
		(add-cops (edges-to-alist edge-list) cops)))					;;;convert the list of edges to an alist and add cops to it

;;;convert a list of edges to an alist of edges
(defun edges-to-alist (edge-list)
	(mapcar (lambda (node1)														;;;mapcar with this lambda function over the edge list
				(cons node1														;;;
					(mapcar (lambda (edge)
							  (list (cdr edge)))
							(remove-duplicates (direct-edges node1 edge-list)
												:test #'equal))))
			(remove-duplicates (mapcar #'car edge-list))))

;;;randomly adds cops to edges of nodes
(defun add-cops (edge-alist edges-with-cops)
	(mapcar (lambda (x)															
				(let ((node1 (car x))
					  (node1-edges (cdr x)))
			      (cons node1
				  		(mapcar (lambda (edge)
								  (let ((node2 (car edge)))
								  	(if (intersection (edge-pair node1 node2)
													  edges-with-cops
													  :test #'equal)
										(list node2 'cops)
									edge)))
								node1-edges))))
			edge-alist))

;;;### building the nodes for the city ###;;;

;;;returns the neighbors of a given node
(defun neighbors (node edge-alist)
	(mapcar #'car (cdr (assoc node edge-alist))))	

;;;uses the previous function to determine if we are within one of a node of interest
(defun within-one (a b edge-alist)
	(member b (neighbors a edge-alist)))

;;;uses the previous function and a lambda to tell us if we are within two of a node of interest
(defun within-two (a b edge-alist)
	(or (within-one a b edge-alist)
		(some (lambda (x)
				(within-one x b edge-alist))
			  (neighbors a edge-alist))))

;;;build the map of the game
(defun make-city-nodes (edge-alist)
	(let ((wumpus (random-node))												;;;pick random nodes for wumpus
		  (glow-worms (loop for i below *worm-num* 								;;;and for glow worms
		  				collect (random-node))))
		(loop for n from 1 to *node-num*										;;;run thru node nums build description for each node
			collect (append (list n)											
							(cond ((eql n wumpus) '(wumpus))
								  ((within-two n wumpus edge-alist) '(blood!)))
							(cond ((member n glow-worms)
								  '(glow-worm))
								  ((some (lambda (worm)
								  			(within-one n worm edge-alist))
											glow-worms)
									'(lights!)))
							(when (some #'cdr (cdr (assoc n edge-alist)))
								'(sirens!))))))
;;;### initialize a new game ###;;;

;;;this will init a new game
(defun new-game ()
	(setf *congestion-city-edges*	(make-city-edges))
	(setf *congestion-city-nodes*	(make-city-nodes *congestion-city-edges*))
	(setf *player-pos*				(find-empty-node))
	(setf *visited-nodes*			(list *player-pos*))
	(draw-city)
	(draw-known-city)
	(start-repl)	(opening-text)
	)

;;;finds an empty node
(defun find-empty-node ()
	(let ((x (random-node)))
		(if (cdr (assoc x *congestion-city-nodes*))
			(find-empty-node)
			x)))
;;;draw the city
(defun draw-city ()
	(ugraph->png "city" *congestion-city-nodes* *congestion-city-edges*))

;;;### drawing city from partial knowledge ###;;;
(defun known-city-nodes ()
	(mapcar (lambda (node)
				(if (member node *visited-nodes*)
					(let ((n (assoc node *congestion-city-nodes*)))
						(if (eql node *player-pos*)
							(append n '(*))
							n))
					(list node '?)))
			(remove-duplicates 
				(append *visited-nodes*
					(mapcan (lambda (node)
								(mapcar #'car
									(cdr (assoc node
												*congestion-city-edges*))))
						*visited-nodes*)))))

;;;
(defun known-city-edges ()
	(mapcar (lambda (node)
				(cons node (mapcar (lambda (x)
									(if (member (car x) *visited-nodes*)
										x
										(list (car x))))
								   (cdr (assoc node *congestion-city-edges*)))))
			*visited-nodes*))

;;;
(defun draw-known-city ()
	(ugraph->png "known-city" (known-city-nodes) (known-city-edges)))

;;;### walking around the town ###;;;

(defun walk (pos)
	(handle-direction pos nil)
	(mapcar #'car (cdar (direct-edges *player-pos* *congestion-city-edges*)))
	(princ ""))	

(defun charge (pos)
	(princ "You only have one bullet if you waste it you're toast. Are you sure? (y/n)")
	(setq input (read))
	(if (equal input 'y) (handle-direction pos t)(princ "Better not try it.."))
	(princ ""))

;;(defun charge (pos)
;;	(princ "You only have one bullet if you waste it you're toast. Are you sure? (y/n)")
;;	(let (input (read-from-string)
;;	(if (eq input "y") (princ "OKIE-DOKIE")(handle-direction pos t))
;;	(handle-direction pos t))))


(defun handle-direction  (pos charging)
	(let ((edge (assoc pos
					   (cdr (assoc *player-pos* *congestion-city-edges*)))))
	  (if edge 
	  		(handle-new-place edge pos charging)
			(princ "That location does not exist!"))))

(defun handle-new-place (edge pos charging)
	(let* ((node (assoc pos *congestion-city-nodes*))
		   (has-worm (and (member 'glow-worm node)
		   				  (not (member pos *visited-nodes*)))))
	  (pushnew pos *visited-nodes*)
	  (setf *player-pos* pos)
	  (look-around)	;;;every time we walk we should print out info
	  (draw-known-city)
	  (cond ((member 'cops edge) (clear-screen)(princ "You run into some cops. \"He\'s coming right for us!\" One yells as they begin unloading shot after endless shot into your pale rotund body. Game over."))
	  		((member 'wumpus node) (clear-screen)(if charging
														(princ "You surprised the Wumpus and shot him in his leathery gut. He screams out in pain \"RAAAARRGGHHHH!!!\" You win!")
														(princ "You bumped into the Wumpus! Before you can react he pounces upon you, ripping you apart limb from limb. You lose."))(princ ""))
			(charging (clear-screen)(princ "You wasted your last bullet. Game over.")(princ ""))
			(has-worm (let ((new-pos (random-node)))
						(clear-screen)(princ "You ran into a Glow Worm Gang! They force you into a sack then drive you around for hours before kicking you out onto a random street")(fresh-line)(princ "")
						(handle-new-place nil new-pos nil))))
						))

;;;a function to handle looking around for the user
(defun look-around ()
	  (princ "######################################################################################################################################################")(fresh-line)
	  (retrieve-visual)
	  (princ "You are currently at node: ") (fresh-line)
	  (princ *player-pos*) (fresh-line)
	  (princ "You see the following paths: ") (fresh-line)
	  (princ (mapcar #'car (cdar (direct-edges *player-pos* *congestion-city-edges*)))) (fresh-line)
	  (princ ""))

(defun opening-text ()
	(princ "Welcome to Hunt The Wumpus. You are lost in the seedy underbelly of a sprawling metropolitan city. You must hunt down and kill the dastardly Wumpus.") (fresh-line)
	(help)
	(look-around))

(defun help ()
	
	(princ "Commands: look-around, walk, charge, new-game, help, quit, clear-screen, view-known-map, restart-repl") (fresh-line)(fresh-line)
	(princ ""))

(defun clear-screen ()
	(ext:shell "clear")
	(princ ""))

(defun retrieve-visual ()
	(let (location-info) 1)
	(setq location-info (cdr (assoc *player-pos* *congestion-city-nodes*)))
	(if (member 'SIRENS! location-info)
		(princ "You hear a siren faintly in the distance but you cannot tell which direction it is coming from. "))		
	(fresh-line)
	(if (member 'LIGHTS! location-info)
		(princ "The area glimmers under a faint light. "))	
	(fresh-line)
	(if (member 'BLOOD! location-info)
		(princ "Blood is splattered gruesomely around your current location. "))
	(fresh-line)
	(if (eq nil location-info)
		(princ "Your current location is eerily silent and visually unremarkable. ")
		)
	(fresh-line)
)

;;;this is not portable, viewnior will need to be swapped for the current users image viewer
(defun view-known-map ()
	(let ((*standard-output* (make-broadcast-stream)))
	(ext:shell "viewnior known-city.png &> /dev/null"))
	(princ ""))

(defun start-repl () 
	(load "repl-tools"))

(defun restart-repl () 
	(load "repl-tools"))
(new-game)
