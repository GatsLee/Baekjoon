#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

string str, bomb;
deque <char> DQ;
stack <char> S;

int main(void) {

	cin>>str>>bomb;
	for (int j = 0; j < bomb.length(); j++)
		S.push(bomb[j]);
	for (int i = 0; i < str.length(); i++) {
		DQ.push_back(str[i]);
		stack <char> tmp = S;
		deque <char>::iterator it = DQ.end() - 1;
		int checker = 0;
		while (!tmp.empty() && it >= DQ.begin()
				&& *it == tmp.top()){
			it--;
			checker++;
			tmp.pop();
		}
		if (tmp.empty())
			while (checker--)
				DQ.pop_back();
	}
	if (DQ.empty())
		cout<<"FRULA\n";
	else {
		while (!DQ.empty()) {
			cout<<DQ.front();
			DQ.pop_front();
		}
	}
}
