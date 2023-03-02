#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int , int> b)
{
	return (a < b);
}

int main(void)
{
	int CNT, x, y;
	vector < pair<int, int> >coord;
	pair<int , int>p1;

	cin>>CNT;
	for (int i = 0; i < CNT; i++)
	{
		cin>>x>>y;
		p1 = make_pair(x, y);
		coord.push_back(p1);
	}
	sort(coord.begin(), coord.end(), cmp);
	for (int j = 0; j < CNT; j++)
	{
		cout<<coord[j].first<<' '<<coord[j].second<<'\n';
	}
}
