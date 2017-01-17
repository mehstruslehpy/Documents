;;;start the server
(defun init-server ()
  (defparameter my-socket (socket-server 4323)) ;this is run on the server to grab a socket from the os
  (defparameter my-stream (socket-accept my-socket))) ;this is run on the server to open a stream on that socket
;;;NOTE:
;;;  you can check the server is running with netstat -an | grep [PORTNUMBER]
;;;  the server will wait initially for the client to send a msg

;;;read the stream for any new messages
;;;ex: (read)
(defun read-msg ()
  (read my-stream))

;;;write to the stream to communicate back to the client
;;;ex: (write-msg "Hey client")
(defun write-msg (x)
  (print x my-stream))

;;;end the session
;;;ex: (close-chat)
(defun close-chat ()
  (close my-stream)
  (socket-server-close my-socket)
  (ext:shell "fuser -k -n tcp 4323"))
;;;NOTE: if you get stuck with open listening ports and no pid you can do
;;;	fuser -k -n tcp [PORTNUMBER]
;;;because my ports aren't closing fast enough I've added it in to the close-chat function
