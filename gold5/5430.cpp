#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int	arr[100000];

bool init_command(char COM, deque <int> &Q)
{
	if (COM == 'R')
	{
		if (Q.size() >= 2) {
			int end = Q.size() - 1;
			for (int i = 0; i < Q.size() / 2; i++)
			{
				swap(Q[i], Q[end]);
				end--;
			}
		}
		return (true);
	}
	else
	{
		if (Q.size() == 0)
			return (false);
		else
			Q.pop_front();
		return (true);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int TEST, num;
	string  COMMAND, ARR;

	cin>>TEST;
	while (TEST--) {
		int 	idx = 0;
		bool	flag = true;
		cin>>COMMAND>>num>>ARR;
		deque <int> Q;
		// make an array
		for (int i = 0; i < ARR.size(); i++)
		{
			int total  = 0;
			while (ARR[i] >= '0' && ARR[i] <= '9')
			{
				total = total * 10 + (ARR[i] - '0');
				i++;
			}
			if (total != 0)
				Q.push_back(total);
		}
		// initiate commands
		int size = idx;
		for (int j = 0; j < COMMAND.size(); j++)
		{
			if (init_command(COMMAND[j], Q) == true)
				continue ;
			else
			{
				cout<<"error\n";
				flag = false;
				break ;
			}
		}
		// print array if commands worked
		if (flag == true)
		{
			cout<<"[";
			while (Q.size() != 0)
			{
				if (Q.size() == 1)
					cout<<Q.front();
				else
					cout<<Q.front()<<',';
				Q.pop_front();
			}
			cout<<"]\n";
		}
	}	
}