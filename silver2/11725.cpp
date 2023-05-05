#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector <int> node[100001];
int p[100001];

void	solve(int par)
{
	queue <int> Q;

	Q.push(par);
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		for (int nxt : node[cur]) {
			if (p[cur] == nxt) continue ;
			Q.push(nxt);
			p[nxt] = cur;
		}
	}
}

// void	solve(int par) {
// 	for (int nxt : node[par]) {
// 		if (p[par] == nxt) continue ;
// 		p[nxt] = par;
// 		solve(nxt);
// 	}
// }

int main(void) {
	int n1, n2;
	cin>>N;
	for (int i = 0; i < N - 1; i++) {
		cin>>n1>>n2;
		node[n1].push_back(n2);
		node[n2].push_back(n1);
	}
	solve(1);
	for (int i = 2; i <= N; i++)
		cout<<p[i]<<'\n';
}
