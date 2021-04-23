#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n, m;
vector<int> G[MAXN];
int depth[MAXN];

void init() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

void bfs(int source) {
    queue<int> que;
    depth[source] = 1;
    que.push(source);
    while (que.size() > 0) {
        int u = que.front();
        que.pop();
        for (int i = 0; i < (int)G[u].size(); i++) {
            int v = G[u][i];
            if (depth[v] == 0) {
                depth[v] = depth[u] + 1;
                que.push(v);
            }
        }
    }
}

void print(int u) {
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if (depth[v] == depth[u] - 1) {
            print(v);
            break;
        }
    }
    cout << u << ' ';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();
    bfs(1);
    if (depth[n] == 0) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    } else {
        cout << depth[n] << '\n';
        print(n);
        cout << '\n';
    }
    return 0;
}
