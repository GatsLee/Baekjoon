#include <iostream>
using namespace std;

int main(void)
{
    int cnt;
    int highest = 0;
    int *score;
    double  avr = 0;

    cin>>cnt;
    score = new int[cnt];
    for (int i = 0; i < cnt; i++)
    {
        cin>>score[i];
        if (highest == 0 || highest < score[i])
            highest = score[i];
    }
    for (int j = 0; j < cnt; j++)
        avr += score[j];
    avr = avr / highest * 100 / cnt;
    cout <<avr;
}