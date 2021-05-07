#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n, m;
vector<int> G[MAXN];
int din[MAXN];
int dp[MAXN];  // dp[i]: longest path ending at i
int from[MAXN];

void init() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;  // to 0-base
        G[u].push_back(v);
    }
}

vector<int> topo_sort() {
    // build in degree array
    fill(din, din + n, 0);
    for (int u = 0; u < n; u++) {
        for (int v : G[u]) {
            din[v]++;
        }
    }

    // init queue
    queue<int> que;
    for (int i = 0; i < n; i++) {
        if (din[i] == 0) {
            que.push(i);
        }
    }

    // bfs
    vector<int> topo_ans;
    while (que.size()) {
        int u = que.front();
        que.pop();
        topo_ans.push_back(u);
        for (int v : G[u]) {
            din[v]--;
            if (din[v] == 0) que.push(v);
        }
    }
    return topo_ans;
}

void print(int u) {
    if (u < 0) return;
    print(from[u]);
    cout << u + 1 << ' ';
}

void solve() {
    vector<int> topo = topo_sort();

    fill(dp, dp + n, -1);
    fill(from, from + n, -1);
    dp[0] = 1;  // source = 0

    for (int i = 0; i < n; i++) {
        int u = topo[i];
        if (dp[u] == -1) continue;
        for (int v : G[u]) {
            if (dp[v] < dp[u] + 1) {
                dp[v] = dp[u] + 1;
                from[v] = u;
            }
        }
    }
    if (dp[n - 1] == -1) {
        cout << "IMPOSSIBLE" << '\n';
    } else {
        cout << dp[n - 1] << '\n';
        print(n - 1);
        cout << '\n';
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    init();
    solve();

    return 0;
}
