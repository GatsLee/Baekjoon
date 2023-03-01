#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(void)
{
    int CNT;
    char front, back;
    string str;
    deque <char>ps;

    cin>>CNT;
    while (CNT--)
    {
        cin>>str;
        for (int i = 0; i < str.length(); i++)
            ps.push_back(str[i]);
        while (ps.empty() != true)
        {
            front = ps.front();
            back = ps.back();
            if (!(front == '(' && back == ')')
                && !(front == ')' && back == '('))
                break ;
            ps.pop_front();
            ps.pop_back();
        }
        if (ps.empty())
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

}