#include "number.h"
#include "exp10to2.h"

//#include <stdio.h>
void exp10ToExp2(struct Number *pn)
{
	// in this function, convert the number pointed to b
	// pn from a base-10 mantissa and exponent to a base-2
	// mantissa and exponent
	// divide into two main cases: when exp10 > 0, and when
	// exp10 < 0

	uint64_t msb = (uint64_t)1<<63;	//set the very last bit 2^63
	uint64_t allbits = (uint64_t)~0; //set all bits 2^63-1

//	if (pn->exp10 < 0)
//	{
//		while (pn->exp10 < 0)
//		{
//			while(!((uint64_t)pn->mantissa & msb))
//			{
//				pn->mantissa = pn->mantissa << 1;
//				pn->exp2--;
//			}
//			pn->mantissa = (pn->mantissa + 5)/10;
//			pn->exp10++;
//		}
//	}
//    while(!((uint64_t)pn->mantissa & msb))
//    {
//        pn->mantissa = pn->mantissa << 1;
//        pn->exp2--;
//    }
//	printf("Your Number:\n");
//	printf("\tMantissa: %llu\n",pn->mantissa);
//	printf("\tBase-10 exponent: %d\n",pn->exp10);
//	printf("\tBase-2 exponent: %d\n",pn->exp2);
//	printf("\tBase-2 exponent: %d\n",pn->exp2);

	if (pn->exp10 > 0)
	{
		while (pn->exp10 > 0)
		{
			while(!(pn->mantissa < allbits/10))
			{
				pn->mantissa = (pn->mantissa+1)/2;
				pn->exp2++;
			}

			pn->mantissa *= 10;
			pn->exp10--;
		}
	}

}
