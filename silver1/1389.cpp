#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int	DFS(int i, vector < vector <int> >&node)
{
	int cnt, cur;
	int total = 0;

	stack < pair <int ,int> > S;
	vector <int> visited(N + 1, 0);
	S.push(make_pair(i , 0));
	visited[i] = 1;
	while (!S.empty())
	{
		cur = S.top().first;
		cnt = S.top().second;
		S.pop();
		for (int j = 0; j < node[cur].size(); j++)
		{
			if (visited[node[cur][j]] == 0)
			{
				S.push(make_pair(node[cur][j], cnt + 1));
				visited[node[cur][j]] = 1;
			}
		}
		total += cnt;
	}
	return total;
}

int main(void)
{
	int num1, num2, ret;
	int	bacon = 500000;
	vector <int> kevin;

	cin>>N>>M;
	vector < vector <int> >node(N + 1);
	for (int i = 1; i <= M; i++)
	{
		cin>>num1>>num2;
		node[num1].push_back(num2);
		node[num2].push_back(num1);
	}
	for (int i = 1; i <= N; i++)
		reverse(node[i].begin(), node[i].end());
	for (int i = 1; i <= N; i++)
	{
		ret = DFS(i, node);
		if (bacon > ret)
		{
			if (!kevin.empty())
				kevin.clear();
			bacon = ret;
			kevin.push_back(i);
		}
		else if (bacon == ret)
			kevin.push_back(i);
	}
	sort(kevin.begin(), kevin.end());
	cout<<kevin.front();
}
