#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int N;

int x_mv[4] = {0, 0, 1, -1};
int y_mv[4] = {1, -1, 0, 0};

void    weak(int y,  int x,  vector < vector <char> > &map)
{
    stack < pair<int , int> > S;

    map[y][x] = 'V';
    S.push(make_pair(y, x));
    while (!S.empty())
    {
        int tmp_y = S.top().first;
        int tmp_x = S.top().second;
        S.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = tmp_y + x_mv[i];
            int nx = tmp_x + y_mv[i];
            if (ny >= N || ny < 0 || nx >= N || nx < 0)
                continue ;
            if (map[ny][nx] == 'R' || map[ny][nx] == 'G')
            {
                S.push(make_pair(ny, nx));
                map[ny][nx] = 'V';
            }
        }
    }
}

void    not_weak(int y,  int x,  vector < vector <char> > &map)
{
    stack < pair<int , int> > S;

    char checker = map[y][x];
    map[y][x] = 0;
    S.push(make_pair(y, x));
    while (!S.empty())
    {
        int tmp_y = S.top().first;
        int tmp_x = S.top().second;
        S.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = tmp_y + x_mv[i];
            int nx = tmp_x + y_mv[i];
            if (ny >= N || ny < 0 || nx >= N || nx < 0)
                continue ;
            if (map[ny][nx] == checker)
            {
                S.push(make_pair(ny, nx));
                map[ny][nx] = 0;
            }
        }
    }
}


int main(void)
{
    string line;
    int yes = 0, no = 0;

    cin>>N;
    vector < vector <char> >map1(N, vector <char>(N));
    vector < vector <char> >map2(N, vector <char>(N));
    for (int i = 0; i < N; i++)
    {
        cin>>line;
        for (int j = 0; j < N; j++)
        {
            map1[i][j] = line[j];
            map2[i][j] = line[j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map1[i][j] != 0)
            {
                not_weak(i, j, map1);
                no++;
            }
            if (map2[i][j] == 'R' || map2[i][j] == 'G')
            {
                weak(i, j, map2);
                yes++;
            }
            else if (map2[i][j] == 'B')
            {
                not_weak(i, j, map2);
                yes++;
            }
        }
    }
    cout<<no<<' '<<yes;
}