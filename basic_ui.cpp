#include "head.h"


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

void print_ham(WINDOW *win, int h,int hmax, int keys, int m){
    wattron(win, COLOR_PAIR(1));
    mvwprintw(win, 1, 1, "Health: %d/%d", h, hmax);
    mvwprintw(win, 2, 1, "Potions: %d", m);
    mvwprintw(win, 3, 1, "Keys: %d/3", keys);
    wattroff(win, COLOR_PAIR(1));
    wrefresh(win);
}

void print_help(WINDOW *win){
    wattron(win, COLOR_PAIR(1));
    wprintw(win, "\nCollect 3 keys and find \npassage to the next level.\nUse WSAD to move.\nPress \"p\" to drink a potion.");
    wattroff(win, COLOR_PAIR(1));
    wrefresh(win);
}
void init_color_pairs(){
     init_pair(1, COLOR_GREEN, 0);
    init_pair(2, COLOR_RED, 0);
    init_pair(3, COLOR_YELLOW, 0);
    init_pair(4, COLOR_CYAN, 0);
    
}