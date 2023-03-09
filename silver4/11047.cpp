#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int N, K;
    int cnt = 0;
    int idx;

    cin>>N>>K;
    vector <int>v(N);
    for (int i = 0; i < N; i++)
        cin>>v[i];
    idx = v.size() - 1;
    while (K >= 0 && idx >= 0)
    {
        if (K / v[idx] != 0)
        {
            cnt += K / v[idx];
            K %= v[idx];
        }
        else
            idx--;
    }
    cout<<cnt;
}