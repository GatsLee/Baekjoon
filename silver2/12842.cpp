#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, S, PER;

void solve(long long gap, vector <pair <int, int> > &V) {

	long long start = 0;
	long long end = 1000

}


int main(void) {

	cin>>N>>S>>PER;
	vector <pair <int, int> > V(PER);
	for (int i = 0; i < PER; i++) {
		cin>>num;
		V[i] = make_pair(num, i + 1);
	}
	sort(V.begin(), V.end());
	solve(N-S, V);
}
