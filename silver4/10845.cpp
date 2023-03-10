#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(void)
{
    int OPS_CNT, num;
    string ops;
    queue <int>q;

    cin>>OPS_CNT;
    while (OPS_CNT--)
    {
        cin>>ops;
        if (ops == "push")
        {
            cin>>num;
            q.push(num);
        }
        else if (ops == "pop")
        {
			if (q.empty())
				cout<<-1<<'\n';
			else
			{
				cout<<q.front()<<'\n';
				q.pop();
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
