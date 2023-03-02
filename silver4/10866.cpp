#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(void)
{
    int OPS_CNT, num;
    string ops;
    deque <int>q;

    cin>>OPS_CNT;
    while (OPS_CNT--)
    {
        cin>>ops;
        if (ops == "push_front")
        {
            cin>>num;
            q.push_front(num);
        }
		else if (ops == "push_back")
		{
            cin>>num;
            q.push_back(num);
		}
        else if (ops == "pop_front")
        {
			if (q.empty())
				cout<<-1<<'\n';
			else
			{
				cout<<q.front()<<'\n';
				q.pop_front();
			}
        }
        else if (ops == "pop_back")
        {
			if (q.empty())
				cout<<-1<<'\n';
			else
			{
				cout<<q.back()<<'\n';
				q.pop_back();
			}
        }
		else if (ops == "size")
		{
			cout<<q.size()<<'\n';
		}
		else if (ops == "empty")
		{
			if (q.empty())
				cout<<1<<'\n';
			else
				cout<<0<<'\n';
		}
		else if (ops == "front")
		{
			if (q.empty())
				cout<<-1<<'\n';
			else
				cout<<q.front()<<'\n';
		}
		else if (ops == "back")
		{
			if (q.empty())
				cout<<-1<<'\n';
			else
				cout<<q.back()<<'\n';
		}
    }
}
