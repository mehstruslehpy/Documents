#include "mpc.h"

#ifdef _WIN32

static char buffer[2048];

char* readline(char* prompt) {
	fputs(prompt, stdout);
	fgets(buffer, 2048, stdin);
	char* cpy = malloc(strlen(buffer)+1);
	strcpy(cpy, buffer);
	cpy[strlen(cpy-1)] = '\0';
	return cpy;
}

void add_history(char* unused) {}

#else
#include <editline/readline.h>
#endif

/*create enumeration of possible error types*/
enum { LERR_DIV_ZERO, LERR_BAD_OP, LERR_BAD_NUM };

/*create enumuration of possible lval types*/
enum { LVAL_LONG, LVAL_ERR, LVAL_DBL };

/*declare new lval struct*/
typedef struct {
	int type;
	double numd;
	long numl;
	int err;
} lval;

//originally lval_num
/*a function that creates/returns a new number type lval*/
lval lval_long(long x) {

	lval v;
	v.type  = LVAL_LONG;
	v.numl  = x;
	return v;

}

lval lval_dbl(double x) {

	lval v;
	v.type  = LVAL_DBL;
	v.numd  = x;
	return v;

}

/*a function that creates/returns a new error type lval*/
lval lval_err(int x) {

	lval v;
	v.type = LVAL_ERR;
	v.err  = x;
	return v;

}

/*print an lval*/
void lval_print(lval v) {
	
	switch (v.type) {
		/*in the case that the type is a long print it*/
		case LVAL_LONG: printf("%li", v.numl); break;

		/*in the case that the type is a double print it*/
		case LVAL_DBL: printf("%ff", v.numd); break;
		
		/*in the case that the type is an error*/
		case LVAL_ERR:
			/*check what type of error it is and print it*/
			if (v.err == LERR_DIV_ZERO) {
				printf("ERROR: Division By Zero!");
			}
			if (v.err == LERR_BAD_OP) {
				printf("ERROR: Invalid Operator");
			}
			if (v.err == LERR_BAD_NUM) {
				printf("ERROR: Invalid Number");
			}
		break;
		}
}

/*print an "lval" followed by a newline*/
void lval_println(lval v) { 

	lval_print(v); 
	putchar('\n'); 
}

lval eval_op(lval x, char* op, lval y) {
	
	/*if either value is an error return it*/
	if (x.type == LVAL_ERR) { return x; }
	if (y.type == LVAL_ERR) { return y; }
	if (x.type == LVAL_LONG && y.type == LVAL_LONG) {
		/*otherwise do some maths on the number values*/
		if (strcmp(op, "+") == 0) { return lval_long(x.numl + y.numl); }	
		if (strcmp(op, "-") == 0) { return lval_long(x.numl - y.numl); }	
		if (strcmp(op, "*") == 0) { return lval_long(x.numl * y.numl); }	
		if (strcmp(op, "/") == 0) { return y.numl == 0 ? lval_err(LERR_DIV_ZERO) : lval_long(x.numl / y.numl); }	
	}	
	if (x.type == LVAL_DBL && y.type == LVAL_DBL) {
	
	/*if either value is an error return it*/
	if (x.type == LVAL_ERR) { return x; }
	if (y.type == LVAL_ERR) { return y; }
	if (x.type == LVAL_LONG && y.type == LVAL_LONG) {
		/*otherwise do some maths on the number values*/
		if (strcmp(op, "+") == 0) { return lval_dbl(x.numd + y.numd); }	
		if (strcmp(op, "-") == 0) { return lval_dbl(x.numd - y.numd); }	
		if (strcmp(op, "*") == 0) { return lval_dbl(x.numd * y.numd); }	
		if (strcmp(op, "/") == 0) { return y.numd == 0 ? lval_err(LERR_DIV_ZERO) : lval_dbl(x.numd / y.numd); }	
		
		} else {
		printf("TYPE MISMATCH");
		}
	}
		return lval_err(LERR_BAD_OP);	
}

lval eval(mpc_ast_t* t) {

	/*we need to make this conditional based on a second number parser for doubles*/
	if (strstr(t->tag, "long")) {
			errno = 0;
			long x = strtol(t->contents, NULL, 10);
			return errno != ERANGE ? lval_long(x) : lval_err(LERR_BAD_NUM);
	}
	/*this is for doubles (see prev comment) IT DOES NOT WORK RIGHT*/
	if (strstr(t->tag, "double")) {
			errno = 0;
			double x = strtol(t->contents, NULL, 10);
			return errno != ERANGE ? lval_dbl(x) : lval_err(LERR_BAD_NUM);
	}

	char *op = t->children[1]->contents;

	lval x = eval(t->children[2]);

	int i = 3;
	while (strstr(t->children[i]->tag, "expr")) {
		x = eval_op(x, op, eval(t->children[i]));
		i++;
	}
	return x;
}

int main(int argc, char** argv) {
	
	///create some parsers
	mpc_parser_t* Long        = mpc_new("long");
	mpc_parser_t* Double      = mpc_new("double");
	mpc_parser_t* Operator    = mpc_new("operator");
	mpc_parser_t* Expr        = mpc_new("expr");
	mpc_parser_t* Lispy       = mpc_new("lispy");

	//define them with the following language
	mpca_lang(MPCA_LANG_DEFAULT,
		"                                                             \
        	operator    : '+' | '-' | '*' | '/' | '%' ;               \
            long        : /-?[0-9]+/ ;								  \
            double 		: 'd'/-?[0-9]/  '.' /[0-9]+/ ;			          \
            expr        : <long> | <double> | '(' <operator> <expr>+ ')' ;     \
            lispy       : /^/ <operator> <expr>+ /$/ ;                \
        ",
    	Long, Double, Operator, Expr, Lispy);


	puts("Slispy: 0.0.0.0.4\n");
	puts("Press Ctrl+c to Exit.\n");

	while (1) {
	
	char* input = readline("Slispy& ");
	add_history(input);

	mpc_result_t r;
		if (mpc_parse("<stdin>", input, Lispy, &r)) {
			lval result = eval(r.output);
			lval_println(result);
			mpc_ast_delete(r.output);
		} else {
			mpc_err_print(r.error);
			mpc_err_delete(r.error);
		}

	free(input);	

	}
	
	mpc_cleanup(4, Long, Double, Operator, Expr, Lispy);

	return 0;

}
