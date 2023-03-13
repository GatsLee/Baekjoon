#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
using namespace std;

deque <int> DQ;
int min_cnt = 0;

void second_mv(int mv_left)
{
    while (mv_left--)
    {
        int tmp = DQ.front();
        DQ.pop_front();
        DQ.push_back(tmp);
    }
}

void third_mv(int mv_right)
{
    while (mv_right--)
    {
        int tmp = DQ.back();
        DQ.pop_back();
        DQ.push_front(tmp);
    }
}

int idx_cnt(int target)
{
    int idx = 0;

    for (int i = 0; i < DQ.size(); i++)
    {
        if (target == DQ[i])
            return (i);
    }
    return (0);
}

int find_min(vector <int> &v)
{
    int cnt = idx_cnt(v.front());
    if (cnt >= (DQ.size() + 1) / 2)
        cnt = (DQ.size() - cnt) * -1 ;
    v.erase(v.begin());
    if (cnt >= 0)
        second_mv(cnt);
    else
        third_mv(abs(cnt));
    return (abs(cnt));
}

int main(void)
{
    int N, M;

    cin>>N>>M;
    vector <int> v(M);
    for (int i  = 0; i < M; i++)
        cin>>v[i];
    for (int j = 1; j <= N; j++)
        DQ.push_back(j);
    while (v.size() != 0)
    {
        int tmp = find_min(v);
        DQ.pop_front();
        min_cnt += tmp;
    }
    cout<<min_cnt;
}