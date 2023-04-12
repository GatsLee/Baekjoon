#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
queue < pair <int, int> > Q;
int x_mv[4] = {0,0,-1,1};
int y_mv[4] = {1,-1,0,0};

void solve(vector < vector <int> > &map) {
	while (!Q.empty()) {
		int y = Q.front().first;
		int x = Q.front().second;
		Q.pop();
		int cnt = map[y][x];
		for (int m = 0; m < 4; m++) {
			int ny = y + y_mv[m];
			int nx = x + x_mv[m];
			if (ny >= N | ny < 0 | nx >= M | nx < 0)
				continue ;
			if (map[ny][nx] == 0) {
				Q.push(make_pair(ny, nx));
				map[ny][nx] = cnt + 1;
			}
		}
	}
}

int main(void) {
	int num;
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>M;
	vector < vector <int> > map(N, vector <int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin>>map[i][j];
			if (map[i][j] == 2)
				Q.push(make_pair(i,j));
		}
	}
	solve(map);
	cout<<'\n';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout<<map[i][j]<<' ';
		}
		cout<<'\n';
	}
}