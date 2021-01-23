#include <stdio.h>
#include <iostream>
#include "head.h"

using namespace std;
#define RES 9

char sym[7] = {'@'/*Gracz*/, 'm'/*Potwór*/, '+'/*Puste pole*/, '#'/*Œciana*/, 'M' /*potwor dwufazowy*/, 'W' /*potwor 3faz*/, 'P' /*mikstura*/};

typedef struct hero
{

    int hp;
    int pot;
//int atak; na te chwile bez znaczenia

} first;

#define maxhp 15
#define wrogatak1 2
#define wrogatak2 3
#define wrogatak3 4

//#define wroghp 3

char t[RES][RES];


char input;


int main()
{
    first player;

    player.hp = maxhp;
    player.pot = 1;


    for(int i=0; i<RES; i++)
    {
        for (int j=0; j<RES; j++)
        {
            if(i==0 || j==RES-1 || j==0 || i==RES-1 )
            {
                t[i][j]=sym[3];
            }
            else
            {
                t[i][j]=sym[2];
            }
        }
    }
    t[8][4]='D';
    t[4][4]='P';
    int xp=3;
    int yp=3;

    t[xp][yp]=sym[0];

    t[5][7]=sym[1];
    t[7][6]=sym[1];

    initscr();
    start_color();    
    init_color_pairs();
    refresh();
    WINDOW *field;     //displayed rooms
    WINDOW *ham;     //zdrowie, mikstury, atak
    WINDOW *help;   //how to play
    
    field=create_window(11, 21, 5, 5, TRUE);
    help=create_window(5, 35, 10, 30, FALSE);
    ham=create_window(5, 25, 5, 30, TRUE);
    
    print_room(field, t);
    print_ham(ham, player.hp,maxhp, 0, player.pot);
    print_help(help);

    while((player.hp)>0)
    {
        scanf("\n%c",&input);


        t[xp][yp]=sym[2];

        // zmiana pozycji gracza/uzycie mikstury zaleznie od wczytanej czynnosci

        if(input=='w' && t[xp-1][yp]!=sym[3])
        {
            if(t[xp-1][yp]==sym[6])
            {
                player.pot++;
            }
            xp--;
        }
        else if(input=='s' && t[xp+1][yp]!=sym[3])
        {
            if(t[xp+1][yp]==sym[6])
            {
                player.pot++;
            }
            xp++;

        }
        else if(input=='a' && t[xp][yp-1]!=sym[3])
        {
            if(t[xp][yp-1]==sym[6])
            {
                player.pot++;
            }
            yp--;

        }
        else if(input=='d' && t[xp][yp+1]!=sym[3])
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
        t[xp][yp]=sym[0];


        UpdateEnemies(t);

        //sprawdzanie czy wokol stoi potwor jesli takodbywa sie walka zaleznie od fazy potwora po pokonaniu ten ginie lub zmienia sie w nizsza faze


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


        
        print_room(field, t);
        print_ham(ham, player.hp,maxhp, 0, player.pot);
    }


    getch();
    endwin();

    return 0;
}
