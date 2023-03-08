#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int N, M, B;
	int num;
	int	min_time = 2147483647, time, level;
	int	plus, minus, height;

	cin>>N>>M>>B;
	//map parsing
	vector < vector <int> >v(N);
	for (int i = 0; i < N; i++)
	{
		vector <int>line(M);
		for (int j = 0; j < M; j++)
		{
			cin>>num;
			line[j] = num;
		}
		v[i] = line;
		line.clear();
	}
	//find min time to level the ground
	level = 0;
	while (level <= 256)
	{
		minus = 0;
		plus = 0;
		time = 0;
		for(int m = 0; m < N; m++)
		{
			for (int n = 0; n < M; n++)
			{
				if (v[m][n] > level)
				{
					time += (v[m][n] - level) * 2;
					plus += (v[m][n] - level);
				}
				else if (v[m][n] < level)
				{
					time += (level - v[m][n]);
					minus += (level - v[m][n]);
				}
			}
		}
		if (minus <= plus + B)
		{
			if (time <= min_time)
			{
				min_time = time;
				height = level;
			}
		}
		level++;
	}
	//print min time & max height
	cout<<min_time<<' '<<height;
}
