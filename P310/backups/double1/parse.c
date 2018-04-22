#include "parse.h"

int parseSign(struct ParseState *pps)
{
	int retValue = 0;
	switch (*pps->ptr)
	{
		case '+':
			++pps->ptr; // skip, default sign is fine
			break;
		case '-':
			++pps->ptr; // advance
			retValue = 1;
			break;
		default:
			break;
	}
	return retValue;
}

int isDigit(const char p)
{
	return (p >= '0') && (p <= '9');
}

uint64_t parseUnsignedInt(uint64_t n, struct ParseState *pps)
{
	while (isDigit(*pps->ptr))
	{
		n = n * 10 + (*pps->ptr - '0');
		++pps->ptr;
	}
	return n;
}

void parseMantissa(struct ParseState *pps)
{
	// after sign, parse the main part
	pps->pn->mantissa = 0;
	pps->pn->exp10 = 0;
	{
		const char *oldPtr = pps->ptr;
		pps->pn->mantissa = parseUnsignedInt(0,pps);
		if (oldPtr != pps->ptr) // pointer advanced
		{
			if (*pps->ptr == '.')
			{
				++pps->ptr;
				const char *oldPtr = pps->ptr;
				pps->pn->mantissa = 
				  parseUnsignedInt(pps->pn->mantissa, pps);
				pps->pn->exp10 -= (pps->ptr - oldPtr);
			}
		}
	}
}

int parse(const char *str, struct Number *pn)
{
	struct ParseState ps;
	int error = 0;
	ps.ptr = str;
	ps.pn = pn;
	pn->exp10 = 0;
	pn->exp2=0;
	pn->sign = parseSign(&ps);
	{
		const char *oldPtr = ps.ptr;
        parseMantissa(&ps);
		if (oldPtr != ps.ptr)
		{
			if (*ps.ptr == 'e')
			{
				int expSign;
				uint64_t exp = 0;
				++ps.ptr;
				expSign = parseSign(&ps);
				exp = parseUnsignedInt(exp, &ps);
				pn->exp10 += (expSign ? -exp : exp);
			}
		}
		else
		{
			error = 1;
		}
	}
	return error;
}
