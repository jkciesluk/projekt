#include <ncurses.h>
#include <stdbool.h>

WINDOW *create_window(int height, int width, int posy, int posx, bool border);
void print_room(WINDOW *win, char room[9][9]);
void print_ham(WINDOW *win, int h,int hmax, int a, int m);
void print_help(WINDOW *win);
int main()
{
    char tab[9][9];
    for (int i = 0; i < 9; i++)
    {
        for(int j=0; j<9; j++)
        tab[i][j]='k';
    }
    initscr();
    refresh();
    WINDOW *field;     //displayed room
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
        for(int j=0; j<9; j++)
        mvwprintw(win, 1+i, 2+j*2, "%c ", room[i][j]);
    }
    wrefresh(win);
}

void print_ham(WINDOW *win, int h,int hmax, int a, int m){
    mvwprintw(win, 1, 1, "Punkty zycia: %d/%d", h, hmax);
    mvwprintw(win, 2, 1, "Atak: %d", a);
    mvwprintw(win, 3, 1, "Ilosc mikstur: %d", m);
    wrefresh(win);
}

void print_help(WINDOW *win){
    wprintw(win, "Uzywaj WSAD do poruszania sie.\nWcisnij \"m\" aby wypic miksture");
    wrefresh(win);
}