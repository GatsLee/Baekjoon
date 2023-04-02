#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int T;

int main(void) {
    pair <int, int>one;
    pair <int, int>two;
    int rad1, rad2;
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>T;
    vector <int> V(T);
    int i = 0;
    while (T--) {
        cin>>one.first>>one.second>>rad1;
        cin>>two.first>>two.second>>rad2;
        long long dist = (two.first - one.first) * (two.first - one.first)
            + (two.second - one.second) * (two.second - one.second);
        long long rad1_doub = rad1 * rad1;
        long long rad2_doub = rad2 * rad2;
        int max_rad = max(rad1, rad2);
        int min_rad = min(rad1, rad2);
        if (one.first == two.first && one.second == two.second && rad1 == rad2)
            V[i] = -1;
        else if (dist == (rad1 + rad2) * (rad1 + rad2) 
                || dist == (max_rad - min_rad) * (max_rad - min_rad))
            V[i] = 1;
        else if ((max_rad - min_rad) * (max_rad - min_rad) < dist
                && dist < (rad1 + rad2) * (rad1 + rad2))
            V[i] = 2;
        else
            V[i] = 0;
        i++;
    }
    for (int j= 0; j < V.size(); j++)
        cout<<V[j]<<'\n';
}