#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
    string str;
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    vector <int> set(2, 0);
    cin>>str;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'U' || str[i] == 'C')
            set[0]++;
        else
            set[1]++;
    }
    if (set[1] == 0)
        cout<<"U";
    else if ((set[0] * 2 <= set[1] + 1) || (set[0] * 2 == set[1] - 1) || set[1] == 1)
        cout<<"DP";
    else
        cout<<"UDP";
    }