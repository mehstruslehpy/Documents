/*
**
**	This program takes a slope and y intercept and uses that to print a line
**
*/

#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

//it wouldn't make sense to assume our screen is an array of infinite length
#define ROWBOUND 42
#define COLBOUND 42

int drawQuad(float a, float b, float c); //print a line based on its slope and y intercept

int main(int argc, char *argv[])
{
	float aCoeff = 0;
	float bCoeff = 0;
	float cCoeff = 0;

	puts("Enter coefficients of Ax^2+Bx+C: ");
	puts("Please enter the A coefficient: ");
	scanf("%f",&aCoeff);
	puts("Please enter the B coefficient: ");
	scanf("%f",&bCoeff);
	puts("Please enter the constant value C: ");
	scanf("%f",&cCoeff);



    initscr();			/* Start curses mode 		*/
    raw();				/* Line buffering disabled	*/
    noecho();			/* Don't echo() while we do getch */
	
	start_color();			/* Start color 			*/
	init_pair(1, COLOR_RED, COLOR_RED);
	attron(COLOR_PAIR(1));

	drawQuad(aCoeff, bCoeff, cCoeff); //draw the line

    refresh();			/* Print it on to the real screen */
    getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */

    return 0;
}

//y = ax^2 + bx + c
int drawQuad(float a, float b, float c)
{
	
	//we can calculate row toggles using column values (x-values)

	for (int i = 0; i < COLBOUND; i++)
	{

		if (i > COLBOUND)
		{
			break;
		}
		if ( (a*pow(i,2)+b*i+c) > ROWBOUND)
		{
			break;
		}

		move( (a*pow(i,2)+b*i+c), i);	//point (x, ax^2+bx+c)
		addch('0');

	}
}
