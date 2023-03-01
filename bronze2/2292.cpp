#include <iostream>
using namespace std;

long long sig(int n)
{
    long long total = 1;

    for (int i = 0; i < n; i++)
        total += 6 * i;
    return (total);
}



int main(void)
{
    long long RM;
    int i = 1;

    cin>>RM;
    if (RM == 1)
        cout<<1;
    else
    {
        while(1)
        {
            if (RM > sig(i) && RM <= sig(i+1))
            {
                cout<<i + 1;
                return (0);
            }
            i++;
        }
    }
    return (0);
}