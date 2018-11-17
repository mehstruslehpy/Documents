#include "Shapes.h"

int main(int argc, char *argv[])
{
    if (argc != 3 || !strncmp(argv[1],"-h",2))
    {
        puts("NLine: Prints a line based on the standard from");
        puts("Usage:\n\tFor the equation: y = m*x+b\n\tDo: NLine.o m b");
        puts("\tPrint this help: NLine.o -h");
        return 0;
    }

    initscr();			/* Start curses mode 		*/
    raw();				/* Line buffering disabled	*/
    noecho();			/* Don't echo() while we do getch */

    start_color();			/* Start color 			*/
    init_pair(1, COLOR_RED, COLOR_RED);
    attron(COLOR_PAIR(1));

    drawLine(atof(argv[1]), atof(argv[2])); //draw the line

    refresh();			/* Print it on to the real screen */
    getch();			/* Wait for user input */
    endwin();			/* End curses mode		  */

    return 0;
}

