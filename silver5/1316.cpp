#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;

int main(void) {
	string str;
	int cnt = 0;
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>N;
	while (N--) {
		cin>>str;
		int		i = 0;
		bool	flag = true;
		while (i < str.length()) {
			int checker = i;
			for (int j = i + 1; j < str.length(); j++) {
				if (str[checker] == str[j]) {
					if (checker + 1 != j) {
						flag = false;
						break ;
					}
					checker = j;
				}
			}
			if (flag == true)
				i++;
			else
				break ;
		}
		if (flag == true)
			cnt++;
	}
	cout<<cnt;
}