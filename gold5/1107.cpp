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
	pair<int, int> P = make_pair(0, 1000000);
	start = 0;
	end = whole_num.size() - 1;
	while (start <= end) {
		mid = (start + end) / 2;
		if (P.second >= abs(whole_num[mid] - T))
			P = make_pair(whole_num[mid], abs(whole_num[mid] - T));
		if (whole_num[mid] > T)
			end = mid - 1;
		else if (whole_num[mid] < T)
			start = mid + 1;
		else {
			P = make_pair(T, 0);
			break;
		}
	}
	if (abs(T-100) >= P.second + to_string(P.first).size())
		cout << P.second + to_string(P.first).size();
	else
		cout << abs(T-100);
}