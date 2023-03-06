#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
    int CNT, num;
	int arr[10000];

    cin>>CNT;
	for (int a = 0; a < 10000; a++)
		arr[a] = 0;
	for (int i = 0; i < CNT; i++)
	{
		cin>>num;
		arr[num - 1]++;
	}
	for (int j = 0; j < 10000; j++)
	{
		int m = arr[j];
		while (m--)
			cout<<j+1<<'\n';
	}
}
