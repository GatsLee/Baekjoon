#include <iostream>
using namespace std;

int main(void)
{
    int cnt, num;
    int tmp;

    cin>>cnt>>num;
    for (int i = 0; i < cnt; i++)
    {
        cin>>tmp;
        if (tmp < num)
            cout<<tmp<<' ';
    }
}