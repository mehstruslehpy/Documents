#include "Shapes.h"

int main(int argc, char *argv[])
{

    if (argc != 7 || !strncmp(argv[1],"-h",2))
    {
        puts("NLSeg: Prints a line through two given points");
        puts("Usage:\n\tFor the points (x1,y1) and (x2,y2)\n\tDo: NLSeg.o x1 y1 x2 y2");
        puts("\tPrint this help: NLSeg.o -h");
        printf("argc=%di\n",argc);
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
    drawTri(atof(argv[1]), atof(argv[2]),atof(argv[3]), atof(argv[4]),atof(argv[5]),atof(argv[6])); //draw the line
    refresh();			/* Print it on to the real screen */
    getch();			/* Wait for user input */
    endwin();			/* End curses mode		  */

    return 0;
}

