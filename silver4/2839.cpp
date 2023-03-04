#include <iostream>
using namespace std;


int main(void)
{
	int T, THR, FIV;
	int	div = 1667;
	cin>>T;
	for (FIV = T / 5; FIV >= 0; FIV--)
	{

		for (THR = 0; THR * 3 + FIV * 5 <= T; THR++)
		{
			if (THR * 3 + FIV * 5 == T && (THR + FIV) < div)
				div = THR + FIV;
		}
	}
	if (div == 1001)
		cout<<-1;
	else
		cout<<div;
}