#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

long long  N, T;

int main(void) {
    long long time;
    int     cur_dir = 0;
    long long cur = 0;
    string  dir;
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>T;
    pair <long long, long long> P = make_pair(0,0);
    while (T) {
        while (N) {
            cin>>time>>dir;
            int time_diff = time - cur;
            if (cur_dir == 0)
                P.first += time_diff;
            else if (cur_dir == 1)
                P.second -= time_diff;
            else if (cur_dir == 2)
                P.first -= time_diff;
            else
                P.second += time_diff;
            if (dir == "right")
                cur_dir++;
            else
                cur_dir--;
            if (cur_dir == -1)
                cur_dir = 3;
            else
                cur_dir %= 4;
            T -= time_diff;
            N--;
            cur = time;
        }
        if (cur_dir == 0)
            P.first += T;
        else if (cur_dir == 1)
            P.second -= T;
        else if (cur_dir == 2)
            P.first -= T;
        else
            P.second += T;
        T = 0;
    } 
    cout<<P.first<<' '<<P.second<<'\n';
}