#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	int CASE, N, M, cnt = 0;
	int	target, tmp_idx, tmp_val, num;

	cin>>CASE;
	while (CASE--)
	{
		target = 0;
		cnt = 0;
		queue< pair <int, int> >q;
		priority_queue<int>v;
		cin>>N>>M;
		for (int i = 0; i < N; i++)
		{
			cin>>num;
			q.push(make_pair(i, num));
			v.push_back(num);
			if (i == M)
				target = num;
		}
		while (q.size() != 0)
		{
			if (q.top().first == M)
			{
				if (v.top() == target)
					break ;
				q.pop();
				q.push(target);
				cnt++;
			}
			else
			{
				if (v.top().second() == q.top().second())
				{
					v.pop();
					q.pop();
					cnt++;
				}
				else
				{
					tmp_val = q.top().second();
					tmp_idx = q.top().first();
					q.pop();
					q.push(make_pair(tmp_idx, tmp_val));
					cnt++;
				}
			}
		}
		cout<<cnt<<'\n';
	}
}
