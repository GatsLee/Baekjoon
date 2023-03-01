#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int N, M, total, max = 0;

    cin>>N>>M;
    vector<int>card(N);
    for (int i = 0; i < N; i++)
        cin>>card[i];
    for (int j = 0; j <= N - 3; j++)
    {
        for (int m = j+1; m <= N - 2; m++)
        {
            for (int n = m+1; n <= N - 1; n++)
            {
                total = card[j] + card[m] + card[n];
                if (M >= total && max < total)
                    max = total;
            }
        }
    }
    cout<<max;
}