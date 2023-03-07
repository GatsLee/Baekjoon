#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	int CASE, N, M, cnt;
	int	target, tmp_idx, tmp_val, num;

	cin>>CASE;
	while (CASE--)
	{
		target = 0;
		cnt = 1;
		queue< pair <int, int> >q;
		priority_queue<int>		v;

		cin>>N>>M;
		for (int i = 0; i < N; i++)
		{
			cin>>num;
			q.push(make_pair(i, num));
			v.push(num);
			if (i == M)
				target = num;
		}
		while (q.size() != 0)
		{
			if (q.front().first == M)
			{
				if (v.top() == target)
					break ;
				q.pop();
				q.push(make_pair(M, target));
			}
			else
			{
				if (v.top() == q.front().second)
				{
					v.pop();
					q.pop();
					cnt++;
				}
				else
				{
					tmp_val = q.front().second;
					tmp_idx = q.front().first;
					q.pop();
					q.push(make_pair(tmp_idx, tmp_val));
				}
			}
		}
		std::cout<<cnt<<'\n';
	}
}
