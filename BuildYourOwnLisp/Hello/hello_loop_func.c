#include <stdio.h>
#include <stdlib.h>

int hello_loop(int n_times);

int main (int argc, char** argv) {

    int n = atoi( argv[1] );
    hello_loop(n);
    return 0;

}

int hello_loop(int n_times){

    int i = 0;

    while (i <= n_times) {
        puts("Hello World!\n");
        i = i + 1;
    };
    
    return 0;
}
