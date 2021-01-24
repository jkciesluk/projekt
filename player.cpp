#include <stdio.h>
#include <iostream>
#include "head.h"

using namespace std;
#define RES 9

char sym[8] = {'@'/*Gracz*/, 'm'/*Potwór*/, '+'/*Puste pole*/, '#'/*Œciana*/, 'M' /*potwor dwufazowy*/, 'W' /*potwor 3faz*/, 'P' /*mikstura*/, 'K' /*mikstura*/};

typedef struct hero
{

    int hp;
    int pot;
    int keys;
//int atak; na te chwile bez znaczenia

} first;

#define maxhp 15
#define wrogatak1 2
#define wrogatak2 3
#define wrogatak3 4

//#define wroghp 3
char P[155][155];
char t[9][9];

int gX, gY;
int lvl;
char input;

int sizex, sizey;
int main()
{
    first player;
    lvl=1;
    player.hp = maxhp;
    player.pot = 1;
    player.keys = 0;
    wykonaj(lvl);
    

    int xp=3;
    int yp=3;
    gX=73;
    gY=73;
    
    gen_act_room(gX, gY);
    t[xp][yp]=sym[0];
    initscr();
    start_color();
    getmaxyx(stdscr,sizey,sizex);       //set up ncurses
    init_color_pairs();
    refresh();
    noecho();
    curs_set(0);
    WINDOW *field;     //displayed rooms
    WINDOW *ham;     //zdrowie, mikstury, atak
    WINDOW *help;   //how to play
    attron(COLOR_PAIR(1));
    mvprintw(sizey/2-4, sizex/2-20, "Saint Wojciech among Oaks");
    mvprintw(sizey/2-2, sizex/2-20, "There are 3 levels of the maze");
    mvprintw(sizey/2-1, sizex/2-20, "At the end a beautiful Princess awaits");
    mvprintw(sizey/2, sizex/2-20, "Avoid monsters, collect keys and save her");
    mvprintw(sizey/2+2, sizex/2-20, "Press any key to begin");
    attroff(COLOR_PAIR(1));
    refresh();
    getch();
    clear();
    refresh();
    field=create_window(11, 21, (sizey-11)/2, sizex/2-33, TRUE);
    help=create_window(5, 35, (sizey-11)/2+5, sizex/2-10, FALSE);
    ham=create_window(5, 25, (sizey-11)/2, sizex/2-10, TRUE);

    print_room(field, t);
    print_ham(ham, player.hp,maxhp, 0, player.pot);
    print_help(help);


    while((player.hp)>0)
    {
        scanf("\n%c",&input);
        if(t[xp][yp]!='E')t[xp][yp]=sym[2];
        

        

        // zmiana pozycji gracza/uzycie mikstury zaleznie od wczytanej czynnosci
        if(t[xp+1][yp]==sym[1])
        {
            player.hp=(player.hp)-(wrogatak1);
            t[xp+1][yp]=sym[2];

        }
        else if(t[xp+1][yp]==sym[4])
        {
            player.hp=(player.hp)-(wrogatak2);
            t[xp+1][yp]=sym[1];
        }
        else if(t[xp+1][yp]==sym[5])
        {
            player.hp=(player.hp)-(wrogatak3);
            t[xp+1][yp]=sym[4];
        }

            if(t[xp][yp+1]==sym[1])
        {
            player.hp=(player.hp)-(wrogatak1);
            t[xp][yp+1]=sym[2];

        }
        else if(t[xp][yp+1]==sym[4])
        {
            player.hp=(player.hp)-(wrogatak2);
            t[xp][yp+1]=sym[1];
        }
        else if(t[xp][yp+1]==sym[5])
        {
            player.hp=(player.hp)-(wrogatak3);
            t[xp][yp+1]=sym[4];
        }

        if(t[xp-1][yp]==sym[1])
        {
            player.hp=(player.hp)-(wrogatak1);
            t[xp-1][yp]=sym[2];

        }
        else if(t[xp-1][yp]==sym[4])
        {
            player.hp=(player.hp)-(wrogatak2);
            t[xp-1][yp]=sym[1];
        }
        else if(t[xp-1][yp]==sym[5])
        {
            player.hp=(player.hp)-(wrogatak3);
            t[xp-1][yp]=sym[4];
        }

        if(t[xp][yp-1]==sym[1])
        {
            player.hp=(player.hp)-(wrogatak1);
            t[xp][yp-1]=sym[2];

        }
        else if(t[xp][yp-1]==sym[4])
        {
            player.hp=(player.hp)-(wrogatak2);
            t[xp][yp-1]=sym[1];
        }
        else if(t[xp][yp-1]==sym[5])
        {
            player.hp=(player.hp)-(wrogatak3);
            t[xp][yp-1]=sym[4];
        }


        if(input=='w' && t[xp-1][yp]!=sym[3] && t[xp-1][yp]!=sym[5] && t[xp-1][yp]!=sym[4] && t[xp-1][yp]!=sym[1])
        {
            if(t[xp-1][yp]==sym[6])
            {
                player.pot++;
            }
            xp--;
        }
        else if(input=='s' && t[xp+1][yp]!=sym[3]  && t[xp+1][yp]!=sym[5] && t[xp+1][yp]!=sym[4] && t[xp+1][yp]!=sym[4])
        {
            if(t[xp+1][yp]==sym[6])
            {
                player.pot++;
            }
            xp++;

        }
        else if(input=='a' && t[xp][yp-1]!=sym[3]  && t[xp][yp-1]!=sym[5] && t[xp][yp-1]!=sym[4] && t[xp][yp-1]!=sym[1])
        {
            if(t[xp][yp-1]==sym[6])
            {
                player.pot++;
            }
            yp--;

        }
        else if(input=='d' && t[xp][yp+1]!=sym[3]  && t[xp][yp+1]!=sym[5] && t[xp][yp+1]!=sym[4] && t[xp][yp+1]!=sym[1])
        {
            if(t[xp][yp+1]==sym[6])
            {
                player.pot++;
            }
            yp++;

        }
        else if(input=='p')
        {
            player.pot=player.pot - 1;
            player.hp = maxhp;
        }
        if(t[xp][yp]==sym[7]){
            player.keys=player.keys + 1;
        }

        if(t[xp][yp]=='D'){
            
            ret_room(input, gY, gX);
            if(input =='w') {gY-=9; xp=7;}
            if(input =='s') {gY+=9; xp=1;}
            if(input =='a') {gX-=9; yp=7;}
            if(input =='d') {gX+=9; yp=1;}
        }
        
        if(t[xp][yp]=='E'){
            if(n_lvl(player.keys, lvl)){
            gX=73;
            gY=73;
            gen_act_room(gX,gY);
            player.keys=0;
            lvl++;
            }
            if(lvl>3) break;
        }

        if(t[xp][yp]!='E') t[xp][yp]=sym[0];

        
        UpdateEnemies(t);

        //sprawdzanie czy wokol stoi potwor jesli takodbywa sie walka zaleznie od fazy potwora po pokonaniu ten ginie lub zmienia sie w nizsza faze



        print_room(field, t);
        print_ham(ham, player.hp,maxhp, player.keys, player.pot);
    }

    wborder(field, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wborder(ham, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wborder(ham, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    clear();
    if(player.hp<=0){
        mvprintw(sizey/2-1, sizex/2-5, "You lost!");
    }
    else{
        mvprintw(sizey/2-5, sizex/2-5, "Congratulations! You saved the princess!");
        
    }
    
    refresh();
    getch();
    endwin();

    return 0;
}
