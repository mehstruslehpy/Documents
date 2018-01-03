/*
**
**	This program takes a slope and y intercept and uses that to print a line
**
*/

#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <unistd.h>

//it wouldn't make sense to assume our screen is an array of infinite length
#define ROWBOUND 42
#define COLBOUND 42

int drawLine(float m, float b); //print a line based on its slope and y intercept

int main(int argc, char *argv[])
{
	float slope = 0;
	float yInter = 0;

	puts("Please enter a slope: ");
	scanf("%f",&slope);
	puts("Please enter a y-intercept ");
	scanf("%f",&yInter);

    initscr();			/* Start curses mode 		*/
    raw();				/* Line buffering disabled	*/
    noecho();			/* Don't echo() while we do getch */
	
	start_color();			/* Start color 			*/
	init_pair(1, COLOR_RED, COLOR_RED);
	attron(COLOR_PAIR(1));

	drawLine(slope, yInter); //draw the line

    refresh();			/* Print it on to the real screen */
    getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */

    return 0;
}

//y = mx + b
int drawLine(float m, float b)
{
	move(0,b); //draw the y intercept
	
	//we can calculate row toggles using column values (x-values)

	for (int i = 0; i < COLBOUND; i++)
	{

		if (i > COLBOUND)
		{
			break;
		}
		if (m*i+b > ROWBOUND)
		{
			break;
		}

		move(m*i + b, i);
		//move( (m*i + b), i);
		addch('0');

	}
}
