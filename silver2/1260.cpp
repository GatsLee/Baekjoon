#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, V;

void    DFS(int cur, vector < vector <int> >&DFS_line, vector <int>&DFS_v, stack <int>&DFS_s)
{
    int num1, num2;
    int idx;

    idx = cur - 1;
    if (DFS_v[idx] != 0)
        return ;
    else
    {
        DFS_v[idx] = 1;
        cout<<cur<<' ';
    }
    if (DFS_line[idx].size() != 0)
    {
        for (int i = 0; i < DFS_line[idx].size(); i++)
            DFS(DFS_line[idx][i], DFS_line, DFS_v, DFS_s);
    }
    else
        return ;
}

void    BFS(int cur, vector < vector <int> >&BFS_line, vector <int>&DFS_v, queue <int>&BFS_q)
{
    int idx = cur - 1;
    BFS_q.push(cur);
    while (BFS_q.size() != 0)
    {
        idx = BFS_q.front() - 1;
        if (DFS_v[idx] == 0)
        {
            cout<<BFS_q.front()<<" ";
            DFS_v[idx] = 1;
            for (int j = 0; j < BFS_line[idx].size(); j++)
                BFS_q.push(BFS_line[idx][j]);
        }
        BFS_q.pop();
    }

}


int main(void)
{
    int num1, num2;

    cin>>N>>M>>V;
    vector < vector<int> > line(N);
    vector <int> DFS_v(N, 0);
    vector <int> BFS_v(N, 0);
    stack <int> DFS_s;
    queue <int> BFS_q;
    for (int i = 0; i < M; i++)
    {
        cin>>num1;
        cin>>num2;
        line[num1 - 1].push_back(num2);
        line[num2 - 1].push_back(num1);
        sort(line[num1 - 1].begin(), line[num1 -1].end());
        sort(line[num2 - 1].begin(), line[num2 -1].end());
    }
    DFS(V, line, DFS_v, DFS_s);
    cout<<"\n";
    BFS(V, line, BFS_v, BFS_q);
}