#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int N;

int find_GCD(int a, int b)
{
    while(1) {
        int r = a%b;
        if (r == 0) return (b);

        a = b;
        b = r;
    }
}

int main(void) {
    int x, y;
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    unordered_map <pair<int, int>, int>FREQ_1_3;
    unordered_map <pair<int, int>, int>FREQ_2_4;
    unordered_map <int>FREQ_line;
    vector <pair<int, int> >INC;
    cin>>N;
    for (int i = 0; i < N; i++) {
        cin>>x>>y;
        int sign = 1;
        if (x == 0) {
            if (FREQ_1_3[mak] == 0)
                INC.push_back(3000000);
            if (FREQ_1_3[-3000000] == 0)
                INC.push_back(-3000000);
            if (y > 0)
                FREQ_1_3[3000000]++;
            else
                FREQ_1_3[-3000000]++;
        }
        else if (y == 0) {
            if (FREQ_1_3[2000000] == 0)
                INC.push_back(2000000);
            if (FREQ_1_3[-2000000] == 0)
                INC.push_back(-2000000);
            if (x > 0)
                FREQ_1_3[2000000]++;
            else
                FREQ_1_3[-2000000]++;
        }
        else {
            // 1,4 / 2, 3
            int sign = 1;
            if (x < 0)
                sign = -1;
            int tmp = find_GCD(abs(x), abs(y));
            double inc = abs((y / tmp) / (x / tmp));

            if ((x > 0 && y > 0) || (x < 0 && y < 0)) {
                if (FREQ_1_3[inc * sign] == 0)
                    INC.push_back(inc * sign);
                FREQ_1_3[inc * sign]++;
            }
            else {
                if (FREQ_2_4[inc * sign] == 0)
                    INC.push_back(inc * sign);
                FREQ_2_4[inc * sign]++;
            }
        }
    }
    int max = 0;
    for (int i = 0; i < INC.size(); i++) {
        if (max <= FREQ_1_3[INC[i]])
            max = FREQ_1_3[INC[i]];
        if (max <= FREQ_2_4[INC[i]])
            max = FREQ_2_4[INC[i]];
    }
    cout<<max;

}