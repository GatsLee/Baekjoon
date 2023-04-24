#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int width;

int solve(vector < vector <int> > &sticker) {
	vector < vector <int> >max_table(2, vector <int>(width));
	max_table[0][0] = sticker[0][0];
	max_table[1][0] = sticker[1][0];
	for (int i = 1; i < width; i++) {
		if (i == 1) {
			max_table[0][i] = sticker[0][i] + max_table[1][i-1];
			max_table[1][i] = sticker[1][i] + max_table[0][i-1];
		}
		else {
			max_table[0][i] = sticker[0][i] + max(max_table[1][i-1], max_table[1][i-2]);
			max_table[1][i] = sticker[1][i] + max(max_table[0][i-1], max_table[0][i-2]);
		}
	}
	return (max(max_table[0][width - 1], max_table[1][width -1]));
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>T;
	while(T--) {
		cin>>width;
		vector < vector <int> >sticker(2, vector <int>(width));
		for (int i = 0; i < 2; i++)
			for (int j = 0;j < width;j++)
				cin>>sticker[i][j];
		cout<<solve(sticker)<<'\n';
	}

}