#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int M, N, K;

int x_move[4] = {0,0,-1,1};
int y_move[4] = {1,-1,0,0};

void    find_cabbage(void)
{
    int x, y;

    cin>>M>>N>>K;
    vector < vector <int> > map(N, vector<int>(M, 0));
    stack <pair <int, int> > S;
    while (K--)
    {
        cin>>x>>y;
        map[y][x] = 1;
    }
    x = 0, y = 0;
    S.push(make_pair(y,x));
    while (!S.empty())
    {
        for (int i = 0; i < 4; i++) {
            y = S.top().first + y_move[i];
            x = S.top().second + x_move[i];
            if (y < 0 || y > N || x < 0 || x > M)
                continue ;
            if (map[y][x] == 1)
                S.push(make_pair(y, x));
        }
        
    }
}

int main(void)
{
    int CASE;

    cin>>CASE;
    while (CASE--)
        find_cabbage();
}