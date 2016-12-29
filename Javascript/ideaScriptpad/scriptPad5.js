//states whether a number is prime

var input = Number(prompt("Enter a number to be checked."));
var test = isPrime(input);

if (test == 0) 
{
	alert(input + " is not prime" );
} else {
	alert(input + " is prime." );
}

//returns 1 if prime 0 if not
function isPrime(n) 
{
	var prime = 1;
	for ( var i = 2; i < n - 1; i++)
	{
		if ( n % i == 0)
		{
			prime = 0;
			break;	
		} else {
			prime = 1;
			break;
		}
			
	}

	return prime;
}
