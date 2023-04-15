#include <iostream>
#include <queue>
using namespace std;
#define long long int


int N, L;

int main(void) {
	int num;
	deque < pair <int, int > > DQ;

	cin>>N>>L;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (DQ.size() != 0 && i - DQ.front().second >= L)
				DQ.pop_front();
		while (DQ.size() != 0 && DQ.back().first >= num)
			DQ.pop_back();
		DQ.push_back(make_pair(num, i));
		cout<<DQ.front().first<<' ';
	}
}
