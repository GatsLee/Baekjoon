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
		return (a < b);
	}
}

int main(void)
{
	int cnt;
	int flag;
	string	tmp;
	vector <string>v;

	cin>>cnt;
	for (int i = 0; i < cnt;i++)
	{
		cin>>tmp;
		if (find(v.begin(), v.end(), tmp) == v.end())
			v.push_back(tmp);
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++)
		cout<<v[i]<<'\n';
}
