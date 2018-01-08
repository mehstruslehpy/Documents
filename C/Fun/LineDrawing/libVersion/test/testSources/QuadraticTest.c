#include "../../Shapes.h"

int main(int argc, char *argv[])
{

    if (argc != 4 || !strncmp(argv[1],"-h",2))
    {
        puts("DrawQuadratic: Prints a quadratic based on the standard form");
        puts("USAGE: ./DrawQuadratic x x x ");
        return 0;
    }

    initscr();			/* Start curses mode 		*/
    raw();				/* Line buffering disabled	*/
    noecho();			/* Don't echo() while we do getch */
    curs_set(0);

    start_color();			/* Start color 			*/
    init_pair(1, COLOR_RED, COLOR_RED);
    attron(COLOR_PAIR(1));

    drawQuad(atof(argv[1]), atof(argv[2]), atof(argv[3])); //draw the line

    refresh();			/* Print it on to the real screen */
    getch();			/* Wait for user input */
    endwin();			/* End curses mode		  */

    return 0;
}


