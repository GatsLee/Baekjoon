#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int N;

int main(void) {
	int num;
	stack < int > S;
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>N;
	vector <int > connected(N);
	for (int i = 0; i < N; i++) {
		cin>>num;
		S.push(num);
		connected[i] = i;
	}
	while (!S.empty()) {

	}

}
