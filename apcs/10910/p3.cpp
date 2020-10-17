// Copyright (C) Algo Seacow. 2020. All Rights Reserved.
#include <bits/stdc++.h>
using namespace std;

vector<int> update(vector<int> pre, vector<int> x) {
    int n = pre.size();

    vector<int> fromL(n);
    fromL[0] = pre[0] + x[0];
    for (int i = 1; i < n; i++) {
        fromL[i] = max(pre[i] + x[i], fromL[i - 1] + x[i]);
    }

    vector<int> fromR(n);
    fromR[n - 1] = pre[n - 1] + x[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        fromR[i] = max(pre[i] + x[i], fromR[i + 1] + x[i]);
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = max(fromL[i], fromR[i]);
    }
    return ans;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int m, n;
    cin >> m >> n;

    vector<int> ans(n, 0);
    while (m--) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ans = update(ans, a);
    }

    cout << *max_element(ans.begin(), ans.end()) << endl;

    return 0;
}
