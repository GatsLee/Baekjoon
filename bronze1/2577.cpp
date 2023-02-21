#include <iostream>
using namespace std;

int main(void)
{
    int num[10];
    int total = 1;
    int val;
    int div;

    for (int i = 0;  i < 10; i++)
        num[i] = 0;
    for (int i = 0; i < 3; i++)
    {
        cin>>val;
        total *= val;
    }
    while (total)
    {
        div = total % 10;
        num[div] = num[div] + 1;
        total /= 10;
    }
    for (int j = 0; j < 10; j++)
        cout<<num[j]<<'\n';
}