#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int N, M;

int x_move[4] = {0,0,1,-1};
int y_move[4] = {1,-1,0,0};

void    BFS(vector < vector<int> >&map)
{
	queue < pair<int, int> >Q;

	Q.push(make_pair(0,0));
	map[0][0] = 2;
	while (!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + x_move[i];
			int ny = y + y_move[i];
			if (x == M - 1 && y == N - 1)
					return ;
			if (nx >= M || nx < 0 || ny >= N || ny < 0)
				continue ;
			if (map[ny][nx] == 1)
			{
				Q.push(make_pair(nx, ny));
				map[ny][nx] = map[y][x] + 1;
			}
		}
		Q.pop();
	}
}

int main(void)
{
	string line;

	cin>>N>>M;
	vector < vector<int> >map(N, vector<int>(M));
	for (int i = 0; i < N; i++)
	{
		cin>>line;
		for (int j = 0; j < M; j++)
			map[i][j] = line[j] - '0';
	}
	BFS(map);
	cout<<map[N - 1][M - 1] - 1;
}