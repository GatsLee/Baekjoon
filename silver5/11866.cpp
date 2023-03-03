#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	queue <int>p;
	int N, K, tmp;

	std::cin>> N >> K;
	for (int i = 1; i <= N ; i++)
		p.push(i);
	cout<<'<';
	while(p.size() != 1)
	{
		for (int i = 0; i < K - 1; i++)
		{
			tmp = p.front();
			p.pop();
			p.push(tmp);
		}
		cout<<p.front()<<", ";
		p.pop();
	}
	cout<<p.front()<<'>';
}