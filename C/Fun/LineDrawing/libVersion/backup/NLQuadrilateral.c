#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

//it wouldn't make sense to assume our screen is an array of infinite length
#define ROWBOUND 42
#define COLBOUND 42

void drawQuadrilateral(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
void drawLSeg(double x_1, double y_1, double x_2, double y_2);
void fillLine(double x_1, double x_2, double y_1, double m);
void fillVert(double x_1, double y_1, double y_2);
bool checkPair(double x,double y);

int main(int argc, char *argv[])
{

    if (argc != 9 || !strncmp(argv[1],"-h",2))
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

    drawQuadrilateral(atof(argv[1]), atof(argv[2]),atof(argv[3]), atof(argv[4]),atof(argv[5]),atof(argv[6]),atof(argv[7]),atof(argv[8]));
    refresh();			/* Print it on to the real screen */
    getch();			/* Wait for user input */
    endwin();			/* End curses mode		  */

    return 0;
}

void drawQuadrilateral(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
	if (!checkPair(x1,y1) ||!checkPair(x2,y2) ||!checkPair(x3,y3) ||!checkPair(x4,y4)) return;
	drawLSeg(x1,y1,x2,y2);
	drawLSeg(x2,y2,x4,y4);
	drawLSeg(x4,y4,x3,y3);
	drawLSeg(x3,y3,x4,y4);
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
