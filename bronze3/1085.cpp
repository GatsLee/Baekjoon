#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int X, Y, W, H;

	cin>>X>>Y>>W>>H;
	int arr[4] = {X, Y, W - X, H - Y};
	sort(arr, arr+4);
	cout<<arr[0];
}
