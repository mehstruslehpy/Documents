;;;## types of monsters ##;;

;;;the wicked orc
;;;we are creating our orc type by including the fields from our monster type in our orc type 
;;;this way the orc inherits all the fields that apply to all monsters
;;;the orc differs from a generic monster in that it has a 'club-level' that affects its attack
(defstruct (orc (:include monster)) (club-level (randval 8)))
;;;push our orc instantiation function to our array of monster building functions so orcs can be generated
(push #'make-orc *monster-builders*)

;;;specializing some of our generic functions for orcs
(defmethod monster-show ((m orc))
  (princ "A wicked orc with a level ")
  (princ (orc-club-level m))
  (princ " club"))

(defmethod monster-attack ((m orc))										;m is of type orc for this method
  (let ((x (randval (orc-club-level m))))
       (princ "An orc swings his club at you and knocks off ")			;this would be nicer with random names
	   (princ x)
	   (princ " of your health points.")
	   (fresh-line)
	   (decf *player-health*)))

;;;the malicious hydra
(defstruct (hydra (:include monster)))
(push #'make-hydra *monster-builders*)

(defmethod monster-show ((m hydra))
  (princ "A malicious hydra with ")
  (princ (monster-health m))
  (princ " heads."))

(defmethod monster-hit ((m hydra) x)								;of type hydra with a second argument that is x
  (decf (monster-health m) x)
  (if (monster-dead m)
      (princ "The corpse of the fully decapitated and decapacitated hydra falls to the floor!")	;if
	  (progn (princ "You lop off ")																;else
	         (princ x)
			 (princ " of the hydra's heads! "))))

(defmethod monster-attack ((m hydra))
  (let ((x (randval (ash (monster-health m) -1))))
    (princ "A hydra attacks you with ")
	(princ x)
	(princ " of its heads! It also grows one more head! ")
	(fresh-line)
	(incf (monster-health m))
	(decf *player-health* x)))

;;;the slimy slime mold
(defstruct (slime-mold (:include monster)) (sliminess (randval 5)))
(push #'make-slime-mold *monster-builders*)

(defmethod monster-show ((m slime-mold))
  (princ "A slime mold with a sliminess of ")
  (princ (slime-mold-sliminess m)))

(defmethod monster-attack ((m slime-mold))
  (let ((x (randval (slime-mold-sliminess m))))
       (princ "A slime mold wraps around your leg and decreases your agility by ")
	   (princ x)
	   (princ "! ")
	   (decf *player-agility* x)
	   (when (zerop (random 2))														;slimes take away health randomly
	     (princ "It also squirts in your face taking away a health point! ")
		 (decf *player-health*))
		 (fresh-line)))

;;;the cunning brigand
(defstruct (brigand (:include monster))) 
(push #'make-brigand *monster-builders*)

(defmethod monster-attack ((m brigand))
  (let ((x (max *player-health* *player-agility* *player-strength*)))
    (cond ((= x *player-health*)
	       (princ "A brigand hits you with his slingshot, taking off 2 health points! ")
		   (decf *player-health* 2))
		  ((= x *player-agility*)
		   (princ "A brigand catches your leg with his whip, taking off 2 agility points! ")
		   (decf *player-agility* 2))
		  ((= x *player-strength*)
		   (princ "A brigand cuts your arm with his whip, taking off 2 strength points! ")
		   (decf *player-strength* 2)))
		   (fresh-line)))

