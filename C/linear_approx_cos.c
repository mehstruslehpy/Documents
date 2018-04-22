#include <stdint.h>
#include <stdio.h>
#include <assert.h>

/*CONSTANTS*/
//twopi ~ 110.0100100001111 ~ 102943
const int TWOPI = 102943;
//pi/4 ~ 000.1100100100001 ~ 6433
const int PIOVER4 = 6433;
//pi ~ 011.0010010000111 ~ 25735
const int PI = 25735;
//3pi/2 ~ 100.1011011001011 ~ 38603
const int THREEPIOVER2 = 38603;
//pi/2 ~ 001.1001001000011 ~ 12867
const int PIOVER2 = 12867;

int16_t linear_approx_cos(int16_t);

int main()
{
	int16_t argument = PIOVER4;
	int16_t ret = 0;
	ret = linear_approx_cos(argument);
	printf("OUTPUT: %02X\n",ret);
	return 0;
}

int16_t linear_approx_cos(int16_t param)
{
	//if out of range fail
	assert(param >= 0 && param < TWOPI);

	//two cases
	if (param < PI)
	{
		param = param - PIOVER2;
	}
	else
	{
		param = -param + THREEPIOVER2;
	}
	return param;
}

