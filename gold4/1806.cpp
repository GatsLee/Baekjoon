#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;
    vector <long long> V(N);
    for (long long i = 0; i < N; i++)
        cin>>V[i];
    long long start = 0;
    long long end = 0;
    long long p_sum = 0;
    long long ans = 0;
    while (end <= N)
    {
        if (p_sum >= M)
            p_sum -= V[start++];
        else if (p_sum < M)
            p_sum += V[end++];
        if (p_sum == M)
            ans++;
    }
    cout<<ans;
}