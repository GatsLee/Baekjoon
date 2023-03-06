#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string	str;
	string	par;
	int 	OPS_CNT;

	while (1)
	{
		getline(cin, str, '.');
		if (str.empty())
			break ;
		for (int a = 0; a < str.length(); a++)
		{
			if ((str[a] == '(') || (str[a] == ')')
				|| (str[a] == '[') || (str[a] == ']'))
				par.push_back(str[a]);
		}
		OPS_CNT = par.length() / 2;
		while (OPS_CNT--)
		{
			for (int m = 0; m < par.length() - 1; m++)
			{
				if ((par[m] == '(' && par[m + 1] == ')')
					|| (par[m] == '[' && par[m + 1] == ']'))
				{
					par.erase(par.begin() + m);
					par.erase(par.begin() + m);
					break ;
				}
			}
		}
		if (par.empty())
			cout<<"yes\n";
		else
			cout<<"no\n";
		cin.ignore();
		str.clear();
		par.clear();
	}
}
