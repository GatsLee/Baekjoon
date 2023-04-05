#include <iostream>
using namespace std;

int N, M;
int arr[10];
int isused[10];

void    solve(int n) {
    if (n == M) {
        for (int i = 0; i < M; i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
        return ;
    }
    for (int i = 1; i <= N; i++) {
        if (isused[i] == 0) {
            arr[n] = i;
            solve(n+1);
            isused[i] = 0;
        }
    }
}


int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;
    solve(0);
}