#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int N;
    int total = 0;

    cin>>N;
    vector <int> v(N);
    for (int i = 0; i < N; i++)
        cin>>v[i];
    sort(v.begin(), v.end());
    for (int j = 0; j < N; j++)
    {
        total += (N - j) * v[j];
    }
    cout<<total;
}