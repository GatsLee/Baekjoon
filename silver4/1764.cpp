#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
    int N, M;
    string str;

    cin>>N>>M;
    map <string, int>map;
    std::map <string, int>::iterator i;
    vector <string>v;
    for (int i = 0; i < N;i++)
    {
        cin>>str;
        map[str]++;
    }
    for (int j = 0; j < M; j++)
    {
        cin>>str;
        map[str]++;
    }
    for (i = map.begin(); i != map.end();i++)
    {
        if (i->second == 2)
            v.push_back(i->first);
    }
    cout<<v.size()<<'\n';
    for (int m = 0; m < v.size(); m++)
        cout<<v[m]<<'\n';
}