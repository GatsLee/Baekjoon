#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int T;
int from, to;

int double_num(int num, vector <int> &visited) {
    int tmp;

    if (num * 2 >= 10000)
        tmp = (num * 2) % 10000;
    else
        tmp  = num * 2;
    if (visited[tmp] != 0)
        return (-1);
    else
        return (tmp);
}

int subtract_num(int num, vector <int> &visited) {
    int tmp;

    if (num == 0)
        tmp = 9999;
    else
        tmp = num - 1;
    if (visited[tmp] != 0)
        return (-1);
    else
        return (tmp);
}

int left_cmd(int num, vector <int> &visited) {
    int tmp;
    int th_digit;
    int rest;

    th_digit = num / 1000;
    rest = num - th_digit * 1000;
    tmp = rest * 10 + th_digit;
    if (visited[tmp] != 0)
        return (-1);
    else
        return (tmp);
}

int right_cmd(int num, vector <int> &visited) {
    int tmp;
    int one_digit;
    int rest;

    one_digit = num % 10;
    rest = num - one_digit;
    tmp = rest / 10 + one_digit * 1000;
    if (visited[tmp] != 0)
        return (-1);
    else
        return (tmp);
}

string    solve(void) {
    string ret;
    vector < int > visited(10000, 0);
    queue < pair <int, string> > Q;
    Q.push(make_pair(from, ""));
    while (!Q.empty()) {
        int front = Q.front().first;
        string tmp = Q.front().second;
        Q.pop();
        if (front == to) {
            ret = tmp;
            break ;
        }
        if (double_num(front, visited) != -1) {
            Q.push(make_pair(double_num(front, visited), tmp + "D"));
            visited[double_num(front, visited)] = 1;
        }
        if (subtract_num(front, visited) != -1) {
            Q.push(make_pair(subtract_num(front, visited), tmp + "S"));
            visited[subtract_num(front, visited)] = 1;
        }
        if (left_cmd(front, visited) != -1) {
            Q.push(make_pair(left_cmd(front, visited), tmp + "L"));
            visited[left_cmd(front, visited)] = 1;
        }
        if (right_cmd(front, visited) != -1) {
            Q.push(make_pair(right_cmd(front, visited), tmp + "R"));
            visited[right_cmd(front, visited)] = 1;
        }
    }
    return (ret);
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>T;
    vector <string> ans(T);
    for (int i = 0; i < T; i++) {
        cin>>from>>to;
        ans[i] = solve();
    }
    for (int i = 0; i < T; i++)
        cout<<ans[i]<<'\n';
}