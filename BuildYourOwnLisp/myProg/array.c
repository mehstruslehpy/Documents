#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

typedef struct midinote
{
	int note;
	int velocity;
	int time;

} midinote;

void print_rect(WINDOW *win, int starty, int startx, int width, char *string);

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
        init_pair(1, COLOR_RED, COLOR_RED);

        attron(COLOR_PAIR(1));
		
        //repl loop;
			while(1)
			{
				//if(getch() == 113 || 81)
				//{
				//	endwin();
				//}
				switch(getch())
				{
					case ' ' :	
					{
						
						getyx(stdscr, y, x);	
        				print_rect(stdscr, y, x, 0, "0");
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

void print_rect(WINDOW *win, int starty, int startx, int width, char *string)
{       int length, x, y;
        float temp;

        if(win == NULL)
                win = stdscr;
        getyx(win, y, x);
        if(startx != 0)
                x = startx;
        if(starty != 0)
                y = starty;
        if(width == 0)
                width = 80;

        length = strlen(string);
        temp = (width - length)/ 2;
        //x = startx + (int)temp;
        mvwprintw(win, y, x, "%s", string);
}

