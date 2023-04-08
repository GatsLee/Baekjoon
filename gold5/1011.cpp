#include <iostream>
#include <cmath>
using namespace std;

int solve(int x, int y) {
    int cnt = 1;
    long long gap = y - x;
    if (gap == 1)
        return (1);
    if (gap == 2)
        return (2);
    while (true) {
        cnt++;
        if (gap >= (int)pow(2, cnt - 1)
            && gap <= (int)(pow(2, cnt) - 1))
            break ;
    }
    return (cnt + 1);
}

int main(void) {
    int T, x, y;
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>T;
    while (T--) {
        cin>>x>>y;
        cout<<solve(x, y)<<'\n';
    }
}