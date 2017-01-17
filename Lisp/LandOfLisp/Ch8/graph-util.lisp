;;;function for converting the node identifiers from above into DOT format identifiers
;;;any forbidden characters get changed to underscores, substitue-if substitutes values
;;;based on the results of a test function, complement inverts #'alphanumericp, and
;;;substitute replaces any non alphanumeric value for _
(defun dot-name (exp)
	(substitute-if #\_ (complement #'alphanumericp) (prin1-to-string exp)))

;;;the length of the label that should appear in the node that is drawn
(defparameter *max-label-length* 30)

;;;generates the label that should appear in the node when it is drawn, consists of 
;;;the nodename and the data linked to the node.
;;;if the label is to long we will conditionally crop it and add an ellipises, :pretty 
;;;is just a parameter to the write-to-string function that removes tabs and newlines  
(defun dot-label (exp)
	(if exp
		(let ((s (write-to-string exp :pretty nil)))
			(if (> (length s) *max-label-length*)
				(concatenate 'string (subseq s 0 (- *max-label-length* 3)) "...")
				s))
	""))

;;;generating dot info for the nodes this function takes an alist
;;;here we are mapping a lambda function to each element of the input nodes
(defun nodes->dot (nodes)
	(mapc (lambda (node)
			(fresh-line)
			(princ (dot-name (car node)))
			(princ "[label=\"")
			(princ (dot-label node))
			(princ "\"];"))
		nodes))

;;;generating dot info for the edges
(defun edges->dot (edges)
	(mapc (lambda (node)
		(mapc (lambda (edge)
				(fresh-line)
				(princ (dot-name(car node)))
				(princ "->")
				(princ (dot-name (car edge)))
				(princ "[label=\"")
				(princ (dot-label (cdr edge)))
				(princ "\"];"))
			(cdr node)))
	edges))

;;;generating all of the dot info using the previous funcitons
(defun graph->dot (nodes edges)
	(princ "digraph{")
	(nodes->dot nodes)
	(edges->dot edges)
		(princ "}"))

;;;turning the previous info into a dot file into a picture
(defun dot->png (fname thunk)
	(with-open-file (*standard-output*
					 fname
					 :direction :output
					 :if-exists :supersede)
	(funcall thunk))
  (ext:shell (concatenate 'string "dot -Tpng -O " fname)))	 

;;;tie everything together by creating a graph from nodes and edges
;;;this function takes a filename a list of nodes and a list of edges
(defun graph->png (fname nodes edges)
	(dot->png fname 
		(lambda () 
			(graph->dot nodes edges))))

;;;function to draw undirected graphs
(defun uedges->dot (edges)
	(maplist (lambda (lst)
				(mapc (lambda (edge)
						(unless (assoc (car edge) (cdr lst))
							(fresh-line)
							(princ (dot-name (caar lst)))
							(princ "--")
							(princ (dot-name (car edge)))
							(princ "[label=\"")
							(princ (dot-label (cdr edge)))
							(princ "\"];")))
						(cdar lst)))
			edges))

(defun ugraph->dot (nodes edges)
	(princ "graph{")
	(nodes->dot nodes)
	(uedges->dot edges)
	(princ "}"))

(defun ugraph->png (fname nodes edges)
	(dot->png fname
		(lambda ()
			(ugraph->dot nodes edges))))
