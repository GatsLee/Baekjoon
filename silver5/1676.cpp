#include <iostream>
using namespace std;

int main(void)
{
	int N;
	int	cnt =0;
	int cnt_2 = 0, cnt_5 = 0;
	int	a;
	long long total = 1;

	cin>>N;
	for (int i  = 1; i <= N; i++)
	{
		a = i;
		while (a % 2 == 0)
		{
			a /= 2;
			cnt_2++;
		}
		while (a % 5 == 0)
		{
			a /= 5;
			cnt_5++;
		}
	}
	while (cnt_2 > 0 && cnt_5 > 0)
	{
		cnt++;
		cnt_2--;
		cnt_5--;
	}
	cout<<cnt;
}
