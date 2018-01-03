#include <iostream>
#include <gmp.h>

bool BruteForce ( mpz_t &n ); //perform a brute force primality test
int BigMersenne ( mpz_t &n ); //take some number n and turn it into 2^n - 1

using namespace std;

int main()
{

	mpz_t i; //a var for iterating
    mpz_init(i); //we will set it later

    mpz_t mer; //a var to hold a mersenne number
    mpz_init(mer);
    mpz_set_ui(mer,0);

	cout << "BruteForce:" << endl;
	for (mpz_set_ui(i,1); mpz_cmp_ui(i,0) > 0 && mpz_cmp_ui(i,1001) < 0; mpz_add_ui(i,i,1)) //i is gt 2 and i is lt 1000
	{
        mpz_set(mer,i); //set mer to i
        cout << "\t2^"; 
        mpz_out_str(stdout,10,i);
        cout << "-1:";
        BigMersenne(mer); //store 2^ mer -1 into mer
        //mpz_out_str(stdout,10,mer);
        //cout << ":";
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

int BigMersenne ( mpz_t &n )
{

	mpz_t i;    //a var for iterating
    mpz_init(i);
    mpz_set_ui(i,1);

	mpz_t acc;  //an accumulator
    mpz_init(acc);
    mpz_set_ui(acc,2); //set to 2 because we want 2^n -1

    while (mpz_cmp(i,n) < 0) //collect 2^n
    {
        mpz_mul_ui(acc,acc,2);
        mpz_add_ui(i,i,1);
    }
    mpz_sub_ui(acc,acc,1);  //subtract 1
    mpz_set(n,acc); //set n

    return 0;
}

bool BruteForce( mpz_t &n )
{

	mpz_t i;    //this will be for iterating
    mpz_init(i);
    mpz_set_ui(i,2);

    mpz_t np1;  //this will be n/2 + 1 for the loop
    mpz_init(np1);
    mpz_set(np1,n); 
    mpz_cdiv_q(np1,np1,i);
    mpz_add_ui(np1,np1,1);


    mpz_t result;  
    mpz_init(result);

    if (mpz_cmp_ui(n,2) < 0 || mpz_cmp_ui(n,2) == 0) return true; //dont worry about n <= 2

    while (mpz_cmp(i,np1) < 0)
    {
        mpz_mod(result,n,i); //result = n % i
        if (mpz_cmp_ui(result,0) == 0) //cmp result to 0
        {
            return false;
        }
        mpz_add_ui(i,i,1); 
    }
    return true;    
}
