#include <queue>
#include <iostream>

using namespace std;

void bfs(vector<vector<int>> a, int from) {
    queue<int> q;
    q.push(from);
    bool visited[a.size()];
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        visited[current] = true;
        cout << current+1 << ' ';
        for (int i = 0; i < a[current].size(); ++i) {
            if (!visited[ a[current][i] ]) {
                q.push(a[current][i]);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n);
    
    cout << n << ' ' << m << ' ' << a.size() << endl;
    
    while(m--) {
        int i, j;
        cin >> i >> j;
        
        cout << i << ' ' << j << endl;
        
        i--; j--;
        a[i].push_back(j);
        a[j].push_back(i);
    }
    int from;
    cin >> from;
    cout << from << endl;
    from--;
    bfs(a, from);
    cout << endl;
    return 0;
}

/*
4 3
1 2
2 3
2 4
1
*/

/*
7 6
1 2
1 3
2 4
2 5
5 6
5 7
7
*/
