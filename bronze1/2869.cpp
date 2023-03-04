#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    int A, B, V;
    int total = 0;
    cin>>A>>B>>V;
    cout<<(int)ceil((double) (V - B) / (A - B));
}