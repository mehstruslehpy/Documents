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
    mpc_parser_t* Adjective = mpc_new("adjective");
    mpc_parser_t* Noun      = mpc_new("noun");
    mpc_parser_t* Phrase    = mpc_new("phrase");
    mpc_parser_t* Doge      = mpc_new("doge");

    mpca_lang(MPCA_LANG_DEFAULT,
            "                                       \
                adjective : /[\"wow\"\"many\"\"so\"\"such\"]+/;     \
                noun      : /[\"lisp\"\"language\"\"book\"\"build\"]+/;    \
                phrase    : <adjective> <noun>;     \
                                                                                                                                                                      doge      : /^/ <phrase>* /$/;              \
                                                                                                                                                                  ",
            Adjective, Noun, Phrase, Doge);
        
    puts("DogeParse ver: 0.0.0.0.1 \n");
    puts("Press Ctrl+c to exit");

    while (1) {
    
        char *input = readline("Doge$ ");
        add_history(input);

        //attemp to parse the user input
        mpc_result_t r;
        if (mpc_parse("<stdin>", input, Doge, &r)) {
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
    mpc_cleanup(4, Adjective, Noun, Phrase, Doge);

    return 0;
}
