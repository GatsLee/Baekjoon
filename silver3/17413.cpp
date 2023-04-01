#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main(void) {
    string str;
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    getline(cin, str);
    int i = 0;
    while (i < str.length()) {
    if (str[i] == ' ') {
        cout<<' ';
        i++;
    }
    else if (str[i] == '<') {
        while (str[i] != '>') {
            cout<<str[i];
            i++;
        }
        cout<<'>';
        i++;
    }
    else {
        stack <char> V;
        while ((str[i] >= 'a' && str[i] <= 'z')
                || (str[i] >= '0' && str[i] <= '9')) {
            V.push(str[i]);
            i++;
        }
        while (!V.empty()) {
            cout<<V.top();
            V.pop();
        }
    }
    }
}