#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int min_paint[3];
int cur_paint[3];

int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>T;
    cin>>min_paint[0]>>min_paint[1]>>min_paint[2];
    T--;
    while (T--) {
        cin>>cur_paint[0]>>cur_paint[1]>>cur_paint[2];
        int tmp1 = min_paint[0], tmp2 = min_paint[1], tmp3 = min_paint[2];
        min_paint[0] = min(cur_paint[0] + tmp2, cur_paint[0] + tmp3);
        min_paint[1] = min(cur_paint[1] + tmp1, cur_paint[1] + tmp3);
        min_paint[2] = min(cur_paint[2] + tmp1, cur_paint[2] + tmp2);
    }
    int min_val = 999999999;
    for (int i = 0; i < 3; i++)
        if (min_val >= min_paint[i])
            min_val = min_paint[i];
    cout<<min_val;
}