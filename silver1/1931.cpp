#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int N, from, to;
	int	max_cnt = 0, cnt;
	int	lastest = 0, fastest = 214743647;

	cin>>N;
	vector < pair <int, int> >time;
	vector <int>start;
	for (int i = 0; i < N; i++) {
		cin>>from>>to;
		if (to >= lastest)
			lastest = to;
		if (from <= fastest)
			fastest = from;
		time.push_back(make_pair(from, to));
		start.push_back(from);
	}
	sort(time.begin(), time.end());
	for (int i = 0; i < lastest)
	{

	}
}
