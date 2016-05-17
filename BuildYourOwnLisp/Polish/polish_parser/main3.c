#include "mpc.h"

#ifdef _WIN32

static char buffer[2048];

char *readline(char *prompt) {
    fputs(prompt, stdout);
    fgetc(buffer, 2048, stdin);
    char *cpy = malloc(strlen((buffer)+1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy)-1];
    return cpy;
}

void add_history(char *unused) {}

#else
#include <editline/readline.h>
#endif

int main (int argc, char **argv) {
    
    ///create some parsers
    mpc_parser_t* Number      = mpc_new("number");
    mpc_parser_t* Numblock    = mpc_new("numblock");
    mpc_parser_t* Numbertype1 = mpc_new("numbertype1");
    mpc_parser_t* Numbertype2 = mpc_new("numbertype2");
    mpc_parser_t* Operator    = mpc_new("operator");
    mpc_parser_t* Expr        = mpc_new("expr");
    mpc_parser_t* Lispy       = mpc_new("lispy");

    //define them with the following language
    mpca_lang(MPCA_LANG_DEFAULT,
            "                                                               \
                operator    : '+' | '-' | '*' | '/' | '%' ;                 \
                numblock    : /-?[0-9]+/ ;                                       \         
                numbertype1 : /[ <numblock> '.' <numblock> <numblock> ]/ ;    \         
                numbertype2 : /[ <numblock> <numblock> '.' <numblock> ]/ ;    \         
                number      : <numblock> | <numbertype1> | <numbertype2> ;  \         
                expr        : <number> | '(' <operator> <expr>+ ')' ;       \
                lispy       : /^/ <operator> <expr>+ /$/ ;                  \
            ",
            Number, Numblock, Numbertype1, Numbertype2, Operator, Expr, Lispy);
        
    puts("lispy ver: 0.0.0.0.2 \n");
    puts("Press Ctrl+c to exit");

    while (1) {
    
        char *input = readline("lispy$ ");
        add_history(input);

        //attemp to parse the user input
        mpc_result_t r;
        if (mpc_parse("<stdin>", input, Lispy, &r)) {
            //on success print and delete the AST
            mpc_ast_print(r.output);
            mpc_ast_delete(r.output);
        } else {
            //otherwise print and delete the error
            mpc_err_print(r.error);
            mpc_err_delete(r.error);
        }
    
        free(input);

    }
    
    //undefine and delete our parsers
    mpc_cleanup(7, Number, Numblock, Numbertype1, Numbertype2, Operator, Expr, Lispy);

    return 0;
}
