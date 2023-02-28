#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const string a, const string b)
{
	if (a.length() != b.length())
		return (a.length() < b.length());
	else
	{
		if (a.compare(b) < 0)
			return (true);
		else
			return (false);
	}
}

int main(void)
{
	int cnt;
	int flag;
	string	tmp;
	vector <string>v;

	cin>>cnt;
	cin>>tmp;
	v.push_back(tmp);
	for (int i = 1; i < cnt;i++)
	{
		cin>>tmp;
		flag = 0;
		for (int j = 0; j < i; j++)
		{
			if (tmp.compare(v[j]) == 0)
				flag = 1;
		}
		if (flag == 0)
			v.push_back(tmp);
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++)
	{
		cout<<v[i]<<'\n';
	}
}
