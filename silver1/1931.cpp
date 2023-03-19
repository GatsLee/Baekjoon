#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int N, from, to, mid;

	cin>>N;
	vector < pair <int, int> > tt(N);
	for (int i = 0; i < N; i++) {
		cin>>from>>to;
		tt[i] = make_pair(to, from);
	}
	sort(tt.begin(), tt.end());
	int time = tt[0].first;
	int ret = 1;
	for (int j = 1; j < N; j++)
	{
		if (time <= tt[j].second)
		{
			ret++;
			time = tt[j].first;
		}
	}
	cout<<ret;
}
