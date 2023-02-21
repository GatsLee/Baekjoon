#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
    int cnt;
    int idx =0;
    char    arr[81];
    int score = 1;
    int total = 0;

    bzero(arr, 81);
    cin>>cnt;
    while (cnt--)
    {
        idx = 0;
        total = 0;
        cin>>arr;
        while (arr[idx])
        {
            if (arr[idx] == 'O')
            {
                total += score;
                score++;
            }
            else
                score = 1;
            idx++;
        }
        score = 1;
        cout<<total<<'\n';
    }
}