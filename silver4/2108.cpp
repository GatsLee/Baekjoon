#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int N;

int find_frequent(int *arr)
{
	int dup, cnt = 1;
	int checker = arr[0];

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (arr[i] == arr[j])
				dup++;
		}
		if (dup >= cnt)
		{
			checker = arr[i];
			cnt = dup;
		}
	}
	return (checker);
}

int main(void)
{
	int total = 0;
	cin>>N;
	int arr[N];
	for (int i = 0; i < N; i++)
		cin>>arr[i];
	sort(arr, arr + N);
	for (int i = 0; i < N; i++)
		total += arr[i];
	cout<<(total / N)<<'\n';
	cout<<arr[N/2]<<'\n';
	cout<<find_frequent(arr)<<'\n';
	cout<<arr[N -1] - arr[0]<<'\n';
}