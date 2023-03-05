#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	int N, M, cut, total, total_check, mid;
	size_t  start_idx, end_idx;

	cin>>N>>M;
	vector <int>v(N);
	for (int i = 0; i < N; i++)
		cin>>v[i];
	sort(v.begin(), v.end());
	start_idx = v.size()/2;
	end_idx = v.size() - 1;
	cut = v[start_idx];
	while(1)
	{
		total = 0;
		total_check = 0;
		for (int j = start_idx; j <= end_idx; j++)
			total += (v[j] - cut);
		if (total > M)
		{
			for (int m = start_idx + 1; m <= end_idx; m++)
				total_check += (v[m] - v[start_idx + 1]);
			if (total_check < M)
			{
				cut += (total - M) / (end_idx - start_idx);
				cout << cut;
				break ;
			}
			else
			{
				start_idx = (start_idx + end_idx) / 2;
				cut = v[start_idx];
			}
		}
		else if (total < M)
		{
			start_idx = start_idx / 2;
			cut = v[start_idx];
		}
		else
		{
			cout<<cut;
			break ;
		}
	}
}
