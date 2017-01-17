#include <stdio.h>
#include <ctype.h>

int lineno = 1;
int tokenval = 0;

int main() 
{
	int t;
	while (1)
	{
		t = getchar();
		if (t == ' ' || t == '\t') {
			printf("Strip out blanks and tabs");
		} else if (t == '\n') {	
			lineno = lineno + 1;
		} else if (isdigit(t)) {	
			tokenval = t - '0';
			t = getchar();
			while (isdigit(t))
			{
				tokenval = tokenval * 10 + t - '0';
				t = getchar();
			}
			ungetc(t, stdin);
			printf("%s\n",tokenval);
			return tokenval;
		} else {
			tokenval = 0;
			return t;
		}
			
	}
}
