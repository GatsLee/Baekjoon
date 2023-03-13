#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
	int cnt = 0;
	string	line;
	string  odd = "F0F0F0F0";
	string	even = "0F0F0F0F";
	vector < string >chess;

	for (int i = 0; i < 8; i++)
	{
		cin>>line;
		chess.push_back(line);
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i % 2 == 0)
			{
				if (odd[j] == chess[i][j])
					cnt++;
			}
			else
			{
				if (even[j] == chess[i][j])
					cnt++;
			}
		}
	}
	cout<<cnt;
}
