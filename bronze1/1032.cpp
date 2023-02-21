#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(void)
{
    int cnt;
    size_t  idx = 0;
    char    name[51];
    char    ori[51];

    cin>>cnt;
    cin>>ori;
    cnt--;
    while (cnt--)
    {
        idx = 0;
        cin>>name;
        while (name[idx])
        {
            if (name[idx] != ori[idx])
                name[idx] = '?';
            cout<<idx;
			idx++;
        }
        strcpy(ori, name);
    }
    cout<<ori;
}