#include <iostream>
#include <string>
using namespace std;

void pop(int *arr)
{
	int idx = 0;

	if (arr[0] == 0)
	{
		cout<<-1<<'\n';
		return ;
	}
	for (int i = 0; arr[i] != 0; i++)
		idx++;
	cout << arr[idx - 1] << endl;
	arr[idx - 1] = 0;
	return ;
}

void push(int *arr, int data)
{
	int idx = 0;

	if (arr[0] == 0)
	{
		arr[0] = data;
		return ;
	}
	for (int i = 0; arr[i] != 0; i++)
		idx++;
	arr[idx] = data;
	return ;
}

void size(int *arr)
{
	int size = 0;

	for (int i = 0; arr[i] != 0; i++)
		size++;
	cout<<size<< endl;
	return ;
}

void empty(int *arr)
{
	if (arr[0] == 0)
		cout<<1<< endl;
	else
		cout<<0<< endl;
}

void top(int *arr)
{
	int idx = 0;

	if (arr[0] == 0)
		cout<<-1;
	else
	{
		for (int i = 0; arr[i] != 0; i++)
			idx++;
		cout<<arr[idx - 1]<< endl;
	}
}

void	ops_init(string ops, int *arr)
{
	int num;

	if (ops == "pop")
		pop(arr);
	else if (ops == "push")
	{
		cin>>num;
		push(arr, num);
	}
	else if (ops == "size")
		size(arr);
	else if (ops == "empty")
		empty(arr);
	else if (ops == "top")
		 top(arr);
	else
		return ;
}

int main(void)
{
	int ops_cnt;
	string str;
	int arr[10000];

	cin>>ops_cnt;
	for (int i = 0; i < 10000; i++)
		arr[i] = 0;
	while (ops_cnt--)
	{
		cin>>str;
		ops_init(str, arr);
	}
}