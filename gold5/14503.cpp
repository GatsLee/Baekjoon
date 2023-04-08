
#include <iostream>
#include <vector>
using namespace std;

int N, M;
int cur_x, cur_y, dir;
int cnt;
int x_mv[4] = {0,1,0,-1};
int y_mv[4] = {-1,0,1,0};

void    solve(vector < vector <int> > &map) {
	int new_y, new_x;
	int rot_cnt = 0;

	map[cur_y][cur_x] = 2;
	cnt++;
	while (true) {
		if (dir == 0)
			dir = 3;
		else
			dir--;
		new_y = cur_y + y_mv[dir];
		new_x = cur_x + x_mv[dir];
		if (map[new_y][new_x] == 0) {
			cur_y = new_y;
			cur_x = new_x;
			map[new_y][new_x] = 2;
			cnt++;
			rot_cnt = 0;
		}
		else {
			rot_cnt++;
			if (rot_cnt == 4) {
				new_y = cur_y - y_mv[dir];
				new_x = cur_x - x_mv[dir];
				if (map[new_y][new_x] == 1)
					break ;
				else if (map[new_y][new_x] == 2)
					cur_y = new_y; cur_x = new_x;
				rot_cnt = 0;
			}
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>M;
	cin>>cur_y>>cur_x>>dir;
	vector < vector <int> > map(N, vector <int>(M, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin>>map[i][j];
	solve(map);
	cout<<cnt<<'\n';
}