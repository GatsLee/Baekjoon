#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;



int main(void) {
	string eq;
	int total = 0;
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector <int> NUM;
	vector <char> CAL;
	cin>>eq;
	int i = 0;
	while (i < eq.length()) {
		int num = 0;
		while (eq[i] >= '0' && eq[i] <= '9')
			num = num * 10 + (eq[i++] - '0');
		if (eq[i] == '+' || eq[i] == '-')
			CAL.push_back(eq[i++]);
		NUM.push_back(num);
	}
	i = 0;
	if (CAL.size() == 0) {
		cout<<NUM.front();
		return (0);
	}
	while (i < CAL.size()) {
		if (CAL[i] == '+') {
			total += NUM[i];
			//if it ends
			if (i == CAL.size() - 1)
				total += NUM[++i];
			i++;
		}
		else {
			total += NUM[i];
			i++;
			total -= NUM[i];
			while (CAL[i] == '+') {
				total -= NUM[i+1];
				i++;
			}
		}
	}
	cout<<total;
}