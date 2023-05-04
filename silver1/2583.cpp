#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int map[100][100];
int M, N, K;
int cnt;
int mv[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

int solve(int y, int x) {
    int size = 1;
    queue < pair <int, int> > Q;

    Q.push(make_pair(y, x));
    map[y][x] = 1;
    while (!Q.empty()) {
        int top_y = Q.front().first;
        int top_x = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = top_y + mv[i][0];
            int nx = top_x + mv[i][1];
            if (ny >= M || ny < 0 || nx >= N || nx < 0)
                continue;
            if (map[ny][nx] == 0) {
                Q.push(make_pair(ny, nx));
                map[ny][nx] = 1;
                size++;
            }
        }
    }
    return (size);
}

int main(void) {
    int x1, y1, x2, y2;
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>M>>N>>K;
    for (int i = 0; i < K; i++) {
        cin>>x1>>y1>>x2>>y2;
        for (int x = x1; x < x2; x++)
            for (int y = y1; y < y2; y++)
                map[y][x] = 1;
    }
    vector <int> V;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 0)
            {
                V.push_back(solve(i, j));
                cnt++;
            }
        }
    }
    sort(V.begin(), V.end());
    cout<<cnt<<'\n';
    for (int i = 0; i < V.size(); i++)
        cout<<V[i]<<' ';
}