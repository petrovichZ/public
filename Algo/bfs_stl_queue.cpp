#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

vector < vector<int> > g(100, vector<int>(100)); // граф
int n; // число вершин
int s; // стартовая вершина (вершины везде нумеруются с нуля)

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    vector<bool> used(n);
    used[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for (size_t i = 0; i < n; ++i) {
            int to = g[v][i];
            
            if(to < 0) continue;
            
            if (!used[to]) {
                used[to] = true;
                q.push (to);
            }
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    
    cin >> n >> s;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> g[i][j];            
        }
    }
    
    bfs(s);

    return 0;
}

/* -- input.txt
5 1

2 -1 -1 -1 -1
2 3 -1 -1 -1
0 1 4 -1 -1
1 4 -1 -1 -1
3 -1 -1 -1 -1
*/
