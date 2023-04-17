#include <iostream>
using namespace std;

int N, K;
int w[101] = { 0 }, v[101] = { 0 };
int solve[101][100001] = { 0 };

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>K;
	for (int i = 1; i <= N; i++)
		cin>>w[i]>>v[i];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j >= w[i])
				solve[i][j] = max(solve[i-1][j], v[i] + solve[i - 1][j - w[i]]);
			else
				solve[i][j] = solve[i-1][j];
		}
	}
	cout<< solve[N][K];
}