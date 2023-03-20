#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int T;

int main(void) {

	int cnt, num;
	char CMD;

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>T;
	while (T--) {
		cin>>cnt;
		multiset <int> SET;
		while (cnt--) {
			cin >> CMD >> num;
			if (CMD == 'I')
				SET.insert(num);
			else {
				if (SET.size() != 0) {
					if (num == 1) {
						auto iter = SET.end();
						iter--;
						SET.erase(iter);
					}
					else
						SET.erase(SET.begin());
				}
			}
		}
		if (SET.size() == 0)
			cout<<"EMPTY\n";
		else {
			auto iter = SET.end();
			iter--;
			cout<<*(iter)<<' '<<*(SET.begin())<<'\n';
		}
	}
	return (0);
}