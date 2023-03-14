#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int N, num;

	cin>>N;
	vector <int> v(N + 1);
	v[1] = 0;
	v[2] = 1;
	v[3] = 1;
	if (N >= 4)
	{
		for (int i = 4; i <= N; i++)
		{
			v[i] = v[i - 1] + 1;
			if (i % 2 == 0) v[i] = min(v[i], v[i/2] + 1);
			if (i % 3 == 0) v[i] = min(v[i], v[i/3] + 1);
		}
	}
	cout<<v[N];
}
