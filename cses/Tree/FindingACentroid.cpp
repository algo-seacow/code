#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int n;
vector<int> G[MAXN];  // neighbors
int sz[MAXN];

int ans;

void init() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

void dfs(int u, int par) {
    int max_subtree = 0;
    sz[u] = 1;
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if (v == par) continue;
        dfs(v, u);
        sz[u] += sz[v];
        max_subtree = max(max_subtree, sz[v]);
    }
    max_subtree = max(max_subtree, n - sz[u]);
    if (max_subtree <= n/2) ans = u;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    init();
    dfs(0, -1);
    cout << ans + 1 << '\n';

    return 0;
}
