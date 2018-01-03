#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

unsigned char a;
time_t t;

srand((unsigned) time(&t));
for (int i = 0; i < 4; ++i){
a = rand() % 256;
printf("%d",a);

    if (i < 3) {
    printf(".");
    }
    else {
    printf(" \n");
    }
}
}
