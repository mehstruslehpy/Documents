(defun ack (m n)
 (cond
  ( (zerop m) (+ n 1) )
  ( (zerop n) (ack (- m 1) 1) )
  (t (ack (- m 1) (ack m (- n 1) ) ) ) ) )

(defun fib (n)
 (cond
  ( (= n 1) 1)
  ( (= n 2) 1)
  (t (+ (fib (- n 1) ) (fib (- n 2) ) ) ) ) )

(defun fibfun (n)
 (cond
  ( (> n 0)
    (princ "index: ") (princ n) (princ " fib: ") (princ (fib n) )
    (fresh-line)
    (fibFun (- n 1) ) )
  ( (princ "...")
    (fresh-line)
    (princ "loop complete")
    (fresh-line) ) ) )

; lisp comment
(defun kilostomiles ()
 (princ "Enter your distance in kilometers:")
 (fresh-line)
 (let ( (kilos (read) ) )
  (princ "Your distance in miles is approximately: ")
  (princ (* kilos 0.62137119223733396962) ) ) )

