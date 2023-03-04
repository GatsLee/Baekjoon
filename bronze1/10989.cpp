#include <iostream>
using namespace std;

int main(void)
{
    int CNT, num;
    cin>>CNT;
    int v[CNT];
    for (int i = 0; i < CNT; i++)
    {
        cin>>num;
        int j = i;
        while ( j && v[j - 1] > num)
        {
            v[j] = v[j -1];
            j--;
        }
        v[j] = num;
    }
    for (size_t j = 0; j < CNT; j++)
        cout<<v[j]<<'\n';
}