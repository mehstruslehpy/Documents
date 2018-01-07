#include "../../Shapes.h"

int main(int argc, char *argv[])
{

    if (argc != 10 || !strncmp(argv[1],"-h",2))
    {
        puts("DrawTriangle: prints a triangle through the 3 given points");
        puts("USAGE: ./DrawTriangle.o x x x x x x");
        return 0;
    }

    initscr();			/* Start curses mode 		*/
    raw();				/* Line buffering disabled	*/
    noecho();			/* Don't echo() while we do getch */

    start_color();			/* Start color 			*/
    init_pair(1, COLOR_RED, COLOR_RED);
    attron(COLOR_PAIR(1));
    curs_set(0);

    //drawLSeg(atof(argv[1]), atof(argv[2]),atof(argv[3]), atof(argv[4])); //draw the line
    drawRTri(atof(argv[1]), atof(argv[2]),
             atof(argv[3]), atof(argv[4]),
             atof(argv[5]), atof(argv[6]),
             atof(argv[7]), atof(argv[8]),
             atof(argv[9])); //draw the line
    refresh();			/* Print it on to the real screen */
    getch();			/* Wait for user input */
    endwin();			/* End curses mode		  */

    return 0;
}

