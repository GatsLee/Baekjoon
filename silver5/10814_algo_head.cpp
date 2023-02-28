#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare_age(pair<int ,string> age, pair<int, string> name)
{
	return (age.first < name.first);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int mem, age;
	string name;
	vector<pair<int, string>> v;

	cin>>mem;
	for (int i = 0; i < mem; i++)
	{
		cin>>age>>name;
		v.push_back(make_pair(age, name));
	}
	stable_sort(v.begin(), v.end(), compare_age);

	for (int i = 0; i < mem; i++)
		cout<<v[i].first<<' '<<v[i].second<<'\n';
}
