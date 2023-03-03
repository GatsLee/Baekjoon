#include <iostream>
using namespace std;

int recur_find(int K, int N)
{
    if (N == 1)
        return (1);
    if (K == 0)
        return (N);
    return (recur_find(K - 1, N) + recur_find(K, N - 1));
}

int main(void)
{
    int T, K, N;
    cin>>T;
    while (T--)
    {
        cin>>K>>N;
        cout<<recur_find(K, N)<<'\n';
    }
}