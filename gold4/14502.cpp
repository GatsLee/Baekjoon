#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int map[8][8];
queue < pair <int, int> > Q;
int mv[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1,0}};

void solve() {
	while (!Q.empty()) {
		int y = Q.front().first;
		int x = Q.front().second;
		for (int m = 0; m < 4; m++) {
			int ny = y + mv[m][0];
			int nx = x + mv[m][1];
			if (ny >= N | ny < 0 | nx >= M | nx < 0)
				continue ;
			if (map[ny][nx] == 0) {
				Q.push(make_pair(ny, nx));
				map[ny][nx] = 2;
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin>>map[i][j];
			if (map[i][j] == 2)
				Q.push(make_pair(i,j));
		}
	}
	solve();
	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] == 0)
				cnt++;
	cout << cnt << '\n';
}
