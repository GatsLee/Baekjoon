#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;



int main(void) {
	int N;
	long long max_num = LLONG_MIN;
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>N;
	vector <int> V(N);
	vector <int> MAX_VAL(N);
	for (int i = 0; i < N; i++)
		cin>>V[i];
	MAX_VAL[0] = V[0];
	for (int i = 1; i < N; i++)
		MAX_VAL[i] = max(V[i], MAX_VAL[i-1] + V[i]);
	for (int i = 0; i < N; i++)
		if (max_num <= MAX_VAL[i])
			max_num = MAX_VAL[i];
	cout<<max_num;
}