#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int div[10];
    int val;
    int cnt = 1;

    for (int i = 0; i < 10; i++)
    {
        cin>>val;
        div[i] = val % 42;
    }
    sort(div, div + 10);
    val = div[0];
    for (int j = 0; j < 10; j++)
    {
        if (div[j] != val)
        {
            cnt++;
            val = div[j];
        }
    }
    cout<<cnt;
}