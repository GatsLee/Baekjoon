#include <iostream>
#include <vector>
using namespace std;

void put_stars(int n, int x, int y, vector < vector <char> >&MAP) {
    if (n == 3) {
        MAP[y][x] = '*';

        MAP[y + 1][x - 1] = '*';
        MAP[y + 1][x + 1] = '*';

        MAP[y + 2][x - 2] = '*';
        MAP[y + 2][x - 1] = '*';
        MAP[y + 2][x] = '*';
        MAP[y + 2][x + 1] = '*';
        MAP[y + 2][x + 2] = '*';
    }
    else {
        put_stars(n / 2, x, y, MAP);
        put_stars(n / 2, x - n/2, y + n/2, MAP);
        put_stars(n / 2, x - n/2 + n, y + n/2, MAP);
    }
}

int main(void) {
	int N;

	cin>>N;
	vector < vector <char> >MAP(N, vector <char>(2 * N - 1, ' '));
	put_stars(N, N-1, 0, MAP);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++) {
			cout<<MAP[i][j];
		}
		cout<<'\n';
	}

}
