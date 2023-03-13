#include <iostream>
using namespace std;

int cnt_min = 0, cnt_zero = 0, cnt_one = 0;
int paper[2187][2187];

void	which_one(int num)
{
	if (num == -1)
		cnt_min++;
	else if (num == 0)
		cnt_zero++;
	else
		cnt_one++;
}


void cut_paper(int N, int idx_y, int idx_x)
{
	int flag = 0;
	int tmp;

	if (N == 1)
	{
		which_one(paper[idx_y][idx_x]);
		return ;
	}
	tmp  = paper[idx_y][idx_x];
	for (int i = idx_y; i < idx_y + N; i++)
	{
		for (int j = idx_x; j < idx_x + N; j++)
		{
			if (paper[i][j] != tmp)
				flag = 1;
		}
	}
	if (flag == 0)
	{
		which_one(paper[idx_y][idx_x]);
		return ;
	}
	else
	{
		for (int m = idx_y; m < idx_y + N; m += N/3)
			for (int n = idx_x; n < idx_x + N; n += N/3)
				cut_paper(N/3, m, n);
	}
}

int main(void)
{
	int N, num;

	cin>>N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin>>paper[i][j];
	cut_paper(N, 0, 0);
	cout<<cnt_min<<'\n'<<cnt_zero<<'\n'<<cnt_one;
}
