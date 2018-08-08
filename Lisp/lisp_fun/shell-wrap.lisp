(ql:quickload 'inferior-shell)

;not using princ
(defun shell-noprinc (cmd)
 (inferior-shell:run/ss cmd))
;formatted shell output
(defun shell-formatted (cmd)
 (princ "SHELL OUTPUT BEGIN: ")
 (fresh-line)
 (princ (inferior-shell:run/ss cmd))
 (fresh-line)
 (princ "SHELL OUTPUT END: ")
 (fresh-line))
;unformatted shell output
(defun shell-unformatted (cmd)
 (princ (inferior-shell:run/ss cmd)))
;the default
(defun shell (cmd)
 (shell-formatted cmd))
