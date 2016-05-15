#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>

static char input[2048];

int main () {
    
    //Print ver and exit info
    puts("MyLispy Ver:0.0.0.0.1\n");
    puts("Press: \"Ctrl+c\" to exit\n");
    
    //in a never ending loop
    while(1) {

        //output our prompt and get input
        char *input = readline("lispy> ");

        //add input to history
        add_history(input);
        
        //echo input back to user
        printf("No you're a %s\n", input);

        //free retrieved input
        free(input);
    }

    return 0;
}
