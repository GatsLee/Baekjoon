#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
	string tmp;
	vector <string> vec;
	int rev_idx, flag = 1;

	while (1)
	{
		cin>>tmp;
		if (tmp == "0")
			break ;
		vec.push_back(tmp);
	}
	for(int i = 0; i < vec.size(); i++)
	{
		flag = 1;
		rev_idx = vec[i].length() - 1;
		for (int j = 0; j< (vec[i].length() / 2); j++)
		{
			if (vec[i][j] != vec[i][rev_idx])
				flag = 0;
			rev_idx--;
		}
		if (flag == 1)
			cout<<"yes\n";
		else
			cout<<"no\n";
	}
}