#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n;
int root = 0;
vector<pair<int, int>> children[MAXN];  // <to, distance>
int level[MAXN];
int dis[MAXN];

void init() {
    cin >> n;
    fill(children, children + n, vector<pair<int, int>>());
    fill(level, level + n, 0);
    fill(dis, dis + n, 0);

    for (int i = 1; i < n; i++) {
        int par, w;
        cin >> par >> w;
        children[par].push_back({i, w});
    }
}

void dfs(int u) {
    for (int i = 0; i < (int)children[u].size(); i++) {
        int v = children[u][i].first;
        int len = children[u][i].second;
        level[v] = level[u] + 1;
        dis[v] = dis[u] + len;
        dfs(v);
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    init();
    level[root] = 0;
    dis[root] = 0;
    dfs(root);

    int max_level = *max_element(level, level + n);
    int max_dis = *max_element(dis, dis + n);
    cout << max_dis << '\n';
    cout << max_level << '\n';

    return 0;
}
