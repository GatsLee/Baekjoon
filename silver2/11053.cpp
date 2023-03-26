#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int main(void) {
    int num;
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;
    vector < int > V(N);
    vector < int > INC_SEQ(N, 1);
    for (int i = 0; i < N; i++) {
        cin>>V[i];
    }
    for (int j = 0; j < N; j++)
        for (int m = 0; m < j; m++)
            if (V[m] < V[j])
                INC_SEQ[j] = max(INC_SEQ[j], INC_SEQ[m] + 1);
    sort(INC_SEQ.begin(), INC_SEQ.end());
    cout<<INC_SEQ.back();
}