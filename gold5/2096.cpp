#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int pre_max[3];
int cur_max[3];
int pre_min[3];
int cur_min[3];

void push_max(int n1, int n2, int n3) {
pre_max[0] = n1, pre_max[1] = n2, pre_max[2] = n3;
}

void push_min(int n1, int n2, int n3) {
pre_min[0] = n1, pre_min[1] = n2, pre_min[2] = n3;   
}


int main(void) {
	int num1, num2, num3;
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>N;
	cin>>num1>>num2>>num3;
	push_max(num1, num2, num3);
	push_min(num1, num2, num3);
	for (int i = 0 ; i < N-1; i++) {
		cin>>num1>>num2>>num3;
		cur_max[0] = num1 + max(pre_max[0], pre_max[1]);
		cur_max[1] = num2 + max(max(pre_max[0], pre_max[1]), pre_max[2]);
		cur_max[2] = num3 + max(pre_max[1], pre_max[2]);

		cur_min[0] = num1 + min(pre_min[0], pre_min[1]);
		cur_min[1] = num2 + min(min(pre_min[0], pre_min[1]), pre_min[2]);
		cur_min[2] = num3 + min(pre_min[1], pre_min[2]);
		push_max(cur_max[0], cur_max[1], cur_max[2]);
		push_min(cur_min[0], cur_min[1], cur_min[2]);       
	}
	cout<<max(max(pre_max[0], pre_max[1]), pre_max[2]);
	cout<<' '<<min(min(pre_min[0], pre_min[1]), pre_min[2]);

}