#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int N;

int main(void) {
	int num;
	pair <int, int> pin;
	stack <pair <int, int> > first_S;
	stack <pair <int, int> > second_S;
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>N;
	vector <int> tower(N, 0);
	for (int i = 0; i < N; i++) {
		cin>>num;
		first_S.push(make_pair(i, num));
	}
	while (!first_S.empty()) {
		pair <int, int> tmp = first_S.top();
		first_S.pop();
		if (second_S.empty()) {
			second_S.push(tmp);
			pin = tmp;
		}
		else if (tmp.second > pin.second) {
			while (!second_S.empty()) {
				tower[second_S.top().first] = tmp.first + 1;
				second_S.pop();
			}
			pin = tmp;
			second_S.push(tmp);
		}
		else {
			while (tmp.second > second_S.top().second) {
				tower[second_S.top().first] = tmp.first + 1;
				second_S.pop();
			}
			second_S.push(tmp);
		}
	}
	for (int i = 0; i < N; i++)
		cout<<tower[i]<<' ';
}
