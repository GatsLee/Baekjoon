#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	int	T, num1, num2, total;

	cin>>T;
	while (T--)
	{
		cin>>num1>>num2;
		total = 1;
		while (num2--)
		{
			total *= num1;
			total %= 10;
		}
		if (total % 10 == 0)
			cout<<10<<'\n';
		else
			cout<<total % 10<<'\n';
	}
}
