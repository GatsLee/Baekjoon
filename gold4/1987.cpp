#include <iostream>
#include <string>
using namespace std;

int R, C;
char map[21][21];
int max_cnt = 0;

void	solve(int y, int x, int cnt, int vis[]) {
	if (y >= 0 && y < R && x >= 0 && x < C && (!vis[map[y][x]])) {
		vis[map[y][x]]++;
		cnt++;
		if (cnt > max_cnt)
			max_cnt = cnt;
		solve(y + 1, x, cnt, vis);
		solve(y - 1, x, cnt, vis);
		solve(y, x + 1, cnt, vis);
		solve(y, x - 1, cnt, vis);
		vis[map[y][x]]--;
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string str;

	cin>>R>>C;
	int tmp[128] = {};
	for (int i = 0; i < R; i++) {
		cin>>str;
		for (int j = 0; j < C; j++)
			map[i][j] = str[j];
		str.clear();
	}
	solve(0, 0, 0, tmp);
	cout << max_cnt;
}
