#include "Shapes.h"
int main(int argc, char *argv[])
{

    if (argc != 4 || !strncmp(argv[1],"-h",2))
    {
        puts("NLSqr: Prints a square");
        puts("Usage:\n\tFor the points upper left coordinate (x,y) and length l\n\tDo: NLSqr.o x y l");
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

    drawSqr(atof(argv[1]), atof(argv[2]),atof(argv[3])); //draw the line
    refresh();			/* Print it on to the real screen */
    getch();			/* Wait for user input */
    endwin();			/* End curses mode		  */

    return 0;
}

