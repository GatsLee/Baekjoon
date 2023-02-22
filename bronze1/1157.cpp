#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int     cnt[26];
	string  str;
	int     biggest = 0;
	int     dup = 0;

	for(size_t i = 0; i < 26; i++)
	   cnt[i] = 0;
	cin>>str;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			cnt[(int)str[i] - 'a']++;
		if (str[i] >= 'A' && str[i] <= 'Z')
			cnt[(int)str[i] - 'A']++;
	}
	for(size_t i = 0; i < 26; i++)
	{
		if (cnt[i] > biggest)
			biggest = cnt[i];
	}

	for(size_t i = 0; i < 26; i++)
	{
		if (cnt[i] == biggest)
			dup++;
	}
	if (dup == 1)
	{
		for(size_t i = 0; i < 26; i++)
		{
			if (cnt[i] == biggest)
				cout<<(char)(i + 'A');
		}
	}
	else
		cout<<'?';
}