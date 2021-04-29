#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
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
            dp[i] = min(dp[i - 2] + abs(h[i] - h[i - 2]),
                        dp[i - 1] + abs(h[i] - h[i - 1]));
        }
        cout << dp[n - 1] << '\n';
    }
    return 0;
}
