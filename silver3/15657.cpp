#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[10];
int isused[10];

void    solve(vector <int> V, int n, int start) {
    if (n == M) {
        for (int i = 0; i < M; i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
        return ;
    }
    for (int i = 1; i <= N; i++) {
        if (isused[i] == 0 && V[i] >= start) {
            arr[n] = V[i];
            solve(V, n+1, arr[n]);
            isused[i] = 0;
        }
    }
}

int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;
    vector <int> V(N+1, 0);
    for (int i = 1; i <= N; i++)
        cin>>V[i];
    sort(V.begin()+1, V.end());
    solve(V, 0, 0);
}