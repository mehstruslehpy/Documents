;;;cdr of the third cons cell will refer back to the first cons cell
(setf *print-circle* t)

;;;def a three element list called foo
(defparameter foo '(1 2 3))

;;;replace the nil at the end with a link to the first element
(setf (cdddr foo) foo)
;;;#1=(1 2 3 . #1#) rather than (1 2 3 . nil)

;;;

