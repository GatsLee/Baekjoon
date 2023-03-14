#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int APT_CNT = 0;
stack < pair<int, int> > S;

int x_mv[4] = {0,0,1,-1};
int y_mv[4] = {1,-1,0,0};


int DFS(vector < vector <int> > &map, int y, int x)
{
    int house_cnt = 0;

    S.push(make_pair(y, x));
    map[y][x] = 0;
    while (!S.empty())
    {
        int top_y = S.top().first;
        int top_x = S.top().second;
        S.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = top_y + y_mv[i];
            int nx = top_x + x_mv[i];
            if (ny >= N || ny < 0 || nx >= N || nx < 0)
                continue;
            if (map[ny][nx] == 1)
            {
                S.push(make_pair(ny, nx));
                map[ny][nx] = 0;
            }
        }
        house_cnt++;
    }
    return (house_cnt);
}


int main(void)
{
    string line;

    cin>>N;
    vector < vector <int> >map(N, vector<int>(N));
    vector <int>v;
    for (int i = 0; i < N; i++)
    {
        cin>>line;
        for (int j = 0; j < N; j++)
        {
            int num = line[j] - '0';
            map[i][j] = num;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == 1)
            {
                int house_cnt = DFS(map, i, j);
                v.push_back(house_cnt);
                APT_CNT++;
            }
        }
    }
    cout<<APT_CNT<<'\n';
    sort(v.begin(), v.end());
    for (int i = 0 ; i <v.size(); i++)
        cout<<v[i]<<'\n';
}