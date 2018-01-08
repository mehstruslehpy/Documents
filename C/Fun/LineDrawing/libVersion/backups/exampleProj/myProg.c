#include "Shapes.h"

int main()
{
	initscr();          /* Start curses mode        */
    raw();              /* Line buffering disabled  */
    noecho();           /* Don't echo() while we do getch */

    start_color();          /* Start color          */
    init_pair(1, COLOR_RED, COLOR_RED);
    attron(COLOR_PAIR(1));
    curs_set(0);		//hide the cursor
    
	//this loop will toggle the picture back and forth
	for (int i = 0; i < 25; i++)
    {
        drawRect(5,5,20,20); //draw stuff
        drawCircle(3,10,10); //draw stuff
        drawCircle(3,19,10); //draw stuff
        drawLSeg(11,22,20,22); //draw stuff
        drawCircle(15,15,15); //draw stuff
        //refresh();          //refresh the screen now that it has been drawn on
        doupdate();
		getch();            //wait for user input to quit
		clear(); 

        drawRect(10,5,20,20); //draw stuff
        drawCircle(3,15,10); //draw stuff
        drawCircle(3,24,10); //draw stuff
        drawLSeg(16,22,25,22); //draw stuff
        drawCircle(15,20,15); //draw stuff
        doupdate();		//supposedly doupdate is faster than refresh?
		getch();            //wait for user input to quit
    	clear();
	}

    endwin();           // End curses mode

    return 0;
}

