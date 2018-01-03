#include <iostream>
#include <gmp.h>

bool BruteForce ( mpz_t &n );

using namespace std;

int main()
{

	mpz_t i;
    mpz_init(i);

	cout << "BruteForce:" << endl;
	for (mpz_set_ui(i,1); mpz_cmp_ui(i,0) > 0 && mpz_cmp_ui(i,50000) < 0; mpz_add_ui(i,i,1))
	{
        cout << "\t";
        mpz_out_str(stdout,10,i);
        cout << ":";
        if (BruteForce(i))
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

bool BruteForce( mpz_t &n )
{

	mpz_t i;
    mpz_init(i);
    mpz_set_ui(i,2);

    mpz_t np1;  // n/2 + 1
    mpz_init(np1);
    mpz_set(np1,n); 
    mpz_cdiv_q(np1,np1,i);
    mpz_add_ui(np1,np1,1);


    mpz_t result;  // n/2 + 1
    mpz_init(result);

    if (mpz_cmp_ui(n,2) < 0 || mpz_cmp_ui(n,2) == 0) return true;

    while (mpz_cmp(i,np1) < 0)
    {
        mpz_mod(result,n,i);
        if (mpz_cmp_ui(result,0) == 0)
        {
            return false;
        }
        mpz_add_ui(i,i,1);
    }
    return true;    
}
