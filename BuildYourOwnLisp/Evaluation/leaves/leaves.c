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

/*use operator string to see which operator to perform*/
long eval_op(long x, char* op, long y) {
    
    if (strcmp(op, "+") == 0 ) { return x + y; }
    if (strcmp(op, "-") == 0 ) { return x - y; }
    if (strcmp(op, "*") == 0 ) { return x * y; }
    if (strcmp(op, "/") == 0 ) { return x / y; }
    if (strcmp(op, "%") == 0 ) { return x % y; }
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
    
    int i = 3;
    while (strstr(t->children[i]->tag, "expr")) {
        x = eval_op(x, op, eval(t->children[i]));
        i++;
    }

    return x;
}

int leaves (mpc_ast_t *t) {

    if (strstr(t->tag, "number"))   { return 1; }
    if (strstr(t->tag, "operator")) { return 1; }
    else {
        int total = 0;
        for (int i = 0; i < t->children_num; i++) {
            total = total + leaves(t->children[i]);
        }
        return total;
    }
    return 0;
}




int main(int argc, char** argv){
    
    mpc_parser_t* Number    = mpc_new("number"); 
    mpc_parser_t* Operator  = mpc_new("operator"); 
    mpc_parser_t* Expr      = mpc_new("expr"); 
    mpc_parser_t* Lispy     = mpc_new("lispy"); 

   mpca_lang(MPCA_LANG_DEFAULT,
           "                                                                \
                number      :   /-?[0-9]+/                            ;     \
                operator    :   '+' | '-' | '*' | '/' |  '%'          ;     \
                expr        :   <number> | '(' <operator> <expr>+ ')' ;     \
                lispy       :   /^/ <operator> <expr>+ /$/            ;     \
           ",
           Number, Operator, Expr, Lispy);
    
    puts("Leaver Version 0.0.0.0.3\n");
    puts("Press Ctrl+c to Exit\n");
    //puts("..or just kill yourself.. \n");
    
    while (1) {
    
        char *input = readline("leaver$ ");
        add_history(input);

        mpc_result_t r;
        if (mpc_parse("<stdin>", input, Lispy, &r)) {
        
            int result = leaves(r.output);
            printf("%i\n", result);
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