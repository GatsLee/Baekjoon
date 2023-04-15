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

}