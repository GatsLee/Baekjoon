#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int CNT, num;
    int loc = 0;

    cin>>CNT;
    for(num =666;;num++)
    {
        string str = to_string(num);
        for (int i = 0; i < str.length() - 2; i++)
        {
            if ((str[i] == '6') && (str[i+1] == '6') && (str[i+2] == '6'))
            {
                loc++;
                break ;
            }
        }
        if (loc == CNT)
        {
            cout<<num;
            return (0);
        }
    }
}