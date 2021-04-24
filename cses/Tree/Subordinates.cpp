#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int n;
int root;
vector<int> children[MAXN];
vector<int> ans;  // ans[i] : size of the subtree rooted at i

void init() {
    cin >> n;
    root = 1;
    for (int i = 2; i <= n; i++) {
        int par;
        cin >> par;
        children[par].push_back(i);
    }
    ans = vector<int>(n + 1, 0);
}

void dfs(int u) {
    ans[u] = 1;
    for (int i = 0; i < (int)children[u].size(); i++) {
        int v = children[u][i];
        dfs(v);
        ans[u] += ans[v];
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    init();
    dfs(root);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] - 1 << (i == n ? '\n' : ' ');
    }

    return 0;
}
