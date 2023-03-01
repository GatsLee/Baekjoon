#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
    int tri[3];
    bool ang;
    while (1)
    {
        cin>>tri[0]>>tri[1]>>tri[2];
        if ((tri[0]==0) && (tri[1]==0) && (tri[2]==0))
            return (0);
        sort(tri, tri + 3);
        ang = (pow(tri[2], 2) == pow(tri[0], 2) + pow(tri[1], 2));
        if (ang == true)
            cout<<"right\n";
        else
            cout<<"wrong\n";
    }
}