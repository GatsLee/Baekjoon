#include <iostream>
#include <string>
using namespace std;

string color[10] = { "black", "brown", "red", "orange",
					"yellow", "green", "blue", "violet",
					"grey", "white"};

int main(void)
{
	string one, two, three;
	int	rst1, rst2, multi;

	cin>>one>>two>>three;
	for (int i = 0; i < 10; i++)
	{
		if (one == color[i])
			rst1 = i;
		if (two == color[i])
			rst2 = i;
		if (three == color[i])
			multi = i;
	}
	if (rst1 != 0)
		cout<<rst1<<rst2;
	else
	{
		if (rst2 != 0)
			cout<<rst2;
		else
		{
			cout<<0;
			return (0);
		}
	}
	while (multi--)
		cout<<0;
}
