#include <iostream>
#include <string>
#include <vector>
using namespace std;

int WID, LEN;

string WB[8] = {"WBWBWBWB",
				"BWBWBWBW",
				"WBWBWBWB",
				"BWBWBWBW",
				"WBWBWBWB",
				"BWBWBWBW",
				"WBWBWBWB",
				"BWBWBWBW"};

string BW[8] = {"BWBWBWBW",
				"WBWBWBWB",
				"BWBWBWBW",
				"WBWBWBWB",
				"BWBWBWBW",
				"WBWBWBWB",
				"BWBWBWBW",
				"WBWBWBWB"};

int compare_WB(vector <string>v, int x, int y)
{
	int total = 0;
	for (int a = 0; a < 8; a++)
	{
		for (int b = 0; b< 8; b++)
		{
			if (v[a + y][b + x] != WB[a][b])
				total++;
		}
	}
	return (total);
}

int compare_BW(vector <string>v,  int x, int y)
{
	int total = 0;
	for (int a = 0 ; a < 8 ; a++)
	{
		for (int b = 0; b < 8; b++)
		{
			if (v[a + y][b + x] != BW[a][b])
				total++;
		}
	}
	return (total);
}

int main(void)
{
	cin>>WID>>LEN;
	string line;
	vector <string>v;
	int WB, BW;
	int least = 32;

	for(int i = 0; i < WID; i++)
	{
		cin>>line;
		v.push_back(line);
	}
	for(int j = 0; j <= LEN - 8; j++)
	{
		for (int m = 0; m <= WID - 8; m++)
		{
			WB = compare_WB(v, j, m);
			BW = compare_BW(v, j, m);
			if ((least >= WB) || (least >= BW))
			{
				if (WB < BW)
					least = WB;
				else
					least = BW;
			}
		}
	}
	cout<<least;
}