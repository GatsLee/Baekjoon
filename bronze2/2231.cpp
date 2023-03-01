#include <iostream>
using namespace std;

int main(void)
{
    int num, total, j;

    cin>>num;
    for (int i = 1; i < num;i++)
    {
        total = i;
        j = i;
        while (j)
        {
            total += (j % 10);
            j = j / 10;
        }
        if (total == num)
        {
            cout<<i;
            return (0);
        }
    }
    cout<<0;
    return (0);
}