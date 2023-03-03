#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    int K, num, total = 0;
    stack <int>pile;

    cin>>K;

    for (int i = 0; i < K; i++)
    {
        cin>>num;
        if (num != 0)
            pile.push(num);
        else
            pile.pop();
    }
    while (pile.size() != 0)
    {
        total += pile.top();
        pile.pop();
    }
    cout<<total;
}