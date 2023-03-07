#include <iostream>
#include <stack>
#include <vector>
#include <cstdio>
using namespace std;

int main(void)
{
	int N, num;
	int	min_cnt = 0;
	int plus_cnt = 0;

	cin>>N;
	stack <int>s;
	vector <int>v(N);
	vector <char>pm;
	for (int i = 0; i < N; i++)
	{
		cin>>num;
		v[i] = num;
	}
	num = 1;
	int idx = 0;
	while (v[idx])
	{
		//push to the stack until I find target element
		while (num <= N)
		{
			s.push(num);
			pm.push_back('+');
			plus_cnt++;
			if (v[idx] == num)
			{
				num++;
				break ;
			}
			num++;
		}
		//if there is the target on top of the stack, pop it
		while (s.empty() == 0 && s.top() == v[idx])
		{
			s.pop();
			pm.push_back('-');
			min_cnt++;
			idx++;
		}
		//if there is nothing to push, then pop all of the stack
		if (plus_cnt == N && min_cnt < N)
		{
			while (s.empty() != 1)
			{
				if (s.top() != v[idx])
				{
					cout<<"NO\n";
					return (0);
				}
				s.pop();
				pm.push_back('-');
				min_cnt++;
				idx++;
			}
		}
		if (plus_cnt == N && min_cnt == N)
			break ;
	}
	for (int j= 0; j < pm.size(); j++)
		cout<<pm[j]<<'\n';
}