#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n;
int root = 0;
vector<int> G[MAXN];
int color[MAXN];

int ans[MAXN];
set<int> S[MAXN];

void init() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> color[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

void merge(set<int> &a, set<int> &b) {
    if (a.size() < b.size()) swap(a, b);
    for (int x : b) a.insert(x);
    b.clear();
}

void dfs(int u, int par) {
    S[u].insert(color[u]);
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if (v == par) continue;
        dfs(v, u);
        merge(S[u], S[v]);
    }
    ans[u] = S[u].size();
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    init();
    dfs(root, -1);
    for (int i = 0; i < n; i++) {
        cout << ans[i] << (i == n - 1 ? "\n" : " ");
    }

    return 0;
}
