;;;an association list - a list built of key value pairs
;;;name keys mapped to drink order keys
(defparameter *drink-order* '((bill . double-espresso)	
							  (lisa . small-drip-coffee)
							  (john . medium-latte)
							  (tammy . skinny-mocha)))

;;;to look up values in our list we can use the assoc key word
(assoc 'lisa *drink-order*)

;;;to add values to the list use push
(push '(jacob . jack-and-coke) *drink-order*)
(push '(samuel . large-strawberry) *drink-order*)
