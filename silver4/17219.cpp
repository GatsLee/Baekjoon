#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
    int     N, M;
    string  site, pw;

    cin>>N>>M;
    map <string, string>m;
    vector <string>v;
    for (int i = 0; i < N; i++)
    {
        cin>>site;
        cin>>pw;
        m[site] = pw;
    }
    for (int j = 0; j < M; j++)
    {
        cin>>site;
        v.push_back(m[site]);
    }
    for (int i = 0; i < v.size(); i++)
        cout<<v[i]<<'\n';
}