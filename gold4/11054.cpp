#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int val[1000];
int bitonic[1001][1001];

int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;
    for (int i = 0; i < 1000; i++)
        cin>>val[i];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {

        }
    }
}


#include <iostream>
#include <string>
using namespace std;

int main(void) {

    int C, K;

    cin>>C>>K;
    vector <long long> V(C);
    for (int i = 0; i < C; i++)
        cin>>V[i];
    sort(V.begin(), V.end());
    cout<<V[K-1];
}

