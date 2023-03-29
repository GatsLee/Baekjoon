#include <iostream>
#include <string>
#include <algorithm>
using namespace std;



int main(void) {
    string A, B;
    int min_diff = 50;
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>A>>B;
    for (int i = 0; i < B.length(); i++) {
        if (i + A.length() > B.length())
            break;
        int tmp_idx = i;
        int diff = 0;
        for (int j = 0; j < A.length(); j++) {
            if (A[j] != B[tmp_idx])
                diff++;
            tmp_idx++;
        }
        if (min_diff >= diff)
            min_diff = diff;
    }
    cout<<min_diff;
}