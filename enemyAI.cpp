#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stdbool.h>
#include<queue>
#include<utility>

using namespace std;

#define RES 9


void UpdateEnemies(char board[RES][RES]){
	char sym[4] = {'@'/*Gracz*/, '$'/*Potwór*/, '+'/*Puste pole*/, '#'/*Ściana*/};

	int x_p = 0, y_p = 0; // Pozycja gracza

	// Inicjuję bfs

	int dist[RES][RES];
	bool vis[RES][RES];
	for(int i = 0; i < RES; i++){
		for(int j = 0; j < RES; j++){
			dist[i][j] = 2 * RES + 1;
			vis[i][j] = false;
			if(board[i][j] == sym[0]){
				x_p = i;
				y_p = j;
				vis[i][j] = true;
			}else if(board[i][j] == sym[3] || board[i][j] == sym[1]){
				vis[i][j] = true;								// Oznaczam ściany oraz potwory jako odwiedzone,
			}																 //  nie będę musiał tego sprawdzać w bfs
		}
	}

	dist[x_p][y_p] = 0;


	// Właściwy bfs, obliczam odległość każdego pola od gracza

	queue <pair <int, int> > q;

	q.push(make_pair(x_p, y_p));

	while(!q.empty()){

			pair <int, int> next = q.front();
			q.pop();
			int x = next.first;
			int y = next.second;

			vis[x][y] = true;

			if(x != 0 && !vis[x-1][y]){
				dist[x-1][y] = dist[x][y]+1;
				q.push(make_pair(x-1, y));
			}
			if(y != RES-1 && !vis[x][y+1]){
				dist[x][y+1] = dist[x][y]+1;
				q.push(make_pair(x, y+1));
			}
			if(x != RES-1 && !vis[x+1][y]){
				dist[x+1][y] = dist[x][y]+1;
				q.push(make_pair(x+1, y));
			}
			if(y != 0 && !vis[x][y-1]){
				dist[x][y-1] = dist[x][y]+1;
				q.push(make_pair(x, y-1));
			}
	}

	/*
	for(int i = 0; i < RES; i++){
		for(int j = 0; j < RES; j++){
			cout << dist[i][j] << " ";
		}
		cout<<"\n";
	}
 */
	// Przesuwam potwory, jeżeli jest miejsce

	for(int i = 1; i < RES-1; i++){
		for(int j = 1; j < RES-1; j++){
			if(board[i][j] == sym[1]){

				int mindist = min(min(dist[i-1][j], dist[i][j+1]), min(dist[i+1][j], dist[i][j-1]));

				if(board[i-1][j] == sym[2] && dist[i-1][j] == mindist){
					board[i][j] = sym[2];
					board[i-1][j] = sym[1];
				}else if(board[i][j+1] == sym[2] && dist[i][j+1] == mindist){
					board[i][j] = sym[2];
					board[i][j+1] = sym[1];
				}else if(board[i+1][j] == sym[2] && dist[i+1][j] == mindist){
					board[i][j] = sym[2];
					board[i+1][j] = sym[1];
				}else if(board[i][j-1] == sym[2] && dist[i][j-1] == mindist){
					board[i][j] = sym[2];
					board[i][j-1] = sym[1];
				}

			}
		}
	}

}
