/*
**
**	This program takes a user input number and uses that to print a seven segment display styled time
**	NOTE: this is a port of a previous program I had made using ncurses
*/

#include <stdio.h>
#include <string.h>

//declarations to represent the display in memory
//currently these values for rows and columns give me the sanest possible output
#define ROWS 8
#define COLS 100
char screenArray[ROWS][COLS];
int row_index = 0;
int col_index = 0;

//functions to implement what was previously done via ncurses
int move(int, int);    //sets the (x,y) coordinates of the cursor
int addch(char);   //places a character into the display at coordinates: (row_index, col_index)
int initScreen();  //clears the uninintialized display
int printDisplay();  //actually prints the display

int writeDigits(char, int);		//takes a character and an x axis offset to write into the display
int vert(int x, int y);			//print a vertical line
int horiz(int x, int y);		//print a horizontal line
int mid(int offset);			//print two filler dots

int main(int argc, char *argv[])
{

    //check for -h flag
    if (argc < 2 || strcmp(argv[1],"-h") == 0)
    {
	printf("USAGE: SevenSeg [numbers-separated-by-spaces or a ':' character]\n");
        return 0;
    }

    initScreen(); /* initialize 2d array */

    for (int i = 0, j = 0; i < argc; i++, j += 5)
    {
	writeDigits(*argv[i],j);
    }

    printDisplay();			/* Print it on to the real screen */

    return 0;
}

//a big ugly switch statement to build each seven segment digit
int writeDigits(char inChar, int offset)
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

int move(int row, int col)
{
    row_index = row;
    col_index = col;
}

int addch(char inChar)
{
    screenArray[row_index][col_index] = inChar;
}

int printDisplay()
{
    printf("\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%c",screenArray[i][j]);
        }
        printf("\n");
    }
}

int initScreen()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            screenArray[i][j] = ' ';
        }
    }
}
