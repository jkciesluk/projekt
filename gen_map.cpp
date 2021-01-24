#include "rooms.h"
#include "head.h"
#include <iostream>
#include <time.h>
#include <stdbool.h>
using namespace std;


void plansza_enter (char Tt[][9], int ai, int aj)   //wstawia w tablice Tt w miejsce w tablicy P o indeksach [ai, aj]
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            P[i+ai][j+aj] = Tt[i][j];
        }
    }
}

bool sasiedzi (int i, int j) //wsprawdza czy pokoj na planszy ma sasiadow
{
    if(P[i-9][j] != '\0' && i-9 > 0)    return true;
    if(P[i+9][j] != '\0' && i+9 < 155)    return true;
    if(P[i][j-9] != '\0' && j-9 > 0)    return true;
    if(P[i][j+9] != '\0' && j+9 < 155)    return true;
    else return false;
}

bool sprawdz (int i, int j)  //true gdy pole ma co najmniej 1 sasiada, gdy samo nie jest zajete (czyli mozna na nim umiejscic pokoj
{
    if  (P[i][j] == '\0' && sasiedzi (i, j)) return true;
    else    return false;
}

void rand_plansz (int lvl, char typ, int a, int b)      //lvl 1, 2, 3 oznaczaja poziomy trudnosci potworow; typ oznacza jaki typ pokoju na planszy chcemy wylosowac
{                                                       //przyjmuje poziom i typ planszy do wstawienia oraz indeksy a, b do umieszczenia pokoju i umieszcza go w P[a][b]
    int i = rand();
    if(lvl == 1)
    {
        if(typ == 'K')  //pokoje z kluczem
        {
            i = i%5;
            if(i == 0)    plansza_enter(K1_1, a, b);
            else if(i == 1) plansza_enter(K2_1, a, b);
            else if(i == 2) plansza_enter(K3_1, a, b);
            else if(i == 3) plansza_enter(K4_1, a, b);
            else  plansza_enter(K5_1, a, b);
        }
        else if(typ == 'W') //pokoje z wyjsciem na kolejny poziom
        {
            i = i%5;
            if(i == 0)    plansza_enter(W1_1, a, b);
            else if(i == 1) plansza_enter(W2_1, a, b);
            else if(i == 2) plansza_enter(W3_1, a, b);
            else if(i == 3) plansza_enter(W4_1, a, b);
            else  plansza_enter(W5_1, a, b);
        }
        else    //zwykle pokoje
        {
            i = i%6;
            if(i == 0)    plansza_enter(Z1_1, a, b);
            else if(i == 1) plansza_enter(Z2_1, a, b);
            else if(i == 2) plansza_enter(Z3_1, a, b);
            else if(i == 3) plansza_enter(Z4_1, a, b);
            else if(i == 4) plansza_enter(Z5_1, a, b);
            else  plansza_enter(Z6_1, a, b);
        }
    }
    else if(lvl == 2)
    {
        if(typ == 'K')
        {
            i = i%10;
            if(i == 0)    plansza_enter(K1_1, a, b);
            else if(i == 1) plansza_enter(K2_1, a, b);
            else if(i == 2) plansza_enter(K3_1, a, b);
            else if(i == 3) plansza_enter(K4_1, a, b);
            else if(i == 4) plansza_enter(K5_1, a, b);
            else if(i == 5) plansza_enter(K1_2, a, b);
            else if(i == 6) plansza_enter(K2_2, a, b);
            else if(i == 7) plansza_enter(K3_2, a, b);
            else if(i == 8) plansza_enter(K4_2, a, b);
            else    plansza_enter(K5_2, a, b);
        }
        else if(typ == 'W')
        {
            i = i%10;
            if(i == 0)    plansza_enter(W1_1, a, b);
            else if(i == 1) plansza_enter(W2_1, a, b);
            else if(i == 2) plansza_enter(W3_1, a, b);
            else if(i == 3) plansza_enter(W4_1, a, b);
            else if(i == 4) plansza_enter(W5_1, a, b);
            else if(i == 5) plansza_enter(W1_2, a, b);
            else if(i == 6) plansza_enter(W2_2, a, b);
            else if(i == 7) plansza_enter(W3_2, a, b);
            else if(i == 8) plansza_enter(W4_2, a, b);
            else    plansza_enter(W5_2, a, b);
        }
        else
        {
            i = i%12;
            if(i == 0)    plansza_enter(Z1_1, a, b);
            else if(i == 1) plansza_enter(Z2_1, a, b);
            else if(i == 2) plansza_enter(Z3_1, a, b);
            else if(i == 3) plansza_enter(Z4_1, a, b);
            else if(i == 4) plansza_enter(Z5_1, a, b);
            else if(i == 5) plansza_enter(Z6_1, a, b);
            else if(i == 6) plansza_enter(Z1_2, a, b);
            else if(i == 7) plansza_enter(Z2_2, a, b);
            else if(i == 8) plansza_enter(Z3_2, a, b);
            else if(i == 9) plansza_enter(Z4_2, a, b);
            else if(i == 10) plansza_enter(Z5_2, a, b);
            else    plansza_enter(Z6_2, a, b);
        }
    }
    else
    {
        if(typ == 'K')
        {
            i = i%15;
            if(i == 0)    plansza_enter(K1_1, a, b);
            else if(i == 1) plansza_enter(K2_1, a, b);
            else if(i == 2) plansza_enter(K3_1, a, b);
            else if(i == 3) plansza_enter(K4_1, a, b);
            else if(i == 4) plansza_enter(K5_1, a, b);
            else if(i == 5) plansza_enter(K1_2, a, b);
            else if(i == 6) plansza_enter(K2_2, a, b);
            else if(i == 7) plansza_enter(K3_2, a, b);
            else if(i == 8) plansza_enter(K4_2, a, b);
            else if(i == 9) plansza_enter(K5_2, a, b);
            else if(i == 10) plansza_enter(K1_3, a, b);
            else if(i == 11) plansza_enter(K2_3, a, b);
            else if(i == 12) plansza_enter(K3_3, a, b);
            else if(i == 13) plansza_enter(K4_3, a, b);
            else    plansza_enter(K5_3, a, b);
        }
        else if(typ == 'W')
        {
            i = i%15;
            if(i == 0)    plansza_enter(W1_1, a, b);
            else if(i == 1) plansza_enter(W2_1, a, b);
            else if(i == 2) plansza_enter(W3_1, a, b);
            else if(i == 3) plansza_enter(W4_1, a, b);
            else if(i == 4) plansza_enter(W5_1, a, b);
            else if(i == 5) plansza_enter(W1_2, a, b);
            else if(i == 6) plansza_enter(W2_2, a, b);
            else if(i == 7) plansza_enter(W3_2, a, b);
            else if(i == 8) plansza_enter(W4_2, a, b);
            else if(i == 9) plansza_enter(W5_2, a, b);
            else if(i == 10) plansza_enter(W1_3, a, b);
            else if(i == 11) plansza_enter(W2_3, a, b);
            else if(i == 12) plansza_enter(W3_3, a, b);
            else if(i == 13) plansza_enter(W4_3, a, b);
            else    plansza_enter(W5_3, a, b);
        }
        else
        {
            i = i%18;
            if(i == 0)    plansza_enter(Z1_1, a, b);
            else if(i == 1) plansza_enter(Z2_1, a, b);
            else if(i == 2) plansza_enter(Z3_1, a, b);
            else if(i == 3) plansza_enter(Z4_1, a, b);
            else if(i == 4) plansza_enter(Z5_1, a, b);
            else if(i == 5) plansza_enter(Z6_1, a, b);
            else if(i == 6) plansza_enter(Z1_2, a, b);
            else if(i == 7) plansza_enter(Z2_2, a, b);
            else if(i == 8) plansza_enter(Z3_2, a, b);
            else if(i == 9) plansza_enter(Z4_2, a, b);
            else if(i == 10) plansza_enter(Z5_2, a, b);
            else if(i == 11) plansza_enter(Z6_2, a, b);
            else if(i == 12) plansza_enter(Z1_3, a, b);
            else if(i == 13) plansza_enter(Z2_3, a, b);
            else if(i == 14) plansza_enter(Z3_3, a, b);
            else if(i == 15) plansza_enter(Z4_3, a, b);
            else if(i == 16) plansza_enter(Z5_3, a, b);
            else    plansza_enter(Z6_3, a, b);
        }
    }
}

void drzwi(int i, int j)    //ustaw drzwi miedzy kazdymi sasiadujacymi pokojami
{
    if(P[i-9][j] != '\0')
    {
        P[i][j+4] = 'D';
        P[i-1][j+4] = 'D';
    }
    else if(P[i+9][j] != '\0')
    {
        P[i+9][j+4] = 'D';
        P[i+8][j+4] = 'D';
    }
    else if(P[i][j-9] != '\0')
    {
        P[i+4][j] = 'D';
        P[i+4][j-1] = 'D';
    }
    else if(P[i][j+9] != '\0')
    {
        P[i+4][j+9] = 'D';
        P[i+4][j+8] = 'D';
    }
}

void wykonaj(int lvl)   //ustal plansze w zaleznosci od poziomu
{
    srand(time(0));
    plansza_enter(T, 73, 73);

    for(int l = 0; l < 4;)
    {
        int i = (rand()%155), j = (rand()%155);
        i = i - i%9 +1; //i, j indeksy oznaczajace poczatek pokoju
        j = j - j%9 +1;
        if(sprawdz(i, j))
        {
            l++;
            rand_plansz(lvl, 'Z', i, j);
            drzwi(i, j);
        }
    }
    for(int l = 0; l < 3;)
    {
        int i = (rand()%155), j = (rand()%155);
        i = i - i%9 +1;
        j = j - j%9 +1;
        if(sprawdz(i, j))
        {
            l++;
            rand_plansz(lvl, 'K', i, j);
            drzwi(i, j);
        }
    }
    for(int l = 0; l < 1;)
    {
        int i = (rand()%155), j = (rand()%155);
        i = i - i%9 +1;
        j = j - j%9 +1;
        if(sprawdz(i, j))
        {
            l++;
            rand_plansz(lvl, 'W', i, j);
            drzwi(i, j);
        }
    }
}

bool n_lvl (int kl, int lvl) //posiadajac trzy klucze po wejsciu na E generuje nowa plansze dla lvl+1
{
    if(kl==3 && lvl==3)
    {
        return true;
    }
    else if(kl==3)
    {
        lvl++;
        for(int i = 0; i < 155; i++)
        {
            for(int j = 0; j < 155; j++)
            P[i][j] = '\0';
        }
        wykonaj(lvl);
        return true;
    }
    return false;
}


void gen_act_room(int a, int b) //tablica t bedzie przechowywac pokoj w ktorym aktualnie sie znajdujemy
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            t[i][j] = P[a+i][b+j];
        }
    }
}

void act_P(int a, int b)    //umieszcza zaktualizowany pokoj spowrotem w tablicy P
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            P[a+i][b+j] = t[i][j];
        }
    }
}

void ret_room(char input, int a, int b) //przechodzenie miedzy pokojami; input to wcisniety przez gracza przycisk, a i b to wspolrzedne t na planszy P
{
    
    if(input == 'w')
    {
        act_P(a, b);
        gen_act_room(a-9, b);
    }
    else if(input == 'a')
    {
        act_P(a, b);
        gen_act_room(a, b-9);
    }
    else if(input == 's')
    {
        act_P(a, b);
        gen_act_room(a+9, b);
    }
    else if(input == 'd')
    {
        act_P(a, b);
        gen_act_room(a, b+9);
    }
}

//startowe polozenie @ na planszy P <73, 73>

//pierwszy pokoj jest pusty, gracz ma znalezc sie na srodku pokoju, kolejne 4 (w losowaniu) pokoje to zwykle pokoje bez klucza i przejscia
//kolejne 3 to pokoje z kluczem, a ostatni losowany jest pokoj z przejsciem na kolejny poziom



