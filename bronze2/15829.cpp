#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int main(void)
{
	long long	    LEN, hash = 0;
	long long		r = 1;
	string  		str;

	cin>>LEN;
	cin>>str;
	for (size_t i = 0; i < str.length(); i++)
	{
		hash = (hash + (str[i] - 96) * r) % 1234567891;
		r = (r * 31) % 1234567891;
	}
	cout<<hash;
}