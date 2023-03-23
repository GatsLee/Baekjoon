#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long fibo[3];
int N;

int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (i % 3 == 2)
            fibo[i % 3] =(fibo[0] + fibo[1]) % 1000000007;
        else if (i % 3 == 0)
            fibo[i % 3] = (fibo[1] + fibo[2]) % 1000000007;
        else
            fibo[i % 3] = (fibo[0] + fibo[2]) % 1000000007;
    }
    cout<<fibo[N % 3];
}