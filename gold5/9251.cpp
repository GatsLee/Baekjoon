#include <iostream>
#include <vector>
#include <string>
using namespace std;

string s1, s2;
int max_len[1001][1001];

int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>s1>>s2;
    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            if (s1[i-1] == s2[j-1])
                max_len[i][j] = max_len[i-1][j-1] + 1;
            else
                max_len[i][j] = max(max_len[i-1][j], max_len[i][j-1]);
        }
    }
    cout<<max_len[s1.length()][s2.length()];
}