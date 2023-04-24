#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int map[500][500];
int y_mv[4] = {1, -1, 0, 0};
int x_mv[4] = {0, 0, 1, -1};
int cnt, max_vol;

void solve(int y, int x) {
    int size = 1;
    queue < pair <int, int> >Q;

    Q.push(make_pair(y, x));
    map[y][x] = 0;
    while(!Q.empty()) {
        int f_y = Q.front().first;
        int f_x = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = f_y + y_mv[i];
            int nx = f_x + x_mv[i];
            if (ny >= N || ny < 0 || nx >= M || nx < 0)
                continue;
            if (map[ny][nx] == 1) {
                Q.push(make_pair(ny, nx));
                map[ny][nx] = 0;
                size++;
            }
        }
    }
    if (size >= max_vol)
        max_vol = size;
}

int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin>>map[i][j];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 1)
            {
                solve(i, j);
                cnt++;
            }
        }
    }
    cout<<cnt<<'\n'<<max_vol<<'\n';

}