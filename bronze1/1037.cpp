#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int cnt;
	size_t  idx = 0;
	int	*div;
    int lowest, highest;
	
	cin>>cnt;
    div = new int[cnt];
	while (idx < cnt)
		cin>>div[idx++];
    idx = 0;
    sort(div, div+cnt);
    cout <<div[0] * div[cnt - 1];
    delete []div;
}
