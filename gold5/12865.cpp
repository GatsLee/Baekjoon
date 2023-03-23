#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int max_val[100001];
int	visited[100][100];

int main(void) {

	int num1, num2;
	int max = 0;
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>M;
	vector < pair <int, int> > V;
	for (int i = 0; i < N; i++) {
		cin>>num1>>num2;
		V.push_back(make_pair(num1, num2));
		if (max_val[num1] == 0)
			max_val[num1] = num2;
		else {
			if (max_val[num1] <= num2)
				max_val[num1] = num2;
		}
	}
	sort(V.begin(), V.end());
	for (int i = 1; i <= N; i++) {
		if (max_val[i] != 0) {
			for (int j = 0; j < V.size(); j++) {
				if (i + V[j].first <= M
					&& max_val[i + V[j].first] <= max_val[i] + V[j].second)
					max_val[i + V[j].first] = max_val[i] + V[j].second;
			}
		}
	}
	for (int i = 1; i <= M; i++) {
		if (max <= max_val[i])
			max = max_val[i];
	}
	cout<<max;
}