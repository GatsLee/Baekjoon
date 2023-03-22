#include <iostream>
using namespace std;

int main(void) {
	int N;
	int CYC = 1;

	cin>>N;
	int tmp = N;
	while (true) {
		int num = tmp / 10 + tmp % 10;
		if (((tmp % 10) * 10) + num  % 10 == N)
			break ;
		else {
			tmp = ((tmp % 10) * 10) + num % 10;
			CYC++;
		}
	}
	cout<<CYC;
}
