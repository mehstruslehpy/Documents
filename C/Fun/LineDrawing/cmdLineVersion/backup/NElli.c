#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

//it wouldn't make sense to assume our screen is an array of infinite length
#define ROWBOUND 42
#define COLBOUND 42

void drawEllipse(double a, double b, double h, double k);

int main(int argc, char *argv[])
{
    if (argc != 5 || !strncmp(argv[1],"-h",2))
    {
        puts("NElli: draw an ellipse based on the standard form");
        puts("Usage:\n\tFor the equations: y=sqrt(b*b*(1-pow(i-h,2)/(a*a)))+k\n\tand y=sqrt(b*b*(1-pow(i-h,2)/(a*a)))+k\n\tDo: NElli.o a b h k");
        puts("\tPrint this help: NElli.o -h");
        return 0;
    }

    initscr();			/* Start curses mode 		*/
    raw();				/* Line buffering disabled	*/
    noecho();			/* Don't echo() while we do getch */

    start_color();			/* Start color 			*/
    init_pair(1, COLOR_RED, COLOR_RED);
    attron(COLOR_PAIR(1));
    drawEllipse(atof(argv[1]), atof(argv[2]), atof(argv[3]), atof(argv[4])); //draw the ellipse

    refresh();			/* Print it on to the real screen */
    getch();			/* Wait for user input */
    endwin();			/* End curses mode		  */

    return 0;
}

//y = sqrt( b*b * ( 1 - pow(i-h,2)/(a*a))) + k;
//y = sqrt( b*b * ( 1 - pow(i-h,2)/(a*a))) + k;
void drawEllipse(double a, double b, double h, double k)
{
    int y = 0;
    //upper half
    for (int i = 0; i < COLBOUND; i++)
    {
        y = sqrt( b*b * ( 1 - pow(i-h,2)/(a*a))) + k;
        if (i > COLBOUND)
        {
            break;
        }
        if ( y > ROWBOUND)
        {
            break;
        }

        move( y, i);
        if(i >= h-a && i <= h+a) addch('0');

    }
    //lower half
    for (int i = 0; i < COLBOUND; i++)
    {
        y = -sqrt( b*b * ( 1 - pow(i-h,2)/(a*a))) + k;
        if (i > COLBOUND)
        {
            break;
        }
        if ( y > ROWBOUND)
        {
            break;
        }

        move( y, i);
        if(i >= h-a && i <= h+a) addch('0');

    }
}
