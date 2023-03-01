#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
    int OPS_CNT, num;
    string ops;
    vector <int>v;

    cin>>OPS_CNT;
    while (OPS_CNT--)
    {
        cin>>ops;
        if (ops == "push")
        {
            cin>>num;
            v.push_back(num);
        }
        else if (ops == "pop")
        {
            cout<<v.front();
            v.pop_fron
        }
    }
}