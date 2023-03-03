#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(void)
{
	int N, M, num;
	cin>>N;
	vector<int> card(N);
	unordered_map<int, int> freq;

	for (int i = 0; i < N; i++)
	{
		cin>>num;
		card[i] = num;
		freq[num]++;
	}
	cin>>M;
	vector<int> storage(M, 0);
	for (int j = 0; j < M; j++)
	{
		cin>>num;
		if (freq.count(num))
			storage[j] = freq[num];
	}
	for (int a = 0; a < M; a++)
		cout<<storage[a]<<' ';
}