/*
**	This file contains useful macros for one version of the SevenSeg_output_ncurses program
*/

//I can't think of reason not to put these inline
//and seeing as they are all fairly tedious this might be slightly faster
#define VERT(x, y) move(y,x); addch('X'); move(y+1,x); addch('X'); move(y+2,x); addch('X');
#define HORIZ(x, y) move(y,x); addch('X'); move(y,x+1); addch('X'); move(y,x+2); addch('X'); move(y,x+3); addch('X');
#define MID(offset) move(3,offset); addch('X'); move(3,offset+3); addch('X');

//More macros, this isn't meant to be the most portable thing in the world
//it's just meant to be expanded inside of printDigits()
#define SHOW_ZERO()		\
{						\
	VERT(0+offset,0);   \
	VERT(0+offset,4);   \
	VERT(0+3+offset,0); \
	VERT(0+3+offset,4); \
	HORIZ(0+offset,0);  \
	HORIZ(0+offset,6);  \
	MID(offset);    	\
}

#define SHOW_ONE()		\
{						\
	VERT(0+3+offset,0);	\
	move(3,offset+3);   \
	addch('X');         \
	VERT(0+3+offset,4); \
}

#define SHOW_TWO()		\
{						\
	VERT(0+3+offset,0); \
	VERT(0+offset,4);   \
	HORIZ(0+offset,3);  \
	HORIZ(0+offset,0);  \
	HORIZ(0+offset,6);  \
}

#define SHOW_THREE()	\
{						\
	VERT(0+3+offset,4);	\
	VERT(0+3+offset,0);	\
	HORIZ(0+offset,0); 	\
    HORIZ(0+offset,3); 	\
	HORIZ(0+offset,6); 	\
} 

#define SHOW_FOUR()		\
{						\
	VERT(0+3+offset,4);	\
    VERT(0+offset,0);  	\
	HORIZ(0+offset,3); 	\
	VERT(0+3+offset,0);	\
}

#define SHOW_FIVE()		\
{						\
	VERT(0+3+offset,4); \
	VERT(0+offset,0);   \
	HORIZ(0+offset,6);  \
	HORIZ(0+offset,3);  \
	HORIZ(0+offset,0);  \
}

#define SHOW_SIX() 		\
{						\
	HORIZ(0+offset,6); 	\
	VERT(0+3+offset,4); \
	HORIZ(0+offset,3);  \
	VERT(0+offset,0);   \
	HORIZ(0+offset,0);  \
	VERT(0+offset,4);   \
}

#define SHOW_SEVEN()	\
{						\
	move(3,offset+3);	\
	addch('X');         \
	VERT(0+3+offset,4); \
	HORIZ(0+offset,0);  \
	VERT(0+3+offset,0); \
}

#define SHOW_EIGHT()	\
{						\
	HORIZ(0+offset,3);	\
	VERT(0+offset,0);	\
	VERT(0+offset,4);	\
	VERT(0+3+offset,0);	\
	VERT(0+3+offset,4);	\
	HORIZ(0+offset,0);	\
	HORIZ(0+offset,6);	\
}

#define SHOW_NINE()		\
{						\
	HORIZ(0+offset,3);	\
	VERT(0+offset,0);	\
	VERT(0+3+offset,0);	\
	VERT(0+3+offset,4);	\
	HORIZ(0+offset,0);	\
}

#define SHOW_CL()		\
{						\
	move(1,offset+3);	\
	addch('X');			\
	move(2,offset+3);	\
	addch('X');			\
	move(4,offset+3);	\
	addch('X');			\
	move(5,offset+3);	\
	addch('X');			\
	move(1,offset+2);	\
	addch('X');			\
	move(2,offset+2);	\
	addch('X');			\
	move(4,offset+2);	\
	addch('X');			\
	move(5,offset+2);	\
	addch('X');			\
}
