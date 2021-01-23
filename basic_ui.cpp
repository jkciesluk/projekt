#include <ncurses.h>
#include <stdbool.h>
#include "head.h"

WINDOW *create_window(int height, int width, int posy, int posx, bool border);
void print_room(WINDOW *win, char room[9][9]);
void print_ham(WINDOW *win, int h,int hmax, int a, int m);
void print_help(WINDOW *win);
void init_color_pairs();

int display(char t[RES][RES])
{


    initscr();
    start_color();
    refresh();
    init_pair(1, COLOR_GREEN, 0);
    init_pair(2, COLOR_RED, 0);
    init_pair(3, COLOR_YELLOW, 0);
    init_pair(4, COLOR_CYAN, 0);

    WINDOW *field;     //displayed rooms
    WINDOW *ham;     //zdrowie, mikstury, atak
    WINDOW *help;   //how to play



    field=create_window(11, 21, 5, 5, TRUE);
    help=create_window(5, 35, 13, 30, FALSE);
    ham=create_window(5, 25, 5, 30, TRUE);
    print_room(field, tab);
    print_ham(ham, 10,100, 20, 4);
    print_help(help);

    getch();
    endwin();
}


WINDOW *create_window(int height, int width, int posy, int posx, bool border){
    WINDOW *tmp;
    tmp=newwin(height, width, posy, posx);
    if(border){
        box(tmp, 0 , 0);
    }
    wrefresh(tmp);
    return tmp;
}

void print_room(WINDOW *win, char room[9][9]){
    for (int i = 0; i < 9; i++)
    {
        for(int j=0; j<9; j++){
            switch (room[i][j])
            {
            case '@':
                wattron(win, COLOR_PAIR(2));
                mvwprintw(win, 1+i, 2+j*2, "%c ", room[i][j]);
                wattroff(win, COLOR_PAIR(2));
                break;
            case 'M':
                wattron(win, COLOR_PAIR(3));
                mvwprintw(win, 1+i, 2+j*2, "%c ", room[i][j]);
                wattroff(win, COLOR_PAIR(3));
                break;
            case 'P':
                wattron(win, COLOR_PAIR(4));
                mvwprintw(win, 1+i, 2+j*2, "%c ", room[i][j]);
                wattroff(win, COLOR_PAIR(4));
                break;
            case 'K':
                wattron(win, COLOR_PAIR(1));
                mvwprintw(win, 1+i, 2+j*2, "%c ", room[i][j]);
                wattroff(win, COLOR_PAIR(1));
                break;
            default:
                mvwprintw(win, 1+i, 2+j*2, "%c ", room[i][j]);
                break;
            }

        }
    }
    wrefresh(win);
}

void print_ham(WINDOW *win, int h,int hmax, int a, int m){
    wattron(win, COLOR_PAIR(1));
    mvwprintw(win, 1, 1, "Punkty zycia: %d/%d", h, hmax);
    mvwprintw(win, 2, 1, "Atak: %d", a);
    mvwprintw(win, 3, 1, "Ilosc mikstur: %d", m);
    wattroff(win, COLOR_PAIR(1));
    wrefresh(win);
}

void print_help(WINDOW *win){
    wattron(win, COLOR_PAIR(1));
    wprintw(win, "Uzywaj WSAD do poruszania sie.\nWcisnij \"m\" aby wypic miksture");
    wattroff(win, COLOR_PAIR(1));
    wrefresh(win);
}
void init_color_pairs(){
     init_pair(1, COLOR_GREEN, 0);
    init_pair(2, COLOR_RED, 0);
    init_pair(3, COLOR_YELLOW, 0);
    init_pair(4, COLOR_CYAN, 0);

}
