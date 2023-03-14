#include <iostream>
#include <vector>
using namespace std;

int N;
int	white = 0, blue = 0;

void	recur_div(int size, int x, int y, vector < vector<int> >&map)
{
	int flag = 0;

	if (size == 1)
	{
		if (map[y][x] == 0)
			white++;
		else
			blue++;
		return ;
	}
	int checker = map[y][x];
	for (int ny = y; ny < y + size; ny++)
		for (int nx = x; nx < x + size; nx++)
			if (checker != map[ny][nx])
				flag = 1;
	if (flag == 0)
	{
		if (checker == 0)
			white++;
		else
			blue++;
		return ;
	}
	else
	{
		for (int i = y; i < y + size; i += size / 2)
			for (int j = x; j < x + size; j += size / 2)
				recur_div(size / 2, j, i, map);
	}
}

int main(void)
{
	cin>>N;
	vector < vector<int> >map(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin>>map[i][j];
	recur_div(N, 0, 0, map);
	cout<<white<<'\n'<<blue;
}
