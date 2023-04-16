#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int	coord[300001] = {0,};
int N, K;

int go_backward(int cur)
{
	if (cur <= 0 || coord[cur - 1] == 1)
		return (-1);
	return (cur - 1);
}

int go_forward(int cur)
{
	if (cur < 0 || coord[cur + 1] == 1)
		return (-1);
	return (cur + 1);
}

int teleport(int cur)
{
	if (cur < 0 || cur * 2 > 100000 || coord[cur * 2] == 1)
		return (-1);
	return (cur * 2);
}

int main(void)
{
	int cur_pos , cur_mv, min_mv;
	int	cnt = 0;
	deque < pair<int, int> > Q;

	cin>>N>>K;
	Q.push_back(make_pair(N, 0));
	cur_pos = N;
	coord[cur_pos] = 1;
	while (!Q.empty())
	{
		cur_pos = Q.front().first;
		cur_mv = Q.front().second;
		Q.pop_front();
		if (cur_pos == K) {
			min_mv = cur_mv;
			break;
		}
        if (teleport(cur_pos) != -1) {
			Q.push_front(make_pair(teleport(cur_pos), cur_mv));
			coord[teleport(cur_pos)] = 1;
		}
		if (go_forward(cur_pos) != -1) {
			Q.push_back(make_pair(go_forward(cur_pos), cur_mv + 1));
			coord[go_forward(cur_pos)] = 1;
		}
		if (go_backward(cur_pos) != -1) {
			Q.push_back(make_pair(go_backward(cur_pos), cur_mv + 1));
			coord[go_backward(cur_pos)] = 1;
		}
	}
	cout<<min_mv;
}