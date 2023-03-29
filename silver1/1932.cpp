#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int N, m = 0;
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;
    vector <int> cur_max(N, 0);
    vector <int> bef_max(N, 0);
    vector <int> line(N, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++)
            cin>>line[j];
        for (int j = 0; j <= i; j++) {
            if (j == 0)
                cur_max[j] = line[j] + bef_max[j];
            else if (j == i)
                cur_max[j] = line[j] + bef_max[j-1];
            else
                cur_max[j] = max(line[j] + bef_max[j], line[j] + bef_max[j - 1]);
        }
        bef_max = cur_max;
    }
    for (int i = 0; i < N; i++)
        if (m <= bef_max[i])
            m = bef_max[i];
    cout<<m;
}