#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, max_num;

int x_mv[2] = {0,1};
int y_mv[2] = {1,1};

int main(void) {
	int num;
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>N;
	vector < vector <int> > V(N);
	int size = 1;
	for (int i = 0; i < N; i++) {
		vector <int> line;
		for (int j = 0; j < size; j++) {
			cin>>num;
			line.push_back(num);
		}
		V[i] = line;
		line.clear();
		size++;
	}
	queue < pair<int, int> > Q;
	vector < int > SUM(N, -1);
	SUM[0] = V[0][0];
	Q.push(make_pair(0, 0));
	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		for (int i = 0; i < 2; i++) {
			int nx = x + x_mv[i];
			int ny = y + y_mv[i];
			if (nx >= N || ny >= N)
				continue ;
			if (V[ny][nx] != -1) {
				if (SUM[nx] <= V[ny][nx] + SUM[x])
					SUM[nx] = V[ny][nx] + SUM[x];
				Q.push(make_pair(nx, ny));
			}
		}
	}
	for (int m = 0; m < N; m++) {
		cout<<SUM[m]<<' ';
		if (SUM[m] >= max_num)
			max_num = SUM[m];
	}
	cout<<max_num;
}