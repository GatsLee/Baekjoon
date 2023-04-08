#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int M, N;
int cnt;

char p1[2][2] =  {{'X', 'X'},
                {'.', '.'}};

char p2[2][2] = {{'.', 'X'},
                {'.', 'X'}};

char p3[2][2] = {{'.', '.'},
                {'X', 'X'}};

char p4[2][2] = {{'X', '.'},
                {'X', '.'}};

void    check_visited(vector < vector <char> > &is_visited, int flag, int y, int x)
{
     for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            is_visited[y + i][x + j] += flag;
}

bool   read_visited(vector < vector <char> >&is_visited, int flag, int y, int x) {

     for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if ((is_visited[y+i][x+j] & flag) != 0)
                return (false);
    return (true);
}

bool    is_avail(vector < vector <char> >&map, vector < vector <char> > &is_visited, int y, int x) {
    int f1 = 0, f2 = 0, f3 = 0, f4 = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (map[y + i][x + j] == p1[i][j])
                f1++;
            if (map[y + i][x + j] == p2[i][j])
                f2++;
            if (map[y + i][x + j] == p3[i][j])
                f3++;
            if (map[y + i][x + j] == p4[i][j])
                f4++;
        }
    }
    if (f1 == 4 && read_visited(is_visited, 1, y, x)) {
        check_visited(is_visited, 1, y, x);
        return (true);
    }
    if (f2 == 4 && read_visited(is_visited, 2, y , x)) {
        check_visited(is_visited, 2, y, x);
        return (true);
    }
    if (f3 == 4 && read_visited(is_visited, 4, y, x)) {
        check_visited(is_visited, 4, y, x);
        return (true);
    }
    if (f4 == 4 && read_visited(is_visited, 8, y, x)) {
        check_visited(is_visited, 8, y, x);
        return (true);
    }
    return (false);
}

void   solve(vector < vector <char> >&map) {
    vector < vector <char> > is_visited(M, vector <char>(N, 0));

    for (int i = 0; i < M - 1; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (is_avail(map, is_visited, i, j))
                cnt++;
        }
    }
}



int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>M>>N;
    vector < vector <char> > map(M, vector <char>(N));
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin>>map[i][j];
    solve(map);
    cout<<cnt<<'\n';
}