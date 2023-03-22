#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

int N, M;

int main(void) {
	long long top, cnt;

	cin>>N>>M;
	unordered_map <int ,int>UM;
	queue < long long > Q;

	Q.push(N);
	UM[N] = 0;
	while (!Q.empty()) {
		top = Q.front();
		cnt = UM[top] + 1;
		Q.pop();
		if (top * 2 <= M) {
			if (UM[top * 2] == 0) {
				Q.push(top * 2);
				UM[top * 2] = cnt;
			}
		}
		if (top * 10 + 1 <= M) {
			if (UM[top * 10 + 1] == 0) {
			Q.push(top * 10 + 1);
			UM[top * 10 + 1] = cnt;
			}
		}
	}
	if (UM[M] == 0)
		cout<<-1;
	else
		cout<<UM[M] + 1;
}
