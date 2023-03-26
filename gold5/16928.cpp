#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

int N, M;
int  num_map[101];

void BFS(unordered_map <int , int> &VAR)
{
	int cur, cnt;

	queue <int> Q;
	Q.push(1);
	while (!Q.empty())
	{
		cur = Q.front();
		if (VAR[cur] != 0) {
			Q.push(VAR[cur]);
			num_map[VAR[cur]] = num_map[cur];
			Q.pop();
			continue ;
		}
		cnt = num_map[cur] + 1;
		Q.pop();
		for (int i = 1; i <= 6; i++)
		{
			int new_pos = cur + i;
			if (new_pos > 100)
				continue;
			if (num_map[new_pos] == 0) {
				if (VAR[new_pos] != 0 && num_map[VAR[new_pos]] == 0) {
					Q.push(VAR[new_pos]);
					num_map[VAR[new_pos]] = cnt;
				}
				else {
					Q.push(new_pos);
					num_map[new_pos] = cnt;
				}
			}
			}
		}
}

int main(void) {
	int num1, num2;
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>N>>M;
	vector <int> V(101, 9999);
	unordered_map <int , int> VAR;
	//ladder
	for (int i = 0; i < N; i++) {
		cin>>num1>>num2;
		VAR[num1] = num2;
	}
	//snake
	for (int j = 0; j < M; j++) {
		cin>>num1>>num2;
		VAR[num1] = num2;
	}
	BFS(VAR);
	cout<<num_map[100];
}