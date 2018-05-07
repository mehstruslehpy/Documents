/*
*	Description: Computes x*y without using the * operator
*				 This is mainly for figuring out binary multiplication
*/

#include <stdint.h>
#include <stdio.h>
#include <assert.h>

//change T and NUM here to whatever type and width works
//Num and T must match
//if you want to do 16 bit multiplication you will need to extend to 32 bits and etc I think?
#define NUM 32
#define T int32_t
//Input test values for a * b here
#define A 6144
#define B 13312
// 0.75    ~ 000.1 1000 0000 0000 ~ 0001 1000 0000 0000 ~ 2^11 + 2^12 = 6144
// 0.125   ~ 000.0 0100 0000 0000 ~ 0000 0100 0000 0000 ~ 2^10        = 1024
// 0.09375 ~ 0000 00.00 0110 0000 0000 0000 0000 0000 ~ 0000 0000 0110 0000 0000 0000 0000 0000 = 6291456

// 1.625 ~ 001.1 0100 0000 0000 ~ 0011 0100 0000 0000 ~ 2^10 + 2^12 + 2^13 = 13312

//take most significant 16 bits shift left around 26 times
//the bitwidth
const T WIDTH = NUM;

//unroll this loop to the correct bitwidth to get the correct algorithm if needed
T binmul(T,T);

int main()
{
    T a = A;
    T b = B;

	T ret = 0;
    ret = binmul(a,b);
    printf("OUTPUT: %d*%d=%d\n",a,b,ret);
    printf("HEX: %02X*%02X=%02X\n",a,b,ret);
    return 0;
}

T binmul(T a, T b)
{
    T ret = 0;
    for(int i = 0; i <= WIDTH-1; i++)
    {
        if((b >> i) & 0x01)
        {
            ret += (a<<i);
        }

    }
    return ret;
}

