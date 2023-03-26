#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int T, N;

int main(void) {
	int n, start, end, mid;
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>T>>N;
	vector <int> whole_num;
	vector <int> num_set(N);
	for (int i = 0; i < N; i++)
		cin>>num_set[i];
	sort(num_set.begin(), num_set.end());
	for (int j = 0; j <= 999999; j++) {
		bool flag = false;
		string tmp = to_string(j);
		for (int m = 0; m < num_set.size(); m++) {
			if (tmp.find(num_set[m] + '0') != string::npos) {
				flag = true;
				break ;
			}
		}
		if (flag == false)
			whole_num.push_back(j);
	}
	if (whole_num.size() == 0) {
		cout<< abs(T- 100);
		return (0);
	}
	int min_n = 1000006;
	for (int i = 0; i < whole_num.size(); i++) {
		if (min_n >= to_string(whole_num[i]).size() + abs(whole_num[i] - T))
			min_n = to_string(whole_num[i]).size() + abs(whole_num[i] - T);
	}
	if (abs(T-100) >= min_n)
		cout << min_n;
	else
		cout << abs(T-100);
}