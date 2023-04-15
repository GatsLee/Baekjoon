#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int gap, vector <int> &V) {
    int sec = 0;

    while (1) {

    }
}

int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, s, m;
    cin>>n>>s>>m;
    vector <int> V(m, 0);
    for (long long i = 0; i < m; i++)
        cin>>V[i];
    cout<<solve(n - s, V);

}