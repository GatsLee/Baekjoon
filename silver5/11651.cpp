#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair <int, int>a, pair <int, int>b)
{
    if (a.second != b.second)
        return (a.second < b.second);
    else
        return (a.first < b.first);
}

int main(void)
{
    int CNT, x, y;
    vector < pair<int, int> >v;

    cin>>CNT;
    while (CNT--)
    {
        cin>>x>>y;
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end(), cmp);
    for (size_t i = 0; i < v.size(); i++)
        cout<<v[i].first<<' '<<v[i].second<<'\n';
}