#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#define ROWBOUND 42
#define COLBOUND 42

void drawSine(double a, double b, double c, double d);

int main(int argc, char *argv[])
{
    if (argc != 5 || !strncmp(argv[1],"-h",2))
    {
        puts("NSine: Prints a sinewave based on the standard from");
        puts("Usage:\n\tFor the equation: y = a*sin(b(x+c))+d\n\tDo: NSine.o a b c d");
        puts("\tPrint this help: NSine.o -h");
        return 0;
    }

    initscr();			/* Start curses mode 		*/
    raw();				/* Line buffering disabled	*/
    noecho();			/* Don't echo() while we do getch */

    start_color();			/* Start color 			*/
    init_pair(1, COLOR_RED, COLOR_RED);
    attron(COLOR_PAIR(1));
    drawSine(atof(argv[1]), atof(argv[2]), atof(argv[3]), atof(argv[4])); //draw the sine wave

    refresh();			/* Print it on to the real screen */
    getch();			/* Wait for user input */
    endwin();			/* End curses mode		  */

    return 0;
}

void drawSine(double a, double b, double c, double d)
{
    double y = 0;
    //we can calculate row toggles using column values (x-values)

    for (int i = 0; i < COLBOUND; i++)
    {
        y = a*sin(b*(i+c)+d);
        if (i > COLBOUND)
        {
            break;
        }
        if ( y > ROWBOUND)
        {
            break;
        }

        move( y, i);	//point (x, a*sin(b*(x+c))+d)
        addch('0');

    }
}