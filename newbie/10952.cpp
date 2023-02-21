#include <iostream>
using namespace std;

int main(void)
{
    int cnt;
    int total = 0;
    char num;

    cin>>cnt;
    while (cnt--)
    {
       cin>>num;
       total += (num - '0');
    }
    cout<<total;
}