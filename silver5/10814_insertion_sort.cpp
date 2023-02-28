//time overload
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int mem, key, i , j;
	string key_name;

	cin>>mem;
	vector <int>age(mem);
	vector <string>name(mem);
	for (i = 0; i < mem; i++)
		cin>>age[i]>>name[i];
	for (i = 1; i < mem; i++)
	{
		key = age[i];
		key_name = name[i];
		for(j = i - 1; (j >= 0) && (age[j]>key); j--)
		{
			age[j+1] = age[j];
			name[j+1] = name[j];
		}
		age[j+1] = key;
		name[j+1] = key_name;
	}
	for (i = 0; i < mem; i++)
		cout<<age[i]<<' '<<name[i]<<'\n';
}
