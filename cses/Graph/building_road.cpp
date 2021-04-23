#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
#define endl '\n'
const int maxn = 1e5 + 5;

int dsu[maxn];
int fnd(int x) {
    return x == dsu[x] ? x : dsu[x] = fnd(dsu[x]);
}

int32_t main() {
    IOS;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        dsu[i] = i;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dsu[fnd(a)] = fnd(b);
    }
    vector<int> ans;
    for (int i = 2; i <= n; i++) {
        if (fnd(1) != fnd(i)) {
            dsu[fnd(i)] = fnd(1);
            ans.emplace_back(i);
        }
    }
    cout << ans.size() << endl;
    for (int x : ans) {
        cout << "1 " << x << endl;
    }
    return 0;
}
