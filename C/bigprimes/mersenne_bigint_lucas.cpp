/*****************************************************

William Vanskike
CISP 400 - MW 5:30 pm
Programming Project 1
September 11, 2017

Please grade extra credit

*****************************************************/

#include <iostream>
#include <gmp.h>

bool LucasLehmer ( unsigned long long n );

using namespace std;

int main()
{

	cout << "Lehmer:" << endl;
	cout << "Note: 2^2-1 and 2^3-1 are both prime" << endl;
	for (int i = 1; i < 1001; i++)
	{
		cout << "\t2^" << i << "-1:";
		if (LucasLehmer(i))
		{
			cout << " PRIME" << endl;
		}
		else 
		{
			cout << " NOT PRIME" << endl;
		}
	}
	return 0;
}

bool LucasLehmer( unsigned long long n1 )
{

    if (n1 <= 2) return true; //dont worry about n <= 2

    mpz_t n;    //n is n1 but as an mpz_t
    mpz_init(n);
    mpz_set_ui(n,n1);

	mpz_t two;  //this simplifies some function calls
    mpz_init(two);
    mpz_set_ui(two,2);

    mpz_t s;    //from the pseudocode
    mpz_init(s);
    mpz_set_ui(s,4); //s = 4

	mpz_t M;    //also from the pseudocode
	mpz_init(M);//M = 2^n -1
	mpz_pow_ui(M,two,n1); //M = 2^n
	mpz_sub_ui(M,M,1); //M = M -1

	mpz_t i;    //for looping
	mpz_init(i);
    mpz_set_ui(i,0);

	mpz_t n2; 	//n - 2
	mpz_init(n2); //also for looping
    mpz_sub_ui(n2,n,2);



    while ( mpz_cmp(i, n2))	// i < (n-2)
    {
        //perform s = ((s * s) - 2) % M;
		mpz_mul(s, s, s);
    	mpz_sub_ui(s,s,2);
		mpz_mod(s, s, M);

		//i++
		mpz_add_ui(i,i,1);
    }
    
    if (mpz_cmp_ui(s,0) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
