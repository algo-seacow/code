#include <bits/stdc++.h>
using namespace std;

using Edge = pair<long long, int>;  // <dis, to>
#define dis first
#define to second

vector<long long> Dijkstra(const vector<vector<Edge>> &G, int source) {
    const long long INF = 1e18;
    int n = G.size();
    vector<long long> ans(n, INF);
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    pq.push({0, source});
    while (pq.size()) {
        long long dis = pq.top().dis;
        long long u = pq.top().to;
        pq.pop();
        if (ans[u] != INF) continue;
        ans[u] = dis;
        for (Edge e : G[u]) {
            pq.push({dis + e.dis, e.to});
        }
    }

    return ans;
}

const int MAXN = 1e5 + 5;

int n, m;
vector<vector<Edge>> G, iG;

void init() {
    cin >> n >> m;
    G = iG = vector<vector<Edge>>(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        G[u].push_back({w, v});
        iG[v].push_back({w, u});
    }
}

void solve() {
    vector<long long> pre = Dijkstra(G, 0);
    vector<long long> suf = Dijkstra(iG, n - 1);
    long long ans = 1e18;
    for (int u = 0; u < n; u++) {
        for (Edge e : G[u]) {
            long long w = e.dis;
            int v = e.to;
            ans = min(ans, pre[u] + w / 2 + suf[v]);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();
    solve();

    return 0;
}
