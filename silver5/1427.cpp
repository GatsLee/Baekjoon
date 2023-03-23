#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N;

int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;
    vector <int> V;
    while (N) {
        V.push_back(N % 10);
        N /= 10;
    }
    sort(V.begin(), V.end(), greater <int>());
    for (int i = 0; i < V.size(); i++)
        cout<<V[i];
}