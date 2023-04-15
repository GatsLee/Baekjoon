#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, L;

struct Min_cast {
	int num;
	Min_cast(int i) : num(i) {}

	bool operator<(const Min_cast obj) const {
		return this->num > obj.num;
	}
};

int main(void) {
    int num;
    deque <int> DQ;
    priority_queue <Min_cast> PQ;
    vector <int> V(N);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>L;
    for (int i = 0; i < N; i++) {
        cin>>num;
        DQ.push_back(num);
    }
    for (int i = 0; i < N; i++) {
        int tmp = DQ.front();
        PQ.push(tmp);
        if (i < L) {
            
        }
    }

}