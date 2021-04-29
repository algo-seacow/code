#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n, m;
int cnt, mx;
int par[MAXN];
int sz[MAXN];

int find(int x) {
    if (par[x] == -1) return x;
    return par[x] = find(par[x]);
}

void merge(int a, int b) {
    a = find(a), b = find(b);
    if (a != b) {
        par[a] = b;
        cnt--;
        sz[b] += sz[a];
        mx = max(mx, sz[b]);
    }
}

void solve() {
    cin >> n >> m;

    cnt = n, mx = 1;
    fill(par, par + n, -1);
    fill(sz, sz + n, 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        merge(u, v);
        cout << cnt << ' ' << mx << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
