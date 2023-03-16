#include <iostream>
using namespace std;

int main(void)
{
	int T, ret;
	int ans[11];

	cin>>T;
	ans[1] = 1;
	ans[2] = 2;
	ans[3] = 4;
	while (T--)
	{
		cin>>ret;
		if (ret >= 4)
			for (int i = 4; i <= ret; i++)
				ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 3];
		cout<<ans[ret]<<'\n';
	}
}
