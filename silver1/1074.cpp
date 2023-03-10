#include <iostream>
using namespace std;

int	calculate_y(int y, int N)
{
	if (y == 0)
		return (0);
	if (y == 1)
		return (2);
	else
	{
		if (y % 2 == 1)
			return (calculate_y(y/2, N) * 4 + 2);
		else
			return (4 * calculate_y(y/2, N));
	}

}

int	calculate_x(int x, int N)
{
	if (x == 0)
		return (0);
	if (x == 1)
		return (1);
	else
	{
		if (x % 2 == 1)
			return ((calculate_x(x/2, N) * 4 + 1));
		else
			return (4  * calculate_x(x/2, N));
	}
}

int main(void)
{
	int	N, r, c;

	cin>>N>>r>>c;
	cout<< calculate_y(r, N) + calculate_x(c, N);
}
