#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;

int main(void)
{
	int num;

	cin>>N;
	vector < pair <int , int> >coord(N);
	vector <int> to_print(N);
	for (int i = 0; i < N; i++)
	{
		cin>>num;
		coord[i] = make_pair(num, i);
	}
	sort(coord.begin(), coord.end());
	int	checker = coord.front().first;
	int ret = 0;
	for (int i = 0; i < coord.size(); i++)
	{
		if (coord[i].first > checker)
		{
			to_print[coord[i].second] = ++ret;
			checker = coord[i].first;
		}
		else
			to_print[coord[i].second] = ret;
	}
	for (int i = 0; i < to_print.size(); i++)
		cout<<to_print[i]<<' ';
}
