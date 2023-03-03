#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int main(void)
{
	int     N, M, num, mode_int, max_freq = 0;
    double   total;
	cin>>N;
	vector<int> list(N);
    vector<int> mode;
	unordered_map<int, int> freq;

	for (int i = 0; i < N; i++)
	{
		cin>>num;
        total += (double)num;
		list[i] = num;
		freq[num]++;
	}
    sort(list.begin(), list.end());
    cout<<lround(total/N)<<'\n';
    cout<<list[N/2]<<'\n';
    for(int j = 0; j < N; j++)
    {
        if (freq[list[j]] == max_freq)
            mode.push_back(list[j]);
        if (freq[list[j]] > max_freq)
        {
            mode.clear();
            max_freq = freq[list[j]];
            mode_int = list[j];
            mode.push_back(list[j]);
        }
    }
    if(mode.size() == 1)
        cout<<mode_int<<'\n';
    else
    {
        sort(mode.begin(), mode.end());
        cout<<mode[1]<<'\n';
    }
    cout<<list.back() - list.front()<<'\n';

}