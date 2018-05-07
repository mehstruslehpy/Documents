#include <stdint.h>
#include <stdio.h>
#include <assert.h>

/*CONSTANTS*/
//pi/4 ~ 000.1100100100001 ~ 6433
const uint32_t PIOVER4 = 6433;
//pi/2 ~ 001.1 0010 0100 0011 ~ 12867
const uint32_t PIOVER2 = 12867;
//3pi/4 ~ 010.0 1011 0110 0101 ~ 19301
const uint32_t THREEPIOVER4 = 19301;
//pi ~ 011.0010010000111 ~ 25735
const uint32_t PI = 25735;
//NOTE: FIX ME
//5pi/4 ~ 111.1101101010011 ~ 64339
const uint32_t FIVEPIOVER4 = 64339;
//3pi/2 ~ 100.1011011001011 ~ 38603
const uint32_t THREEPIOVER2 = 38603;
//7pi/4 ~ 45037
const uint32_t SEVENPIOVER4 = 45037;
//twopi ~ 110.0100100001111 ~ 102943
const uint32_t TWOPI = 102943;
// 000.1011010100000  ~ sqrt(2)/2 ~ 5792
const uint32_t SQRT2OVER2 = 5792;

int32_t linear_approx_cos(uint32_t);
uint32_t binmul(uint32_t,uint32_t);
void debug_binprint32(uint32_t);

int main()
{
    uint32_t argument = FIVEPIOVER4;
    int32_t ret = 0;
    ret = linear_approx_cos(argument);
    printf("OUTPUT: %02X\n",ret);
	printf("ret: ");
	debug_binprint32(ret);
	printf("\n ");
    return 0;
}

int32_t linear_approx_cos(uint32_t param)
{
    //if out of range fail
    printf("DEBUG-OUTPUT:\n");
	printf("\tparam: ");
	debug_binprint32(param);
	printf("\n ");
	
	printf("\tTWOPI: ");
	debug_binprint32(TWOPI);
	printf("\n ");

    assert(param < TWOPI);

    if (param < PIOVER4)
    {
    	printf("CASE1");
        param = SQRT2OVER2 - binmul(SQRT2OVER2,(param - PIOVER4));
    }
    else if (param >= PIOVER4 && param < PIOVER2)
    {
    	printf("CASE2");
        param = PIOVER2 - param;
    }
    else if (param >= PIOVER2 && param < THREEPIOVER4)
    {
    	printf("CASE3");
        param = - SQRT2OVER2 - binmul(SQRT2OVER2,(param - THREEPIOVER4));
    }
    else if (param >= THREEPIOVER4 && param < PI)
    {
    	printf("CASE4");
        param = -1;
    }
    else if (param >= PI && param < FIVEPIOVER4)
    {
    	printf("CASE5");
        param = - SQRT2OVER2 + binmul(SQRT2OVER2,(param - THREEPIOVER4));
    }
    else if (param >= FIVEPIOVER4 && param < THREEPIOVER2)
    {
    	printf("CASE6");
        param = param - THREEPIOVER2;
    }
    else if (param >= THREEPIOVER2 && param < SEVENPIOVER4)
    {
    	printf("CASE7");
        param = SQRT2OVER2 + binmul(SQRT2OVER2,(param - SEVENPIOVER4));
    }
    else if (param >= SEVENPIOVER4 && param < TWOPI)
    {
    	printf("CASE8");
        param = 1; //fix this value to match correct representation
    }

    return param;
}

uint32_t binmul(uint32_t a, uint32_t b)
{
    uint32_t ret = 0;

    for(int i = 0; i <= 31; i++)
    {
        if((b >> i) & 0x01)
        {
            ret += (a<<i);
        }

    }
    ret = (ret<<26);
    return ret;
}

void debug_binprint32(uint32_t myint)
{
    for (int i = 0; i < 32; i++)
    {
        //if the i'th bit is set
        if((myint >> i) & 0x01)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
	return;
}
/*
*TODO: Increase the accuracy
*	add in linear approximations at:
*	-:  sqrt(2)/2 - sqrt(2)/2 * (x - pi/4)
*	-: -sqrt(2)/2 - sqrt(2)/2 * (x - 3pi/4)
*	-: -sqrt(2)/2 + sqrt(2)/2 * (x - 5pi/4)
*	-:  sqrt(2)/2 + sqrt(2)/2 * (x - 7pi/4)
*
*	figure out multiplying by an irrational in ttpasm
*
*	NOTE: 000.1011010100000  ~ sqrt(2)/2 ~ 5792
*/
/*
*	Description: Computes x*y without using the * operator
*				 This is mainly for figuring out binary multiplication
*/

