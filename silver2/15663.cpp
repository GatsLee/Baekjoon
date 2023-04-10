#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[10];
int isused[10];

void    solve(vector <int> V, int n) {
    if (n == M) {
        for (int i = 0; i < M; i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
        return ;
    }
    for (int i = 0; i < V.size(); i++) {
        if (isused[i] == 0) {
            arr[n] = V[i];
            isused[i] = 1;
            solve(V, n+1);
            isused[i] = 0;
        }
    }
}

int main(void) {
    int num;
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;
    vector <int> V(N);
    for (int i = 0; i < N; i++)
        cin>>V[i];
    sort(V.begin(), V.end());
    solve(V, 0);
}
