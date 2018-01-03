/*
**
**	This program takes a user input number and uses that to print a seven segment display style time
**
*/

#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include "macros.h" //user defined macros

int printDigits(char, int);		//takes a character and an x axis offset print a digit
int numberDemo();				//print a demo

/*
**	A lot of this is straight off tldp
**	and from any other unix/linux program
*/

int main(int argc, char *argv[])
{

	//check for -h
	if (argc < 2 || strcmp(argv[1],"-h") == 0)
	{
		printf("USAGE: clock [numbers-separated-by spaces]\n");
		return 0;
	}
    initscr();			/* Start curses mode 		*/
    raw();				/* Line buffering disabled	*/
    noecho();			/* Don't echo() while we do getch */
	
	start_color();			/* Start color 			*/
	init_pair(1, COLOR_RED, COLOR_RED);
	attron(COLOR_PAIR(1));

	for (int i = 0, j = 0; i < argc; i++, j += 5)
	{
		printDigits(*argv[i],j);	
	}

	//move the cursor
 	move(1024,1024);

    refresh();			/* Print it on to the real screen */
    getch();			/* Wait for user input */
    endwin();			/* End curses mode		  */

    return 0;
}

//a big ugly switch statement to build each seven segment digit
int printDigits(char inChar, int offset)
{
    switch (inChar)
    {
    case '0':
		SHOW_ZERO();
        break;
    case '1':
        SHOW_ONE();
		break;
    case '2':
		SHOW_TWO();
		break;
    case '3':
		SHOW_THREE();
        break;
    case '4':
		SHOW_FOUR();
        break;
    case '5':
		SHOW_FIVE();
        break;
    case '6':
		SHOW_SIX();
        break;
    case '7':
		SHOW_SEVEN();
        break;
    case '8':
		SHOW_EIGHT();
        break;
    case '9':
        SHOW_NINE();
		break;
    case ':':
       	SHOW_CL(); 
        break;
    default:
        break;
    }
}

