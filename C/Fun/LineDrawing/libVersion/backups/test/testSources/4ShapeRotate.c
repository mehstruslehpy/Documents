#include "../../Shapes.h"

int main(int argc, char *argv[])
{

    if (argc != 10 || !strncmp(argv[1],"-h",2))
    {
        puts("DrawLineSegment: Prints a line through two given points");
        puts("USAGE: ./DrawLineSegment x");
        return 0;
    }

    initscr();			/* Start curses mode 		*/
    raw();				/* Line buffering disabled	*/
    noecho();			/* Don't echo() while we do getch */

    start_color();			/* Start color 			*/
    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_BLUE, COLOR_BLUE);
    attron(COLOR_PAIR(1));
    curs_set(0);

    double x1 = atof(argv[1]);
    double y1 = atof(argv[2]);

    double x2 = atof(argv[3]);
    double y2 = atof(argv[4]);

    double x3 = atof(argv[5]);
    double y3 = atof(argv[6]);

    double x4 = atof(argv[7]);
    double y4 = atof(argv[8]);

    Pair mid1 = midPoint(x1,y1,x2,y2);
    Pair mid2 = midPoint(x3,y3,x4,y4);
    Pair mid = midPoint(mid1.x,mid1.y,mid2.x,mid2.y);

    Pair rpoint1;
    Pair rpoint2;
    Pair rpoint3;
    Pair rpoint4;

    for (int i = 0; i < 1080; i++)
    {
        rpoint1 = rotateDPoint(mid.x,mid.y,x1,y1,i);
        rpoint2 = rotateDPoint(mid.x,mid.y,x2,y2,i);
        rpoint3 = rotateDPoint(mid.x,mid.y,x3,y3,i);
        rpoint4 = rotateDPoint(mid.x,mid.y,x4,y4,i);

        //draw the starting line

        //draw the midpoint
        attron(COLOR_PAIR(2));
        drawPair(mid);

        //draw rotated about the middle point
        attron(COLOR_PAIR(1));
        drawQuadrilateral(rpoint1.x,rpoint1.y,
                          rpoint2.x,rpoint2.y,
                          rpoint3.x,rpoint3.y,
                          rpoint4.x,rpoint4.y); //draw the shape

        refresh(); /* Print it on to the real screen */
        //sleep() wasn't working too well for me
        for (int j = 0; j <= atol(argv[5])*10000; j++);
        clear();
    }
    getch();			/* Wait for user input */
    endwin();			/* End curses mode		  */

    return 0;
}

