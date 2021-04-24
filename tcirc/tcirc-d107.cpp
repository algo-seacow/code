#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int n;
int root = 0;
vector<int> G[MAXN];
int dp[MAXN][2];
// dp[u][0] : not choose u
// dp[u][1] : choose u or not choose u

void init() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        G[p].push_back(i);
    }
}

void dfs(int u, int par) {
    dp[u][0] = 0;
    dp[u][1] = 1;
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if (v == par) continue;
        dfs(v, u);
        dp[u][0] += dp[v][1];
        dp[u][1] += dp[v][0];
    }
    dp[u][1] = max(dp[u][1], dp[u][0]);
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    init();
    dfs(root, -1);
    cout << dp[root][1] << '\n';

    return 0;
}
