#include <iostream>
#include <vector>
using namespace std;

int N;

int	x_mv[4] = {0,0,3,-3};
int	y_mv[4] = {3,-3,0,0};


void    put_space (vector < vector <char> > &V, int x, int y, int size) {

	if (x >= N || y >= N || x < 0 || y < 0)
		return ;
	if (x == size / 3 && y == size / 3) {
		for (int i = y; i < y + size / 3; i++)
			for (int j = x; j < x + size / 3; j++)
				V[i][j] = ' ';
		for (int i = 0; i < 4; i++)
			put_space(V, x + x_mv[i], y + y_mv[i], size / 3);
	}
	else {
		V[y + 1][x + 1] = ' ';
		for (int i = 0; i < 4; i++)
			put_space(V, x + x_mv[i], y + y_mv[i], size);
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>N;
	vector < vector <char> > V(N, vector <char>(N, '*'));
	// put_space recursively
	put_space(V, 0, 0, N);
	//print_stars
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout<<V[i][j];
		}
		cout<<'\n';
	}
}