#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string str;
	int	alp[26];

	cin>>str;
	for (int i = 0; i < 26; i++)
		alp[i] = -1;
	for (int i = 0; i < str.length(); i++)
	{
		for (int a = 97; a <= 122; a++)
		{
			if (str[i] == a)
				if (alp[a - 97] == -1)
					alp[a - 97] = i;
		}
	}
	for (int i = 0; i < 25; i++)
		cout<<alp[i]<<' ';
	cout<<alp[25];
}