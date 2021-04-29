#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    if (n <= 1) {
        cout << 0 << '\n';
    } else {
        vector<int> dp(n);
        dp[0] = 0;
        dp[1] = abs(h[1] - h[0]);
        for (int i = 2; i < n; i++) {
            dp[i] = INF;
            for (int j = max(0, i - k); j < i; j++) {
                dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j]));
            }
        }
        cout << dp[n - 1] << '\n';
    }
    return 0;
}
