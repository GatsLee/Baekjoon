#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
long long ret[101];

void    make_seq(int m) {
    if (m <= 5)
        return ;
    for (int i = 6; i <= m; i++) {
        ret[i] = ret[i-1] + ret[i-5];
    }
}

int main(void) {
    int N, max = 0;
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>T;
    ret[1] = 1;
    ret[2] = 1;
    ret[3] = 1;
    ret[4] = 2;
    ret[5] = 2;
    vector <int> V;
    while (T--) {
        cin>>N;
        V.push_back(N);
        if (N >= max)
            max = N;
    }
    make_seq(max);
    for (int i = 0; i < V.size(); i++)
        cout<<ret[V[i]]<<'\n';
}