#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int min_time = 0;
queue <pair <int, int> > Q_mv;
queue <pair <int, int> > Q_eat;
int x_move[4] = {1,-1,0,0};
int y_move[4] = {0,0,-1,1};

void    eat_fish(vector < vector <int> > &map, int x, int y) {
	int p_size = 2;

	map[y][x] = -1;
	Q_mv.push(make_pair(y, x));
	while (!Q_mv.empty()) {
		int cur_y = Q_mv.front().first;
		int cur_x = Q_mv.front().second;
		Q_mv.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cur_y + y_move[i];
			int nx = cur_x + x_move[i];
			if (ny >= N || ny < 0 || nx >= N || nx < 0)
				continue ;
			if (map[ny][nx] < p_size && map[ny][nx] > 0) {
				Q_mv.push(make_pair(ny, nx));
				Q_eat.push(make_pair(map[ny][nx], mv_cnt));
				map[ny][nx] = -1; 
				min_time++;
			}
			if (map[ny][nx] == 0) {
				Q_mv.push(make_pair(ny, nx));	
				map[ny][nx] = -1;
			}

		}
	}
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int x, y;

	cin>>N;
	vector < vector <int> > map(N, vector<int>(N,0));
	vector <int> fish_to_eat(7, 0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin>>map[i][j];
			if (map[i][j] == 9)
				x = j; y = i;
			if (map[i][j] != 0 && map[i][j] != 9)
				fish_to_eat[map[i][j]]++;
		}
	}
	eat_fish(map, x, y);
	cout<<min_time;
}