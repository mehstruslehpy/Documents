#include "Shapes.h"

int main(int argc, char *argv[])
{
    if (argc != 4 || !strncmp(argv[1],"-h",2))
    {
        puts("NCircle: Prints a circle based on the standard form");
        puts("Usage:\n\tFor the equations: y=+sqrt(r^2-(x-h)^2)+k\n\t    and y=-sqrt(r^2-(x-h)^2)+k\n\tDo: NCircle.o r h k");
        puts("\tPrint this help: NCircle.o -h");
        return 0;
    }

    initscr();			/* Start curses mode 		*/
    raw();				/* Line buffering disabled	*/
    noecho();			/* Don't echo() while we do getch */

    start_color();			/* Start color 			*/
    init_pair(1, COLOR_RED, COLOR_RED);
    attron(COLOR_PAIR(1));
    drawCircle(atof(argv[1]), atof(argv[2]), atof(argv[3])); //draw the circle

    refresh();			/* Print it on to the real screen */
    getch();			/* Wait for user input */
    endwin();			/* End curses mode		  */

    return 0;
}

