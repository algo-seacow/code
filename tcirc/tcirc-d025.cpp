#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n;
int root;
vector<int> parent;
vector<int> children[MAXN];
vector<int> height;  // height[i] : height of the subtree rooted at i

void init() {
    cin >> n;
    parent = vector<int>(n + 1, -1);
    height = vector<int>(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        children[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> children[i][j];
            parent[children[i][j]] = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (parent[i] == -1) {
            root = i;
        }
    }
}

void dfs(int u) {
    height[u] = 0;
    for (int i = 0; i < (int)children[u].size(); i++) {
        int v = children[u][i];
        dfs(v);
        height[u] = max(height[u], height[v] + 1);
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    init();
    dfs(root);

    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += height[i];
    }
    cout << root << '\n';
    cout << sum << '\n';

    return 0;
}
