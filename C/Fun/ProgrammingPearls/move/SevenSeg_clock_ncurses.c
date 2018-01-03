/*
**
**	This program takes a user input number and uses that to print a seven segment display style time
**
*/

#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <unistd.h>

int printTime(char,char,char,char); //print the time using printDigits()
int printDigits(char, int);		//takes a character and an x axis offset print a digit
int vert(int x, int y);			//print a vertical line
int horiz(int x, int y);		//print a horizontal line
int mid(int offset);			//print two filler dots
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
		printf("USAGE: clock [four-digit-num]\n");
		return 0;
	}
    initscr();			/* Start curses mode 		*/
    raw();				/* Line buffering disabled	*/
    noecho();			/* Don't echo() while we do getch */
	
	start_color();			/* Start color 			*/
	init_pair(1, COLOR_RED, COLOR_RED);
	attron(COLOR_PAIR(1));

	//if you wanted to input each char as a seperate argv do this
	//printTime(*argv[1], *argv[2], *argv[3], *argv[4]);

	//if you want to input as a single num do this
	printTime(argv[1][0], argv[1][1], argv[1][2], argv[1][3]);

	//move the cursor
 	move(1024,1024);

    refresh();			/* Print it on to the real screen */
    getch();			/* Wait for user input */
	//sleep(15);		/* or sleep for 15 seconds before exit */
	endwin();			/* End curses mode		  */

    return 0;
}

//a big ugly switch statement to build each seven segment digit
int printDigits(char inChar, int offset)
{
    switch (inChar)
    {
    case '0':
        vert(0+offset,0);	//line 3
        vert(0+offset,4);	//line 5
        vert(0+3+offset,0);	//line 4
        vert(0+3+offset,4); //line 6
        horiz(0+offset,0);	//line 2
        horiz(0+offset,6);	//line 0
        mid(offset);		//missing dots
        break;
    case '1':
        vert(0+3+offset,0);	//line 4
        move(3,offset+3);	//missing dot
        addch('X');			//missing dot
        vert(0+3+offset,4); //line 6
        break;
    case '2':
        vert(0+3+offset,0);	//line 4
        vert(0+offset,4);	//line 5
        horiz(0+offset,3);	//line 1
        horiz(0+offset,0);	//line 2
        horiz(0+offset,6);	//line 0
        break;
    case '3':
        vert(0+3+offset,4); //line 6
        vert(0+3+offset,0);	//line 4
        horiz(0+offset,0);	//line 2
        horiz(0+offset,3);	//line 1
        horiz(0+offset,6);	//line 0
        break;
    case '4':
        vert(0+3+offset,4); //line 6
        vert(0+offset,0);	//line 3
        horiz(0+offset,3);	//line 1
        vert(0+3+offset,0);	//line 4
        break;
    case '5':
        vert(0+3+offset,4); //line 6
        vert(0+offset,0);	//line 3
        horiz(0+offset,6);	//line 0
        horiz(0+offset,3);	//line 1
        horiz(0+offset,0);	//line 2
        break;
    case '6':
        horiz(0+offset,6);	//line 0
        vert(0+3+offset,4); //line 6
        horiz(0+offset,3);	//line 1
        vert(0+offset,0);	//line 3
        horiz(0+offset,0);	//line 2
        vert(0+offset,4);	//line 5
        break;
    case '7':
        move(3,offset+3);	//missing dot
        addch('X');			//missing dot
        vert(0+3+offset,4); //line 6
        horiz(0+offset,0);	//line 2
        vert(0+3+offset,0);	//line 4
        break;
    case '8':
        horiz(0+offset,3);	//line 1
        vert(0+offset,0);	//line 3
        vert(0+offset,4);	//line 5
        vert(0+3+offset,0);	//line 4
        vert(0+3+offset,4); //line 6
        horiz(0+offset,0);	//line 2
        horiz(0+offset,6);	//line 0
        break;
    case '9':
        horiz(0+offset,3);	//line 1
        vert(0+offset,0);	//line 3
        vert(0+3+offset,0);	//line 4
        vert(0+3+offset,4); //line 6
        horiz(0+offset,0);	//line 2
        break;
    case ':':
        move(1,offset+3);	//missing dot
        addch('X');			//missing dot
        move(2,offset+3);	//missing dot
        addch('X');			//missing dot
        move(4,offset+3);	//missing dot
        addch('X');			//missing dot
        move(5,offset+3);	//missing dot
        addch('X');			//missing dot
        move(1,offset+2);	//missing dot
        addch('X');			//missing dot
        move(2,offset+2);	//missing dot
        addch('X');			//missing dot
        move(4,offset+2);	//missing dot
        addch('X');			//missing dot
        move(5,offset+2);	//missing dot
        addch('X');			//missing dot
        break;
    default:
        break;
    }
}
int mid(int offset)
{
    move(3,offset);
    addch('X');
    move(3,offset+3);
    addch('X');
}
int vert(int x, int y)
{
    move(y,x);
    addch('X');
    move(y+1,x);
    addch('X');
    move(y+2,x);
    addch('X');
}
int horiz(int x, int y)
{
    move(y,x);
    addch('X');
    move(y,x+1);
    addch('X');
    move(y,x+2);
    addch('X');
    move(y,x+3);
    addch('X');
}

int printTime(char a, char b, char c, char d)
{

    printDigits(a, 0);
    printDigits(b, 5);
    printDigits(':', 10);
    printDigits(c, 15);
    printDigits(d, 20);
}

int numberDemo()
{
    printDigits('0', 0);
    printDigits('1', 5);
    printDigits('2', 10);
    printDigits('3', 15);
    printDigits('4', 20);
    printDigits('5', 25);
    printDigits('6', 30);
    printDigits(':', 35);
    printDigits('7', 40);
    printDigits('8', 45);
    printDigits('9', 50);
}
