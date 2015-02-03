#include <queue>
#include <iostream>
#include <iterator>

using namespace std;

vector<int> levels(1000);

void bfs(vector< vector<int> > a, int v) {
    int from = 0;
    while (levels[from]!=0 && from < a.size()) from++;
    if (from == a.size()) return;

    queue<int> q;
    q.push(from);
    vector<bool> visited(a.size());
    
    vector<int> leaves;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        visited[current] = true;
        //cout << current+1 << ' ';

        int nearNodes = 0;
        for (int i = 0; i < a[current].size(); ++i) {
            int next = a[current][i];
            
            if (!visited[next]) {
                cout << current+1 << '-' << next+1 << endl;
                q.push(next);
            }
            if (levels[next]==0) {
                nearNodes++;
                cout << "near: " << current+1 << ' ' << next+1 << endl;
            }
        }
        
        if (nearNodes < 2 && levels[current] == 0) {
            leaves.push_back(current);
        }
    }
    
    cout << "graph's leaves one level " << v << ": ";
    for (int i = 0; i < leaves.size(); ++i) {
        int current = leaves[i];
        
        levels[current] = v;
        cout << current+1 << ' ';
    }
    cout << endl;
    
    bfs(a, ++v);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector< vector<int> > a(n);
    
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
    bfs(a, 1);
    
    cout << "levels: " << endl;    
    for (int i = 0; i < a.size(); ++i) {
        cout << i+1 << ' ' << levels[i] << endl;
    }    
    cout << endl;

    return 0;
}
