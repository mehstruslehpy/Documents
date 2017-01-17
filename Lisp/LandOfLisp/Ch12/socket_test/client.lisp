(defparameter my-stream (socket-connect 4323 "127.0.0.1")) ;on the client connect to the server                                                                         

(defun write-msg (x)
  (print x my-stream))

(defun read-msg ()
  (read my-stream))

(defun close-chat ()
  (close my-stream))
