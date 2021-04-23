#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int par[MAXN];

int find(int x) {
    if (par[x] == x) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}

void merge(int a, int b) {
    par[find(a)] = find(b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) par[i] = i;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }
    vector<int> ans;
    for (int i = 2; i <= n; i++) {
        if (find(1) != find(i)) {
            merge(1, i);
            ans.push_back(i);
        }
    }
    cout << ans.size() << '\n';
    for (int x : ans) {
        cout << 1 << " " << x << '\n';
    }
    return 0;
}
