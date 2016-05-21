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
long exponent_func(long base, long exp);
long min_func(mpc_ast_t *t);
long max_func(mpc_ast_t *t);
long eval_op(long x, char* op, long y, mpc_ast_t* t);
long eval(mpc_ast_t* t); 
