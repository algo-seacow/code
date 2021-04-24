#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int n;
int root = 0;
vector<int> G[MAXN];
int color[MAXN];

int ans = 0;
map<int, int> cnt;

void init() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> color[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }
}

void dfs(int u, int par) {
    int &c = cnt[color[u]];
    c++;
    ans = max(ans, c);
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        dfs(v, u);
    }
    c--;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    init();
    dfs(root, -1);

    cout << ans << '\n';

    return 0;
}
