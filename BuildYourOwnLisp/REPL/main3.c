#include <stdio.h>
#include <stdlib.h>

//if we are compiling on windows compile these functions too
//this would be __linux__ for linux and something else for mac
#ifdef _WIN32
#include <string.h>

static char buffer[2048];

//fake readline function
char *readline(char* prompt) {
    fputs(prompt, stdout);
    fgets(buffer, 2048, stdin);
    char *cpy = malloc(strlen(buffer+1));
    strcpy(cpy, buffer);
    cpy[strlen(cpy)-1] = '\0';
    return cpy; 
}

//fake add_history function
void add_history(char *unused) {}

//otherwise include the editline header
#else
#include <editline/readline.h>
#endif

static char input[2048];

int main () {
    

    puts("####################################\n");
    puts("#MyLispy Ver:0.0.0.0.1             #\n");
    puts("#Press: \"Ctrl+c\" to exit           #\n");
    puts("#SIT BACK, RELAX, FEEL INCOMPETENT.#\n");
    puts("####################################\n");

    while(1) {

        //now in either case the readline will be correctly identified
        char *input = readline("lisper$ ");
        add_history(input);
        
        printf("I don't think \"%s\" is very smart\n", input);
        free(input);
    }

    return 0;
}
