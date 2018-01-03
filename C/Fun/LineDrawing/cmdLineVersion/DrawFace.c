#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

//it wouldn't make sense to assume our screen is an array of infinite length
#define ROWBOUND 42
#define COLBOUND 42

void drawCircle(double r, double h, double k);
void drawQuad(double a, double h, double k);	//a variant of the original

int main(int argc, char *argv[])
{

    initscr();			/* Start curses mode 		*/
    raw();				/* Line buffering disabled	*/
    noecho();			/* Don't echo() while we do getch */

    start_color();			/* Start color 			*/
    init_pair(1, COLOR_RED, COLOR_RED);
    attron(COLOR_PAIR(1));

    drawCircle(8,31,10);
    drawCircle(8,10,10);

    drawCircle(1,31,10);
    drawCircle(2,31,11);
    drawCircle(1,10,10);
    drawCircle(2,10,11);

    drawQuad(-0.02,20,27);
    refresh();			/* Print it on to the real screen */
    getch();			/* Wait for user input */
    endwin();			/* End curses mode		  */

    return 0;
}

void drawCircle(double r, double h, double k)
{
    int y = 0;
    for (int i = 0; i < COLBOUND; i++)
    {
        y = sqrt(pow(r,2)-pow((i-h),2))+k;
        if (i > COLBOUND)
        {
            break;
        }
        if ( y > ROWBOUND)
        {
            break;
        }

        move( y, i);
        if(i >= h-r && i <= h+r) addch('0');

    }
    for (int i = 0; i < COLBOUND; i++)
    {
        y = -sqrt(pow(r,2)-pow((i-h),2))+k;
        if (i > COLBOUND)
        {
            break;
        }
        if ( y > ROWBOUND)
        {
            break;
        }

        move( y, i);
        if(i >= h-r && i <= h+r) addch('0');

    }
}
void drawQuad(double a, double h, double k)
{
    int y = 0;

    for (int i = 0; i < COLBOUND; i++)
    {
        y = a*(i-h)*(i-h) + k;
        if (i > COLBOUND)
        {
            break;
        }
        if ( y > ROWBOUND)
        {
            break;
        }

        move( y, i);
        addch('0');
    }
}

