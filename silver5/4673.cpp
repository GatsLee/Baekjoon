#include <iostream>
#include <vector>
using namespace std;

int arr[10001];

int	sum_of_digit(int num) {
	int total = num;

	while (num) {
		total += num % 10;
		num /= 10;
	}
	return (total);
}


int main(void) {
	int tmp, stand;

	for (int i = 1; i <= 10000; i++) {
		tmp = sum_of_digit(i);
		while (arr[tmp] == 0 && tmp <= 10000) {
			arr[tmp] = 1;
			tmp = sum_of_digit(tmp);
		}
	}
	for (int j = 1; j <= 10000; j++)
		if (arr[j] == 0)
			cout<<j<<'\n';
}
