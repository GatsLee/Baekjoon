#include <iostream>
#include <vector>
using namespace std;

int N;

void    put_space (vector < vector <char> > &V, int x, int y) {
	if (x > N || y > N)
		return ;
	if (x % N == 3 && y % N == 3) {
		for (int i = y; i < y + N / 3; i++)
			for (int j = x; j < x + N / 3; j++)
				V[i][j] = ' ';
	}
	else if (x == N / 3 && y == N / 3) {
		for (int i = y; i < y + N / 3; i++)
			for (int j = x; j < x + N / 3; j++)
				V[i][j] = ' ';
	}
	else {
		V[y + 1][x + 1] = ' ';
		put_space(V, x + 3, y);
		put_space(V, x, y+3);
		put_space(V, x+3, y+3);
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>N;
	vector < vector <char> > V(N, vector <char>(N, '*'));
	// put_space recursively
	put_space(V, 0, 0);
	//print_stars
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout<<V[i][j];
		}
		cout<<'\n';
	}
}