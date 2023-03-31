#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int     is_it_promising(int i, vector <int> &V) {
    int temp;
    
    for (int j = 0; j < i; j++) {
        if (V[i] - V[j] < 0)
            temp = (V[i] - V[j]) * (-1);
        else
            temp = (V[i] - V[j]);
        if (V[i] == V[j] || i - j == temp)
            return (0);
    }
    return (1);
}

void    solve(int i, vector <int> &V, int &cnt)
{
    if (i == N) {
        cnt++;
        V.clear();
        return ;
    }
    for (int idx = 0; idx < N; idx++) {
        V[i] = idx;
        if (is_it_promising(i, V))
            solve(i + 1, V, cnt);
    }
}

int main(void) {
    int cnt = 0;
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;
    vector <int> V(N, 0);
    solve(0, V, cnt);
    cout<<cnt;
}