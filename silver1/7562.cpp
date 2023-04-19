#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int x_mv[8] = {1, 2, 2, 1, -1, -2, -2 ,-1};
int y_mv[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int T, si;
int x1, y1, x2, y2;

int solve(void) {
    int ret;
    vector < vector <int> >chess(si, vector <int>(si, 0));
    queue <pair <int, int> > Q;
    Q.push(make_pair(y1, x1));
    chess[y1][x1] = 1;
    while (!Q.empty()) {
        int y = Q.front().first;
        int x = Q.front().second;
        Q.pop();
        if (y == y2 && x == x2) {
            ret = chess[y][x];
            break ;
        }
        for (int i = 0; i < 8; i++) {
            int ny = y + y_mv[i];
            int nx = x + x_mv[i];
            if (ny < 0 || nx < 0 || ny >= si || nx >= si)
                continue ;
            if (chess[ny][nx] == 0) {
                Q.push(make_pair(ny, nx));
                chess[ny][nx] = chess[y][x] + 1;
            }
        }
    }
    return (ret - 1);
}


int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>T;
    vector <int> ans(T);
    for (int i = 0; i < T; i++) {
        cin>>si;
        cin>>y1>>x1>>y2>>x2;
        ans[i] = solve();
    }
    for (int m = 0; m < T; m++)
        cout<<ans[m]<<'\n';
}