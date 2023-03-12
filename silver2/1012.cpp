#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M, N, K;

int x_move[4] = {0,0,-1,1};
int y_move[4] = {1,-1,0,0};

void    find_cabbage(void)
{
	int nx, ny, x, y;
	int total = 0;

	cin>>M>>N>>K;
	vector < vector <int> > map(N, vector<int>(M, 0));
	queue <pair <int, int> > Q;
	for (int i = 0; i < K; i++)
	{
		cin>>x>>y;
		map[y][x] = 1;
	}
	for (int i= 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				Q.push(make_pair(i, j));
				map[i][j] = 0;
				while (!Q.empty()) {
					y = Q.front().first;
					x = Q.front().second;
					for (int m = 0; m < 4; m++) {
						ny = y + y_move[m];
						nx = x + x_move[m];
						if (ny < 0 || ny >= N || nx < 0 || nx >= M)
							continue ;
						if (map[ny][nx] == 1)
						{
							Q.push(make_pair(ny, nx));
							map[ny][nx] = 0;
						}
					}
					Q.pop();
				}
				total++;
			}
		}
	}
	cout<<total<<'\n';
	}

int main(void)
{
	int CASE;

	cin>>CASE;
	while (CASE--)
		find_cabbage();
}