#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int n;
int root = 0;
vector<int> G[MAXN];
int h[MAXN];
int dp[MAXN];  // dp[u] : longest path in the subtree u that passing through u

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
    h[u] = 0;
    int a = 0, b = 0;  // heightest child, second heightest child
    for (int v : G[u]) {
        if (v != par) {
            dfs(v, u);
            if (h[v] + 1 >= a) {
                b = a;
                a = h[v] + 1;
            } else if (h[v] + 1 >= b) {
                b = h[v] + 1;
            }
        }
    }
    h[u] = a;
    dp[u] = a + b;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    init();
    dfs(root, -1);
    int ans = *max_element(dp, dp + n);
    cout << ans << '\n';
    return 0;
}
