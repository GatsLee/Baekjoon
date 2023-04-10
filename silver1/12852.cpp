#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;
    vector <int> V(N+1, 0);
    V[1] = 0;
    V[2] = 1;
    V[3] = 2;
    for (int i = 4; i <= N; i++) {
        V[i] = V[i-1] + 1;
        if (i % 3 == 0)
            V[i] = min(V[i] , V[i/3] + 1);
        if (i % 2 == 0)
            V[i] = min(V[i], V[i/2] + 1);
    }               
    for (int i = 1; i <= N; i++)
        cout<<V[i]<<' ';
}