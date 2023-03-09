#include <iostream>
using namespace std;

int zero, one;

int fibonacci(int n) {
    if (n == 0)
    {
        zero++;
        return 0;
    } 
    else if (n == 1)
    {
        one++;
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main(void)
{
    int N, num;

    cin>>N;
    for (int i = 0; i < N; i++)
    {
        zero = 0;
        one = 0;
        cin>>num;
        fibonacci(num);
        cout<<zero<<' '<<one<<'\n';
    }
}