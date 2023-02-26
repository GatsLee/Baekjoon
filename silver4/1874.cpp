#include <iostream>
using namespace std;

int arr[100];

int ft_is_prime(int nb)
{
    int i;

    i = 2;
    if (nb <= 1)
        return (0);
    else
    {
        while (i * i <= nb)
        {
            if (nb % i == 0)
                return (0);
            i++;
        }
        return (1);
    }
}

int main(void)
{
    int cnt;
    int tmp;
    int ret = 0;

    cin>>cnt;
    for (int i = 0; i < cnt; i++)
    {
        cin>>tmp;
        if (ft_is_prime(tmp))
            ret++;
    }
    cout<<ret;
}   