#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    unsigned int K, N, tmp, ret;
    unsigned int mid, low, hig, cnt = 0;

    cin>>K>>N;
    vector <int> v(K);
    for (int i = 0; i < K; i++)
    {
        cin>>tmp;
        v[i] = tmp;
    }
    sort(v.begin(), v.end());
    low = 1;
    hig = v.back();
    while (low <= hig)
    {
        cnt = 0;
        mid = (low + hig) / 2;
        for (int i = 0; i < v.size(); i++)
            cnt += (v[i] / mid);
        if (cnt >= N)
        {
            low = mid + 1;
            ret = max(ret, mid);
        }
        else
            hig = mid - 1;
    }
    cout<<ret<<'\n';
}