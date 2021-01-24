#include <ncurses.h>
#include <stdbool.h>

#define RES 9

void UpdateEnemies(char board[RES][RES]);
extern char P[155][155];
extern char t[9][9];
extern char sym[8];
WINDOW *create_window(int height, int width, int posy, int posx, bool border);
void print_room(WINDOW *win, char room[9][9]);
void print_ham(WINDOW *win, int h,int hmax, int keys, int m, int lvl);
void print_help(WINDOW *win);
void init_color_pairs();
void plansza_enter (char Tt[][9], int ai, int aj);
bool sasiedzi (int i, int j);
bool sprawdz (int i, int j);
void rand_plansz (int lvl, char typ, int a, int b);
void drzwi(int i, int j);
void wykonaj(int lvl);
bool n_lvl (int kl, int lvl);
void gen_act_room(int a, int b);
void act_P(int a, int b);
void ret_room(char input, int a, int b);
