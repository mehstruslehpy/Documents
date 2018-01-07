#include "../../Shapes.h"

int main(int argc, char *argv[])
{

    if (argc != 7 || !strncmp(argv[1],"-h",2))
    {
        puts("DrawQuadratic: Prints a quadratic based on the standard form");
        puts("USAGE: ./DrawQuadratic x x x ");
        return 0;
    }

    initscr();			/* Start curses mode 		*/
    raw();				/* Line buffering disabled	*/
    noecho();			/* Don't echo() while we do getch */

    start_color();			/* Start color 			*/
    init_pair(1, COLOR_RED, COLOR_RED);
    attron(COLOR_PAIR(1));

    drawRQuad(atof(argv[1]), atof(argv[2]),
              atof(argv[3]),
              atof(argv[4]), atof(argv[5]),
              atof(argv[6])); //draw the line

    refresh();			/* Print it on to the real screen */
    getch();			/* Wait for user input */
    endwin();			/* End curses mode		  */

    return 0;
}


