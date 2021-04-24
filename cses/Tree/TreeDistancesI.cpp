#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int n;
int root = 0;
vector<int> G[MAXN];
int h[MAXN];  // h[i] : height of the subtree that rooted at i
int p[MAXN];

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
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if (v == par) continue;
        dfs(v, u);
        h[u] = max(h[u], h[v] + 1);
    }
}

void push(int u, int par) {
    int a = par, al = p[u] + 1;
    int b = -1, bl = -1;

    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if (v == par) continue;
        int vl = h[v] + 2;
        if (vl > al) {
            b = a, bl = al;
            a = v, al = vl;
        } else if (vl > bl) {
            b = v, bl = vl;
        }
    }

    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if (v == par) continue;
        if (v == a) {
            p[v] = bl;
            push(v, u);
        } else {
            p[v] = al;
            push(v, u);
        }
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    init();
    dfs(root, -1);
    p[root] = 0;
    push(root, -1);

    for (int i = 0; i < n; i++) {
        int ansi = max(h[i], p[i]);
        cout << ansi << (i == n - 1 ? "\n" : " ");
    }

    return 0;
}
