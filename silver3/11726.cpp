#include <iostream>
using namespace std;

int main(void)
{
	int N;
	long long	ans[1001];

	cin>>N;
	ans[1] = 1;
	ans[2] = 2;
	if (N >= 3)
	{
		for  (int i = 3; i <= N; i++)
			ans[i] = (ans[i - 1] + ans[i - 2]) % 10007;
	}
	cout<<ans[N];
}
