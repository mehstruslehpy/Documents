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

int drawSine(float a, float b, float c, float d); //print a line based on its slope and y intercept

int main(int argc, char *argv[])
{
	float aCoeff = 0;
	float bCoeff = 0;
	float cCoeff = 0;
	float dCoeff = 0;

	puts("Enter values for y=a*sin(b(x+c))+d: ");
	puts("Please enter a value for a: ");
	scanf("%f",&aCoeff);
	puts("Please enter a value for b: ");
	scanf("%f",&bCoeff);
	puts("Please enter a value for c: ");
	scanf("%f",&cCoeff);
	puts("Please enter a value for d: ");
	scanf("%f",&dCoeff);



    initscr();			/* Start curses mode 		*/
    raw();				/* Line buffering disabled	*/
    noecho();			/* Don't echo() while we do getch */
	
	start_color();			/* Start color 			*/
	init_pair(1, COLOR_RED, COLOR_RED);
	attron(COLOR_PAIR(1));

	drawSine(aCoeff, bCoeff, cCoeff, dCoeff); //draw the sine wave

    refresh();			/* Print it on to the real screen */
    getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */

    return 0;
}

//y = ax^2 + bx + c
//y = a*sin(b(x+c))+ d
int drawSine(float a, float b, float c, float d)
{
	
	//we can calculate row toggles using column values (x-values)

	for (int i = 0; i < COLBOUND; i++)
	{

		if (i > COLBOUND)
		{
			break;
		}
		if ( (a*sin(b*(i+c)+d)) > ROWBOUND)
		{
			break;
		}

		move( a*sin(b*(i+c))+d, i);	//point (x, a*sin(b*(x+c))+d)
		addch('0');

	}
}
