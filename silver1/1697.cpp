#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int	coord[100001] = {0,};
int N, K;
queue < pair <int, int> > Q;

int go_backward(int cur)
{
	if (coord[cur - 1] == 1 || cur - 1 < 0)
		return (-1);
	return (cur - 1);
}

int go_forward(int cur)
{
	if (coord[cur + 1] == 1 || cur + 1 > 100000)
		return (-1);
	return (cur + 1);
}

int teleport(int cur)
{
	if (cur * 2 > 100000 || coord[cur * 2] == 1)
		return (-1);
	return (cur * 2);
}

int main(void)
{
	int cur, last;
	int	cnt = 0;

	cin>>N>>K;
	Q.push(make_pair(N, cnt));
	cur = N;
	last = N;
	while (Q.size() != 0)
	{
		cur = Q.front().first;
		cnt = Q.front().second + 1;
		if (cur == K)
			break;
		if (coord[cur] == 0)
		{
			coord[cur] = 1;
			if (go_backward(cur) >= 0)
				Q.push(make_pair(go_backward(cur), cnt));
			if (go_forward(cur) >= 0)
				Q.push(make_pair(go_forward(cur), cnt));
			if (teleport(cur) >= 0)
				Q.push(make_pair(teleport(cur), cnt));
		}
		Q.pop();
	}
	cout<<Q.front().second;
}
