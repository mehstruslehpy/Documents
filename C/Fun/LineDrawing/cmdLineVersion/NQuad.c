#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

//it wouldn't make sense to assume our screen is an array of infinite length
#define ROWBOUND 42
#define COLBOUND 42

void drawQuad(double a, double b, double c);

int main(int argc, char *argv[])
{

    if (argc != 4 || !strncmp(argv[1],"-h",2))
    {
        puts("NQuad: Prints a quadratic based on the standard from");
        puts("Usage:\n\tFor the equation: y = a*x^2+bx+c\n\tDo: NQuad.o a b c");
        puts("\tPrint this help: NQuad.o -h");
        return 0;
    }

    initscr();			/* Start curses mode 		*/
    raw();				/* Line buffering disabled	*/
    noecho();			/* Don't echo() while we do getch */

    start_color();			/* Start color 			*/
    init_pair(1, COLOR_RED, COLOR_RED);
    attron(COLOR_PAIR(1));

    drawQuad(atof(argv[1]), atof(argv[2]), atof(argv[3])); //draw the line

    refresh();			/* Print it on to the real screen */
    getch();			/* Wait for user input */
    endwin();			/* End curses mode		  */

    return 0;
}

//y = ax^2 + bx + c
void drawQuad(double a, double b, double c)
{
    double y = 0;
    for (int i = 0; i < COLBOUND; i++)
    {
        y = a*i*i+b*i+c;

        if (i > COLBOUND)
        {
            break;
        }
        if ( y > ROWBOUND)
        {
            break;
        }

        move( y, i);	//point (x, ax^2+bx+c)
        addch('0');

    }
}
