#include <stdio.h>

static char input[2048];

int main () {
    
    //Print ver and exit info
    puts("MyLispy Ver:0.0.0.0.1\n");
    puts("Press: \"Ctrl+c\" to exit\n");
    
    //in a never ending loop
    while(1) {

        //output our prompt
        fputs("lispy> ", stdout);
    
        //read a line of user input max size 2048
        fgets(input, 2048, stdin);

        printf("No you're a: %s", input);
    }

    return 0;
}
