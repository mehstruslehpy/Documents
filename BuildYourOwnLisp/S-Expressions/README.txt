The overall 'idea' behind these examples is to transform an mpc_ast_t to an lval
	This is done through the lval_read function which accepts the tree, iterates through branches and returns an lval*
	the lval_read function can branch out to the lval_read_dec, lval_read_num, lval_sym, lval_sexpr.

The end of lval_read should call lval_add which adds a new child to the lval 'tree' it also recursively calls lval_read as an input to lval_add.

this combination should iterate through all children of the mpc_ast_t input returning a corresponding lval tree

##############
INSIDE OF MAIN
##############

lval_read is an input to the function lval_eval
lval_eval works together recursively with lval_eval_sexpr by calling each other
these two functions iterate through all lvals and lval children
checking for errors
and other miscellaneous things on the children
	
eventually through this process lval_eval_sexpr will call builtin_op which evaluates the math of the input lval/mpc_ast_t
the builtin_op function returns an lval to the next outer function in this recursive loop

through this process the lval_eval function can evaluate all mathematical expressions input that follow it's grammar. 

This program is an example of recursion, transformations and some other neat stuff.

I personally extended the original source to allow input of long integers such as [prefix][number] Ex: i1, i1230, i999999
I also added the same ability with decimals such as [prefix][number].[number]

this allows my finished program to operate on integers AND decimals. (though they are not cross compatible)

####
MISC
####

The whole thing is kind of abstracted into object orientation for the sake of generating the lval tree by using functions such as: 
lval_sexpr(), lval_sym(), lval_err(), lval_num; as constructors. 

For the four previous constructors we have ONE destructor function called lval_del().
