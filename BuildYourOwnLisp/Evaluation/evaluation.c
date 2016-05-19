#include "string.h"
#include "mpc.h"

#ifdef _WIN32

static char buffer[2048];

char* readline(char* prompt) {
    fputs(prompt, stdout);
    fgets(buffer, 2048, stdin);
    char *cpy = malloc(strlen(buffer)+1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy)-1] = '\0';
    return cpy;
}

void add_history(char *unused) {}

#else
#include <editline/readline.h>
#endif

//Why won't YOU COMPILE
/*I really need to put all these functions in a header! :[*/
/*base = b, exponent = n; fuck good naming :[*/
long exponent_func(long base, long exp) {

    long temp = base;
    while ( exp != 1 ) {
        temp = temp * base;
        exp = exp - 1;
    }
    return temp;
}

long min_func(mpc_ast_t *t) {
	long smallest = 0;

		//printf("Debug Op0:%d\n", atoi(t->children[2]->contents));
		//printf("Debug Op1:%d\n", atoi(t->children[3]->contents));
		//printf("Debug Op2:%d\n", atoi(t->children[4]->contents));
		
		smallest = atoi(t->children[2]->contents);

		if ( smallest >= atoi(t->children[3]->contents)) {
			smallest = atoi(t->children[3]->contents);
		}
		
		if (smallest >= atoi(t->children[4]->contents)) {
			smallest = atoi(t->children[4]->contents);
		}
		
	return smallest;
}

long max_func(mpc_ast_t *t) {
    long biggest = 0;

        //printf("Debug Op0:%d\n", atoi(t->children[2]->contents));
        //printf("Debug Op1:%d\n", atoi(t->children[3]->contents));
        //printf("Debug Op2:%d\n", atoi(t->children[4]->contents));

        biggest = atoi(t->children[2]->contents);

        if ( biggest <= atoi(t->children[3]->contents)) {
            biggest = atoi(t->children[3]->contents);
        }

        if (biggest <= atoi(t->children[4]->contents)) {
            biggest = atoi(t->children[4]->contents);
        }

    return biggest;
}

/*use operator string to see which operator to perform*/
long eval_op(long x, char* op, long y, mpc_ast_t* t) {
    
    if (strcmp(op, "+") == 0 ) { return x + y; }
    if (strcmp(op, "-") == 0 ) { return x - y; }
    if (strcmp(op, "*") == 0 ) { return x * y; }
    if (strcmp(op, "/") == 0 ) { return x / y; }
    if (strcmp(op, "%") == 0 ) { return x % y; }
	if (strcmp(op, "^") == 0 ) { return exponent_func(x, y); }
    if (strcmp(op, "min") == 0 ) { return min_func(t); }
    if (strcmp(op, "max") == 0 ) { return max_func(t); }

    return 0;

}

long eval(mpc_ast_t* t) {

    /*if tagged as a number return the number directly directly*/
    /*strstr() returns substrings..*/    
    if(strstr(t->tag, "number")) {
        return atoi(t->contents);
    }
    
    /*the operator is always second child*/
    /*member contents, pointed to by index 1, of member children, pointed to by structure t*/
    char* op = t->children[1]->contents;
    
    /*we store the third child in 'x'*/
    long x = eval(t->children[2]);
	
	/*check for negation*/
	if ( strcmp(op, "neg") == 0) {
		x = atoi(t->children[2]->contents);
		x = x - x - x; 
		return x;
	}

    int i = 3;
    while (strstr(t->children[i]->tag, "expr")) {
        x = eval_op(x, op, eval(t->children[i]), t);
        i++;
    }

    return x;
}




int main(int argc, char** argv){
    
    mpc_parser_t* Number    = mpc_new("number"); 
    mpc_parser_t* Operator  = mpc_new("operator"); 
    mpc_parser_t* Expr      = mpc_new("expr"); 
    mpc_parser_t* Lispy     = mpc_new("lispy"); 

   mpca_lang(MPCA_LANG_DEFAULT,
           "                                                                \
                number      :   /-?[0-9]+/                            ;     \
                operator    :   '+' | '-' | '*' | '/' | '%' | '^' | \"min\" | \"max\" \     	
                			|   \"neg\" ; 									\
				expr        :   <number> | '(' <operator> <expr>+ ')' ;     \
                lispy       :   /^/ <operator> <expr>+ /$/            ;     \
           ",
           Number, Operator, Expr, Lispy);
    
    puts("Lipsy Version 0.0.0.0.3\n");
    puts("Press Ctrl+c to Exit\n");
    //puts("..or just kill yourself.. \n");
    
    while (1) {
    
        char *input = readline("lispy$ ");
        add_history(input);

        mpc_result_t r;
        if (mpc_parse("<stdin>", input, Lispy, &r)) {
        
            long result = eval(r.output);
            printf("%li\n", result);
            mpc_ast_delete(r.output);
        
        } else {
            mpc_err_print(r.error);
            mpc_err_delete(r.error);
        }
        
        free(input);
    }

    mpc_cleanup(4, Number, Operator, Expr, Lispy);

    return 0;
}
