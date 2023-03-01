#include <iostream>
using namespace std;

int main(void)
{
	int CNT;
	int H, W, N;
	int Room_num;

	cin>>CNT;
	while (CNT--)
	{
		Room_num = 0;
		cin>>H>>W>>N;
		if (N % H == 0)
			Room_num += H * 100 + (N / H);
		else
			Room_num += (N % H) * 100 + ((N / H) + 1);
		cout<<Room_num<<'\n';
	}
}