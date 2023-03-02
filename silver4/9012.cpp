#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	int 	STR_CNT;
	size_t 	OPS_CNT;
	string	str;
	vector	<char>ps(50);

	cin>>STR_CNT;
	while (STR_CNT--)
	{
		cin>>str;
		vector <char>ps(str.length());
		for (int i = 0; i < str.length(); i++)
			ps[i] = str[i];
		OPS_CNT = str.length() / 2;
		while (OPS_CNT--)
		{
			for (int i = 0; i < ps.size() - 1; i++)
			{
				if (ps[i] == '(' && ps[i+1] == ')')
				{
					ps.erase(ps.begin() + i);
					ps.erase(ps.begin() + i);
					break ;
				}

			}
		}
		if (ps.empty())
			cout<<"YES\n";
		else
			cout<<"NO\n";
		ps.clear();
	}
}
