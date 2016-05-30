    › What are the four typical steps for adding new language features?

		FROM THE TEXT:

			1. Syntax:	Add new rule to the language grammar for this feature. 
				In the examples rules for "qexprs" (Quoted-Expressions) were added into mpca_lang()'s arguments
			2. Representation:	Add new data type variation to represent this feature.
				LVAL_QEXPR was added to our enums at the start and is used in the original lval as lval->type
			3. Parsing:	Add new functions for reading this feature from the abstract syntax tree.
				Tons of new functions got added and modified. lval_print, lval_del, and lval_read were modified
				for the sake of handling qexprs.
			4. Semantics:	Add new functions for evaluating and manipulating this feature.
				builtin_cons, builtin_len, and builtin_init were personally created via the specs from the reading.
				the rest of the functions were copied from the reading.

    › Create a Macro specifically for testing for the incorrect number of arguments.
			
			This would only require modifying the LASSERT functions in the source
	
			#define NARGS(in_args, nargs, input, err)
				if (in_args != nargs) { lval_del(input); return lval_err(err); }

			USED LIKE THIS:	
			NARGS(input_args, numberofargs, input_lval, "Wrong amount of arguments for function")

    › Create a Macro specifically for testing for being called with the empty list.
				
			I am not at all sure how to macro this but I think it would vaguely resemble this logic:
			
			#define EMPTY(list, err)
				if(list == 0) {lval_del(list); return lval_err(err)}
			
			USED LIKE THIS
		
			EMPTY(input_list, "Input list is empty")
			
