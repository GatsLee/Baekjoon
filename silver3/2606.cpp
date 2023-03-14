#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int COM_CNT, NET_CNT;
int	INF_COM = 0;
stack <int> S;

void	DFS(int i, vector < vector <int> > &Network)
{
	int num;

	vector <int> visited(COM_CNT + 1, 0);

	S.push(i);
	visited[i] = 1;
	while (!S.empty())
	{
		num = S.top();
		S.pop();
		for (int j = 0; j < Network[num].size(); j++)
		{
			if (visited[Network[num][j]] == 0)
			{
				S.push(Network[num][j]);
				visited[Network[num][j]] = 1;
			}
		}
		INF_COM++;
	}
}


int main(void)
{
	int com1, com2;

	cin>>COM_CNT>>NET_CNT;
	vector < vector <int> >Network(COM_CNT +1);
	for (int i = 0; i < NET_CNT; i++)
	{
		cin>>com1>>com2;
		Network[com1].push_back(com2);
		Network[com2].push_back(com1);
	}
	for (int i = 1;i <= COM_CNT; i++)
		reverse(Network[i].begin(), Network[i].end());
	DFS(1, Network);
	cout<<INF_COM - 1;
}
