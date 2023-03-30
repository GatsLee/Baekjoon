#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int N;

int x_mv[4] = {1,-1,0,0};
int y_mv[4] = {0,0,1,-1};

void    DFS(vector < vector <int> >&tmp, int y, int x, int lev) {
    queue < pair <int, int> > Q;

    Q.push(make_pair(y, x));
    tmp[y][x] = lev;
    while (!Q.empty()) {
        int cur_y = Q.front().first;
        int cur_x = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cur_y + y_mv[i];
            int nx = cur_x + x_mv[i];
            if (ny >= N || nx >= N || ny < 0 || nx < 0)
                continue ;
            if (tmp[ny][nx] > lev) {
                Q.push(make_pair(ny, nx));
                tmp[ny][nx] = lev;
            }
        }
    }
}

int    solve(vector < vector <int> > map, int lev)
{
    int area_div = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] > lev) {
                DFS(map, i, j, lev);
                area_div++;
            }
        }
    }
    return (area_div);
}

int main(void) {
    int min_lev = INT_MAX, max_lev = INT_MIN;
    int max_div = 0;
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;
    vector < vector <int> > map(N, vector <int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin>>map[i][j];
            if (min_lev >= map[i][j])
                min_lev = map[i][j];
            if (max_lev <= map[i][j])
                max_lev = map[i][j];
        }
    }
    
    for (int l = min_lev - 1; l < max_lev; l++) {
        int area_div = solve(map, l);
        if (area_div >= max_div)
            max_div = area_div;
    }
    cout<<max_div;

}