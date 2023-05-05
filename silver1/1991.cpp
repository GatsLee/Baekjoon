#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
char lc[26] = {'.', };
char rc[26] = {'.', };

void	preorder(char root) {
	cout << root;
	if (lc[root - 'A'] != '.') preorder(lc[root- 'A']);
	if (rc[root - 'A'] != '.') preorder(rc[root- 'A']);
}

void	inorder(char root) {
	if (lc[root - 'A'] != '.') inorder(lc[root- 'A']);
	cout << root;
	if (rc[root - 'A'] != '.') inorder(rc[root- 'A']);
}

void	postorder(char root) {
	if (lc[root - 'A'] != '.') postorder(lc[root- 'A']);
	if (rc[root - 'A'] != '.') postorder(rc[root- 'A']);
	cout << root;
}

int main(void) {

	cin>>N;
	for (int i = 0; i < N; i++) {
		char P, L, R;
		cin>>P>>L>>R;
		lc[P - 'A'] = L;
		rc[P - 'A'] = R;
	}
	preorder('A');
	cout<<'\n';
	inorder('A');
	cout<<'\n';
	postorder('A');
}
