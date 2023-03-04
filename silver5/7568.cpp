#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int N, x, y;
    int rank = 1;
    vector <pair <int, int> >v;

    cin>>N;
    vector <int> set(N);
    while(N--)
    {
        cin>>x>>y;
        v.push_back(make_pair(x, y));
    }
    for (int i = 0; i < v.size(); i++)
    {
        rank = 1;
        for (int j = 0; j < v.size(); j++)
        {
            if ((v[i].first < v[j].first) && (v[i].second < v[j].second))
                rank++;
        }
        set[i] = rank;
    }
    for (int m = 0; m < set.size(); m++)
        cout<<set[m]<<' ';
}