#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int map[500][500];
int path[500][500];
int mv[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
int M, N;

// void    solve(void) {
//     stack < pair<int, int> > S;

//     S.push(make_pair(0,0));
//     path[0][0] = 1;
//     while (!S.empty()) {
//         int y = S.top().first;
//         int x = S.top().second;
//         S.pop();
//         for (int i = 0; i < 4; i++) {
//             int ny = y + mv[i][0];
//             int nx = x + mv[i][1];
//             if (ny >= M || ny < 0 || nx >= N || nx < 0)
//                 continue;
//             if (map[ny][nx] < map[y][x]) {
//                 S.push(make_pair(ny, nx));
//                 path[ny][nx]++;
//             }
//         }
//     }
// }

int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>M>>N;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin>>map[i][j];
    solve();
    cout<<path[M-1][N-1];
}