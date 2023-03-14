#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int N, M;
int DAY_CNT = 0;
queue < pair <int , int> > Q;
int x_move[4] = {0,0,1,-1};
int y_move[4] = {1,-1,0,0};

int BFS(vector < vector < pair <int, int> > >&map, vector < pair <int, int> > &ripe)
{
    for (int i = 0; i < ripe.size(); i++)
    {
        Q.push(make_pair(ripe[i].first, ripe[i].second));
        map[ripe[i].first][ripe[i].second].first = -1;
    }
    while (!Q.empty())
    {
        int rotate_check = 0;
        int y = Q.front().first;
        int x = Q.front().second;
        DAY_CNT = map[y][x].second;
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + y_move[i];
            int nx = x + x_move[i];
            int day_check  = map[y][x].second + 1;
            if (ny >= M || ny < 0 || nx >= N || nx < 0)
                continue ;
            if (map[ny][nx].first == 0)
            {
                Q.push(make_pair(ny, nx));
                map[ny][nx].first = -1;
                map[ny][nx].second = day_check;
            }
            else if (map[ny][nx].first == 1)
            {
                Q.push(make_pair(ny, nx));
                map[ny][nx].first = -1;
                map[ny][nx].second = map[y][x].second;
            }
        }
    }
    return (DAY_CNT);
}

int main(void)
{
    cin>>N>>M;
    vector < vector <pair <int, int> > >map(M, vector<pair <int ,int> >(N));
    vector < pair<int, int> >ripe;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int num;
            cin>>num;
            map[i][j] = make_pair(num, 0);
            if (num == 1)
                ripe.push_back(make_pair(i,j));
        }
    }    
    BFS(map, ripe);
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j< N; j++)
        {
            if (map[i][j].first != -1)
            {
                cout<<-1;
                return (0);
            }
        }
    }
    cout<<DAY_CNT;
}