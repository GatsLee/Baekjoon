//time overload
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int CNT, num, i;

	cin>>CNT;
	vector <int>v(CNT);
	for (i = 0; i < CNT; i++)
		cin>>v[i];
	sort(v.begin(), v.end());
	for (i = 0; i < CNT; i++)
		printf("%d\n", v[i]);
}