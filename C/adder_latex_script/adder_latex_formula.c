#include <stdio.h>
#include <stdlib.h>

const int MAX_CHARS = 999;

const char* preamble =
"The program you just ran expands the carry computation formula for n=%ld:\n"
"$$k_{n+1}=\\bigvee_{i=0}^{n} g_{i}(\\bigwedge_{j=i+1}^{n} p_{j})+ k_0 \\bigwedge_{i=0}^{n} p_{i}$$\n"
"Where $g_n$ and $p_n$ are defined as:\n"
"$$g_n:=x_n y_n$$\n"
"$$p_n:=x_n+y_n$$\n";

int main()
{
	FILE* outf = NULL;
	char carrystr[MAX_CHARS];
	unsigned long carryno = 0;
	char filestr[MAX_CHARS];

	printf("Please enter a carry number:\n-->");
	fgets(carrystr,MAX_CHARS,stdin);
	printf("Please enter a filename:\n-->");
	fgets(filestr,MAX_CHARS,stdin);
	sscanf(filestr,"%s",filestr);
	carryno = strtoul(carrystr,NULL,10);
	
	printf("Carry number: %ld \n",carryno);
	printf("File name: %s \n",filestr);
	printf("Generating output file...\n");

	outf = fopen(filestr,"w");
	fclose(outf);

	outf = fopen(filestr,"a");
	fputs("\\documentclass{article}\n\\usepackage{graphics}\n\\begin{document}\\begin{flushleft}\n",outf);
	fprintf(outf,preamble,carryno-1);
	fputs("$$\n",outf);

	fprintf(outf,"k_%ld",carryno);
	fprintf(outf,"=k_{%ld+1}=",carryno-1);
	
	for(long int i = 0; i <= carryno-1; i++)
	{
		fprintf(outf,"g_%ld",i);
		for (long int j = i+1; j <= carryno-1; j++)
		{
			fprintf(outf,"p_%ld",j);
		}
		fputs("+",outf);
	}

	fputs("k_0",outf);
	for(long int i = 0; i <= carryno-1; i++)
	{
		fprintf(outf,"p_%ld",i);
	}

	fputs("\n$$\n\\end{flushleft}\\end{document}\n",outf);
	fclose(outf);
	return EXIT_SUCCESS;
}
