#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
pair <int, int> min_paint[3];
int cur_paint[3];

int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>T;
    cin>>cur_paint[0]>>cur_paint[1]>>cur_paint[2];
    min_paint[0] = make_pair(cur_paint[0], 0);
    min_paint[1] = make_pair(cur_paint[1], 1);
    min_paint[2] = make_pair(cur_paint[0], 2);
    T--;
    for (int i = 0; i < T; i++) {
        cin>>cur_paint[0]>>cur_paint[1]>>cur_paint[2];
        if (min_paint[2].second != 2 && min_paint[1].first > min_paint[2].first)
            min_paint[0] = make_pair(cur_paint[0] + min_paint[2].first, min_paint[2].second);
        else if ()
            min_paint[0] = make_pair(cur_paint[0] + min_paint[1].first, min_paint[1].second);
        if (min_paint[2].second != 2 && min_paint[0].first > min_paint[2].first)
            min_paint[1] = make_pair(cur_paint[1] + min_paint[2].first, min_paint[2].second);
        else
            min_paint[1] = make_pair(cur_paint[1] + min_paint[0].first, min_paint[0].second);
        if (min_paint[1].second != 2 && min_paint[0].first > min_paint[1].first)
            min_paint[2] = make_pair(cur_paint[2] + min_paint[1].first, min_paint[1].second);
        else
            min_paint[2] = make_pair(cur_paint[2] + min_paint[0].first, min_paint[0].second);
    }

    int min_val = 999999999;
    for (int i = 0; i < 3; i++)
        if (min_val >= min_paint[i].first)
            min_val = min_paint[i].first;
    cout<<min_val;
}