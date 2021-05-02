#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> C[105];  // <y, z>
long long dp[1 << 18];

void init() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        C[x].push_back({y, z});
    }
}

void solve() {
    dp[0] = 1;
    for (int S = 1; S < (1 << n); S++) {
        dp[S] = 0;
        bool flag = true;
        int sz = __builtin_popcount(S);
        for (int i = 0; i < (int)C[sz].size(); i++) {
            int y = C[sz][i].first;
            int z = C[sz][i].second;
            for (int j = 0; j < y; j++) {
                if (S & (1 << j)) z--;
            }
            if (z < 0) flag = false;
        }
        if (flag == true) {
            for (int i = 0; i < n; i++) {
                if (S & (1 << i)) {
                    dp[S] += dp[S ^ (1 << i)];
                }
            }
        }
    }
    cout << dp[(1 << n) - 1] << '\n';
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    init();
    solve();

    return 0;
}
