#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int n, m;
int root;
int weight[MAXN];
int query[MAXN];
int lc[MAXN], rc[MAXN];
int parent[MAXN];

void init() {
    cin >> n >> m;
    fill(parent, parent + n, -1);

    for (int i = n; i <= 2 * n - 1; i++) {
        cin >> weight[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> query[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int p, l, r;
        cin >> p >> l >> r;
        lc[p] = l;
        rc[p] = r;
        parent[l] = p;
        parent[r] = p;
    }
    for (int i = 1; i <= n - 1; i++) {
        if (parent[i] == -1) {
            root = i;
        }
    }
}

void build(int u) {
    if (u >= n) return;
    build(lc[u]);
    build(rc[u]);
    weight[u] = weight[lc[u]] + weight[rc[u]];
}

int insert(int u, int w) {
    weight[u] += w;

    if (u >= n) {
        return u;
    }

    if (weight[lc[u]] <= weight[rc[u]]) {
        return insert(lc[u], w);
    } else {
        return insert(rc[u], w);
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    init();
    build(root);
    for (int i = 0; i < m; i++) {
        int q = query[i];
        cout << insert(root, q) << (i == m - 1 ? "\n" : " ");
    }

    return 0;
}
