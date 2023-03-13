#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, M;

bool find_square(int line, vector < vector <int> >&rec)
{
	for (int i = 0; i < N - line; i++)
	{
		for (int j = 0; j < M - line; j++)
		{
			if (rec[i][j] == rec[i+line][j]
				&& rec[i][j] == rec[i][j+line]
				&& rec[i][j] == rec[i+line][j+line])
				return (true);
		}
	}
	return (false);
}

int main(void)
{
	int line;
	string str;

	cin>>N>>M;
	if (N >= M)
		line = M;
	else
		line = N;
	vector < vector <int> >rec(N, vector <int>(M));
	for (int i = 0; i < N; i++)
	{
		cin>>str;
		for (int j = 0; j < str.size(); j++)
		{
			int num = str[j] - '0';
			rec[i][j] = num;
		}
	}
	while (line > 1)
	{
		if (find_square(line - 1, rec) == true)
		{
			cout<<line * line;
			return (0);
		}
		line--;
	}
	cout<<line * line;
}
