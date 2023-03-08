#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, tmp;
    string  str;

    cin>>N>>M;
    unordered_map <string, int>map_name;
    vector <string>map_idx(N);
    vector <string>result;
    for (int i = 1; i <= N; i++)
    {
        cin>>str;
        map_name[str] = i;
        map_idx[i - 1] = str;
    }
    for (int j = 0; j < M; j++)
    {
        cin>>str;
        if (str[0] >= 'A' && str[0] <= 'Z')
            result.push_back(to_string(map_name[str]));
        else
            result.push_back(map_idx[stoi(str) - 1]);
    }
    for (int m =0; m < result.size(); m++)
        cout<<result[m]<<'\n';
}