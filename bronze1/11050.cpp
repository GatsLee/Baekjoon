#include <iostream>
using namespace std;

int factorial(int n)
{
	int total = 1;

	for (int i = 1; i <= n; i++)
		total *= i;
	return (total);
}


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K;

	cin>>N>>K;
	cout<< factorial(N) / (factorial(K) * factorial(N-K));
}
