#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<long long> pre(n + 5);
    for (int i = 0; i < m; i++) {
        int l, r, w;
        cin >> l >> r >> w;
        pre[l] += w;
        pre[r + 1] -= w;
    }
    for (int i = 1; i <= n; i++) {
        pre[i] += pre[i - 1];
    }
    vector<long long> num(pre.begin() + 1, pre.begin() + n + 1);
    sort(num.begin(), num.end());
    vector<long long> t;
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        t.push_back(x);
    }
    sort(t.rbegin(), t.rend());
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += t[i] * num[i];
    }
    cout << ans << '\n';
}
