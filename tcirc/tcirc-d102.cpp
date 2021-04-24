#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e4 + 5;

int n;
vector<int> G[MAXN];  // neighbors

int totalWeight = 0;
vector<int> ans;

void init() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        totalWeight += w;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

void dfs(int u, int par) {
    sort(G[u].begin(), G[u].end());

    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (v == par) continue;
        ans.push_back(v);
        dfs(v, u);
        ans.push_back(u);
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    init();
    ans.push_back(0);
    dfs(0, -1);

    cout << totalWeight * 2 << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << (i + 1 == ans.size() ? '\n' : ' ');
    }

    return 0;
}
