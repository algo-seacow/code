// Copyright (C) Algo Seacow. 2020. All Rights Reserved.
#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int bit[N];
void add(int pos, long long val) {
    while (pos < N) {
        bit[pos] += val;
        pos += pos & (-pos);
    }
}
long long sum(int pos) {
    long long ans = 0;
    while (pos > 0) {
        ans += bit[pos];
        pos -= pos & (-pos);
    }
    return ans;
}

int n, l[N], r[N];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    // input
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        int x;
        cin >> x;
        if (l[x] == 0) {
            l[x] = i;
        } else {
            r[x] = i;
        }
    }

    // solve
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += sum(r[i]) - sum(l[i]);
        add(l[i], 1);
        add(r[i], 1);
    }
    cout << ans << '\n';

    return 0;
}
