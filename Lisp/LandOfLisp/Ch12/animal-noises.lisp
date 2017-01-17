;;;this will define a global parameter *animal-noises and read the values contained in "animal-noises.txt" into it
(defparameter *animal-noises* 
  (with-open-file (my-stream "animal-noises.txt" :direction :input) 
    (read my-stream)))
