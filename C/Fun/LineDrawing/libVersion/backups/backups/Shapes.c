#include "Shapes.h"

int main()
{
    initscr();          // Start curses mode
    raw();              // Line buffering disabled
    noecho();           // Don't echo() while we do getch

    start_color();          // Start color
    init_pair(1, COLOR_RED, COLOR_RED);
    attron(COLOR_PAIR(1));
    curs_set(0);		//hide the cursor

    drawRect(5,5,20,20); //draw stuff
    drawCircle(3,10,10); //draw stuff
    drawCircle(3,19,10); //draw stuff
    drawLSeg(11,22,20,22); //draw stuff
    drawCircle(15,15,15); //draw stuff
    drawCircle(15,15,15); //draw stuff
    refresh();          //refresh the screen now that it has been drawn on

    getch();            //wait for user input to quit
    endwin();           // End curses mode

    return 0;
}

