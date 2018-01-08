#include "../../Shapes.h"

int main(int argc, char *argv[])
{

    if (argc != 5 || !strncmp(argv[1],"-h",2))
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
    attron(COLOR_PAIR(2));
    curs_set(0);

    //amount to delay between each draw
    const int PAUSE = 100000000;
    //starting point
    Pair start = {.x=atof(argv[1]), .y= atof(argv[2])};
    double x = atof(argv[1]);
    double y = atof(argv[2]);
    drawSinglePoint(x,y);

    //translation
    Pair xlat = {.x=atof(argv[3]), .y=atof(argv[4])};

    for (int i = 0; i < 10; i++)
    {
        start = xlatPoint(xlat.x,xlat.y,start.x,start.y);
        attron(COLOR_PAIR(2));
        drawSinglePoint(x,y);
        attron(COLOR_PAIR(1));
        drawPair(start);
        refresh(); /* Print it on to the real screen */
        for (int j = 0; j <= PAUSE; j++);
        clear();
    }

    //now undo it
    xlat.x *= -1;
    xlat.y *= -1;
    for (int i = 0; i < 10; i++)
    {
        start = xlatPoint(xlat.x,xlat.y,start.x,start.y);
        attron(COLOR_PAIR(2));
        drawSinglePoint(x,y);
        attron(COLOR_PAIR(1));
        drawPair(start);
        refresh(); /* Print it on to the real screen */
        for (int j = 0; j <= PAUSE; j++);
        clear();
    }

    getch();			/* Wait for user input */
    endwin();			/* End curses mode		  */

    return 0;
}

