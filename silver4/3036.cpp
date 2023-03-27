#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find_GCD(int checker, int num)
{
    int ret = 1;;

    for (int i = 1; i <= checker && i <= num; i++) {
        if (checker % i == 0 && num % i == 0)
            ret = i;
    }
    return (ret);
}


int main(void) {
    int N, checker, num;
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>checker;
    for (int i = 0; i < N - 1; i++) {
        cin>>num;
        int gcd = find_GCD(checker, num);
        cout<<checker/gcd<<'/'<<num/gcd<<'\n';
    }

}