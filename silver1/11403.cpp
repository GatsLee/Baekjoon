#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int node[101][101];
int is_avail[101][101];
int is_visited[101];
int N;

void    solve(vector < vector <int> > &V) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            queue <int> Q;
            vector <int> is_visited(N+1, 0);
            bool flag = false;
            Q.push(i);
            is_visited[i] = 1;
            while (!Q.empty()) {
                int tmp = Q.front();
                Q.pop();
                if (V[tmp].size() == 0)
                    continue;
                for (int m = 0; m < V[tmp].size(); m++) {
                    if (is_visited[V[tmp][m]] <= 1) {
                        Q.push(V[tmp][m]);
                        is_visited[V[tmp][m]]++;
                        if (V[tmp][m] == j) {
                            flag = true;
                            break ; 
                        }
                    }
                }
                if (flag == true)
                    break ;
            }
            if (flag == true)
                is_avail[i][j] = 1;
            is_visited.clear();
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout<<is_avail[i][j]<<' ';
        }
        cout<<'\n';
    }


}

int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;
    vector < vector <int> > V(N+1);
    for (int i = 1; i <= N; i++) {
        vector <int> tmp;
        for (int j = 1; j <= N; j++) {
            cin>>node[i][j];
            if (node[i][j] == 1)
                tmp.push_back(j);
        }
        V[i] = tmp;
        tmp.clear();
    }
    solve(V);
}