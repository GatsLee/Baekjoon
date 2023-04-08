#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector < vector <int> > map(9, vector <int>(9));
int isused[10];


void    solve(void) {



}

int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin>>map[i][j];
    solve();
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cout<<map[i][j];
}