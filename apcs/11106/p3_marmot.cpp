#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

void turn(int &d, int t) {
    if (t == 0) {
        if (d == 0)
            d = 1;
        else if (d == 1)
            d = 0;
        else if (d == 2)
            d = 3;
        else if (d == 3)
            d = 2;
    } else {
        if (d == 0)
            d = 3;
        else if (d == 3)
            d = 0;
        else if (d == 1)
            d = 2;
        else if (d == 2)
            d = 1;
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    auto X = map<int, map<int, int>>{};
    auto Y = map<int, map<int, int>>{};

    for (int i = 0; i < n; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        X[x][y] = t;
        Y[y][x] = t;
    }

    int d = 0, cnt = 0;
    int x = 0, y = 0;
    while (1) {
        if (d == 0) {
            // right
            if (not Y.count(y)) break;
            auto it = Y[y].upper_bound(x);
            if (it == Y[y].end()) break;
            x = it->first;
            turn(d, it->second);
        } else if (d == 2) {
            // left
            if (not Y.count(y)) break;
            auto it = Y[y].lower_bound(x);
            if (it == Y[y].begin()) break;
            it--;
            x = it->first;
            turn(d, it->second);
        } else if (d == 1) {
            // up
            if (not X.count(x)) break;
            auto it = X[x].upper_bound(y);
            if (it == X[x].end()) break;
            y = it->first;
            turn(d, it->second);
        } else if (d == 3) {
            // down
            if (not X.count(x)) break;
            auto it = X[x].lower_bound(y);
            if (it == X[x].begin()) break;
            it--;
            y = it->first;
            turn(d, it->second);
        }
        cnt++;
    }

    cout << cnt << '\n';
}
