#include <ncurses.h>
#include <stdbool.h>

#define RES 9

void UpdateEnemies(char board[RES][RES]);

extern char sym[8];
WINDOW *create_window(int height, int width, int posy, int posx, bool border);
void print_room(WINDOW *win, char room[9][9]);
void print_ham(WINDOW *win, int h,int hmax, int keys, int m);
void print_help(WINDOW *win);
void init_color_pairs();