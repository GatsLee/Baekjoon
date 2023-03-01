#include <iostream>
#include <string>
#include <vector>
using namespace std;

void pop(vector<int> &v)
{
	if (v.empty())
	{
		cout<<-1<<'\n';
		return ;
	}
	cout<<v.back()<<'\n';
	v.pop_back();
}

void push(vector<int> &v, int data)
{
	v.push_back(data);
	return ;
}

void size(vector<int> &v)
{
	cout<<v.size()<<'\n';
	return ;
}

void empty(vector<int> &v)
{
	cout<<v.empty()<<'\n';
	return ;
}

void top(vector<int> &v)
{
	if (v.empty())
	{
		cout<<-1<<'\n';
		return ;
	}
	cout<<v.back()<<'\n';
	return ;
}

void	ops_init(string ops, vector<int> &v)
{
	int num;

	if (ops == "pop")
		pop(v);
	else if (ops == "push")
	{
		cin>>num;
		push(v, num);
	}
	else if (ops == "size")
		size(v);
	else if (ops == "empty")
		empty(v);
	else if (ops == "top")
		 top(v);
	else
		return ;
}

int main(void)
{
   int OPS_CNT;
   string ops;
   vector <int>v;

	cin>>OPS_CNT;
	while (OPS_CNT--)
	{
		cin>>ops;
		ops_init(ops, v);
	}
}