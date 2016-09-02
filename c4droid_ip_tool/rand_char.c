#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

char a;
time_t t;

for (int i = 0; i < 4; ++i){
srand((unsigned) time(&t));
a = rand() % 26;
printf("%d",a);

    if (i < 3) {
    printf(".");
    }
    else {
    printf(" \n");
    }
}
}
