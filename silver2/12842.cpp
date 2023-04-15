#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

<<<<<<< HEAD
int solve(int gap, vector <int> &V) {
    int sec = 0;

    while (1) {

    }
}

int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, s, m;
    cin>>n>>s>>m;
    vector <int> V(m, 0);
    for (long long i = 0; i < m; i++)
        cin>>V[i];
    cout<<solve(n - s, V);

}
=======
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
>>>>>>> 9aec1eebe1f080fcbe38b41aa4984b0fe5e44c01
