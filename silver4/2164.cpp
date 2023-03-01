#include <iostream>
#include <deque>
using namespace std;

int TOTAL;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>TOTAL;
	deque <int>DQ;

	for (int i = 1; i <=TOTAL; i++)
		DQ.push_back(i);
	while (DQ.size() != 1)
	{
		DQ.pop_front();
		DQ.push_back(DQ.front());
		DQ.pop_front();
	}
	cout<<DQ.front();
}