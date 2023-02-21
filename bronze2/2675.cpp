#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
    int cnt;
    int time = 0;
    int idx = 0;
    char arr[21];

    bzero(arr, 21);
    cin>>cnt;
    while (cnt)
    {
        cin>>time;
        cin>>arr;
        idx = 0;
        while (arr[idx])
        {
            for(int i = 0; i < time; i++)
                cout<<arr[idx];
            idx++;
        }
        cout<<'\n';
        cnt--;
    }
}