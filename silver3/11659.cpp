#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int main(void) {
    int num, p1, p2;
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;
    vector <long long> sum(N+1);
    cin>>sum[1];
    for (int i = 2; i <= N; i++) {
        cin>>num;
        sum[i] = sum[i-1] + num;
    }
    while (M--) {
        cin>>p1>>p2;
        cout<<sum[p2]-sum[p1 - 1]<<'\n';
    }
}