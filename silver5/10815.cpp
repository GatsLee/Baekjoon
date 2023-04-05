#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(void) {
    int N, M, tmp;
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;
    unordered_map <int, int> map;
    for (int i = 0; i < N; i++)
    {
        cin>>tmp;
        map[tmp]++;
    }
    cin>>M;
    vector <int> V(M, 0);
    for (int j = 0; j < M; j++) {
        cin>>tmp;
        if (map[tmp] != 0)
            V[j] = 1;
    }
    for (int m = 0; m < M; m++)
        cout<<V[m]<<' ';

}