#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int N, M, num;

	cin>>N;
	vector <int>card(N);
	for (int i = 0; i < N; i++)
	{
		cin>>num;
		card[i] = num;
	}
	sort(card.begin(), card.end());
	cin>>M;
	vector <int>find(M, 0);
	for (int j = 0; j < M; j++)
	{
		cin>>num;
		if (find(card.begin(), card.end(), num) != card.end())
		{
			tmp

		}
	}
	for (int a = 0; a < M; a++)
		cout<<find[a]<<' ';
}
