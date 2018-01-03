#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

//it wouldn't make sense to assume our screen is an array of infinite length
#define ROWBOUND 42
#define COLBOUND 42

void drawRect(double x, double y, double l, double h);
void drawLSeg(double x_1, double y_1, double x_2, double y_2);
void fillLine(double x_1, double x_2, double y_1, double m);
void fillVert(double x_1, double y_1, double y_2);
bool checkPair(double x,double y);

int main(int argc, char *argv[])
{

    if (argc != 5 || !strncmp(argv[1],"-h",2))
    {
        puts("NLSqr: Prints a square");
        puts("Usage:\n\tFor the points upper left coordinate (x,y) and length l\n\tDo: NLSqr.o x y l h");
        puts("\tPrint this help: NLSqr.o -h");
        return 0;
    }

    initscr();			/* Start curses mode 		*/
    raw();				/* Line buffering disabled	*/
    noecho();			/* Don't echo() while we do getch */

    start_color();			/* Start color 			*/
    init_pair(1, COLOR_RED, COLOR_RED);
    attron(COLOR_PAIR(1));
    curs_set(0);

    drawRect(atof(argv[1]), atof(argv[2]),atof(argv[3]), atof(argv[4])); //draw the line
    refresh();			/* Print it on to the real screen */
    getch();			/* Wait for user input */
    endwin();			/* End curses mode		  */

    return 0;
}

void drawRect(double x, double y, double l, double h)
{
    drawLSeg(x,y,x+l,y); //top
    drawLSeg(x,y+h,x+l,y+h); //bottom
    drawLSeg(x+l,y,x+l,y+h); //right
    drawLSeg(x,y,x,y+h); //right
}
void fillVert(double x_1, double y_1, double y_2)
{
    for (; y_1 <= y_2; y_1++)
    {
        if (checkPair(x_1,y_1))
        {
            move(y_1, x_1);
            addch('0');
        }
    }
    return;
}
void fillLine(double x_1, double x_2, double y_1, double m)
{
    double y = 0;
    for (double i = x_1; i <= x_2; i++)
    {
        y = m*(i - x_1)+y_1;
        if (checkPair(i,y))
        {
            move(y, i);
            addch('0');
        }
    }
    return;
}
bool checkPair(double x,double y)
{
    if (y >= 0 && y <= ROWBOUND &&
            x >= 0 && x <= COLBOUND) return true;

    return false;
}
void drawLSeg(double x_1, double y_1, double x_2, double y_2)
{
    double m  = (y_2-y_1)/(x_2-x_1);

    if (checkPair(x_1,y_1))
    {
        move(y_1,x_1);
        addch('0');
    }

    if (checkPair(x_2,y_2))
    {
        move(y_2,x_2);
        addch('0');
    }

    if((x_2-x_1) == 0)
    {
        fillVert(x_1,y_1,y_2);
        return;
    }
    else
    {
        fillLine(x_1,x_2,y_1,m);
        return;
    }
}
