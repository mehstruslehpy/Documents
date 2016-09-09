#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

//typedef struct midinote
//{
//	int note;
//	int velocity;
//	int time;
//
//} midinote;

void print_rect(WINDOW *win, int starty, int startx, char *string);

int main(int argc, char *argv[])
{      
		int y = 0;
		int x = 0; 
		initscr();                      /* Start curses mode            */
		cbreak();
		noecho();
		keypad(stdscr, TRUE);
		curs_set(2);
        if(has_colors() == FALSE)
        {       
				endwin();
                printf("Your terminal does not support color\n");
                exit(1);
        }
        start_color();                  /* Start color                  */
        //init_pair(1, COLOR_RED, COLOR_RED);
        //init_pair(2, COLOR_BLUE, COLOR_BLUE);

        //attron(COLOR_PAIR(1));
		
			//for( int i = 0; i < 10; i++ )
			//{
			//}		

        	//main loop;
			while(1)
			{
				switch(getch())
				{
					case '1':
					{
        				init_pair(1, COLOR_RED, COLOR_RED);
						attron(COLOR_PAIR(1));
						break;
					}
					case '2':
					{
        				init_pair(2, COLOR_GREEN, COLOR_GREEN);
						attron(COLOR_PAIR(2));
						break;
					}
					case '3':
					{
        				init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
						attron(COLOR_PAIR(3));
						break;
					}
					case '4':
					{
        				init_pair(4, COLOR_BLUE, COLOR_BLUE);
						attron(COLOR_PAIR(4));
						break;
					}
					case ' ' :	
					{
						
						getyx(stdscr, y, x);	
        				print_rect(stdscr, y, x, "0");
						move(y,x);
						break;
					}
					case KEY_UP :
					{
						y-- ;
						move(y,x);
						break;
					}
					case KEY_DOWN :
					{
						y++;
						move(y,x);
						break;
					}
					case KEY_RIGHT :
					{
						x++;
						move(y,x);
						break;
					}
					case KEY_LEFT :
					{
						x--;
						move(y,x);
						break;
					}
				}
				refresh();
			}
        	endwin();
}

void print_rect(WINDOW *win, int starty, int startx, char *string)
{       int x, y;

        if(win == NULL)
                win = stdscr;
        getyx(win, y, x);
        if(startx != 0)
                x = startx;
        if(starty != 0)
                y = starty;

        mvwprintw(win, y, x, "%s", string);
}

