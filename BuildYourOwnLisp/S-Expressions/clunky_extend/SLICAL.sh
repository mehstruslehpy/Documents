#########################################################################
#THIS WOULD WORK BUT FP OPERATIONS WOULD NOT BE COMPATIBLE WITH INTEGERS#
#########################################################################

#!/bin/bash

	case "$1" in
		-i|--integer)
			./s_expr.o
			;;
		-d|--double)
			./s_expr_dbl.o
			;;
		-h|--help|*)
		echo "usage: SLICAL.sh [--option/-option]"
		echo "		-i --integer: the integer calculator"
		echo "		-d --double: the double calculator"
		;;
	esac
