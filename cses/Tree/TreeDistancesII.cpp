#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int n;
int root = 0;
vector<int> G[MAXN];

long long sz_sub[MAXN], dp_sub[MAXN];
long long sz_par[MAXN], dp_par[MAXN];

void init() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

void dfs(int u, int par) {
    sz_sub[u] = 1;
    dp_sub[u] = 0;
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if (v == par) continue;
        dfs(v, u);
        sz_sub[u] += sz_sub[v];
        dp_sub[u] += dp_sub[v] + sz_sub[v];
    }
}

void push(int u, int par) {
    long long total = dp_par[u] + sz_par[u];

    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if (v == par) continue;
        total += dp_sub[v] + 2 * sz_sub[v];
    }

    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if (v == par) continue;
        sz_par[v] = n - sz_sub[v] + 1;
        dp_par[v] = total - dp_sub[v] - 2 * sz_sub[v];
        push(v, u);
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    init();
    dfs(root, -1);
    sz_par[root] = 1;
    dp_par[root] = 0;
    push(root, -1);

    for (int i = 0; i < n; i++) {
        long long ansi = dp_sub[i] + dp_par[i];
        cout << ansi << (i == n - 1 ? "\n" : " ");
    }

    return 0;
}
