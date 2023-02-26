#include <iostream>
#include <algorithm>
using namespace std;

int		N,M;
int		arr[100000];

bool	check_arr(int tmp)
{
	int start = 0;
	int	end = N - 1;
	int mid;

	while (start <= end)
	{
		mid = (start + end) / 2;
		if (arr[mid] == tmp)
			return (true);
		else if (arr[mid] > tmp)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return (false);
}

int main(void)
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	int		tmp;
	bool	flag;

	cin>>N;
	for (int i = 0; i < N; i++)
	{
		cin>>arr[i];
	}

	sort(arr, arr + N);
	cin>>M;
	for (int j = 0; j < M; j++)
	{
		cin>>tmp;
		flag = check_arr(tmp);
		cout<<(int)flag<<'\n';
	}
}