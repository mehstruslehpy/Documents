dnl defines a forloop macro, I did not write this code
dnl forloop(var, from, to, stmt) - simple version
define(`forloop', `pushdef(`$1', `$2')_forloop($@)popdef(`$1')')dnl
define(`_forloop',
       `$4`'ifelse($1, `$3', `', `define(`$1', incr($1))$0($@)')')dnl
