#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

unsigned long long set[101];

int main(void) {
    int N;
    int zero = 1, nine = 1;
    int div = 2;  
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    set[1] = 9;
    set[2] = 17;
    for (int i = 3; i <= N; i++) {
        set[i] = ((set[i-1] - div) * 2 + (div)) % 1000000;
        if (i % 2 == 0)
            zero *= 3;
        else
            nine *= 2;
        div = zero + nine;
        }
    cout<<set[N];
}