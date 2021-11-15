#include <bits/stdc++.h>
using namespace std;
const int maxn = 20005;
vector<int> g[maxn];
vector<pair<int, int>> v[maxn];
int n, m, p, k;
int color[maxn];
bool dfs(int now) {
    int f = 1;
    for (auto &i : g[now]) {
        if (~color[i]) {
            if (color[i] == color[now]) {
                return 0;
            }
            continue;
        }
        color[i] = 1 - color[now];
        f &= dfs(i);
    }
    return f;
}
bool check(int l, int r) {
    int f = 1;
    for (int i = l; i <= r; i++) {
        for (auto &j : v[i]) {
            g[j.first].push_back(j.second);
            g[j.second].push_back(j.first);
        }
    }
    fill(color, color + n, -1);
    for (int i = 0; i < n; i++) {  // 判二分圖
        if (color[i] == -1) {
            color[i] = 0;
            f &= dfs(i);
            if (!f) {
                break;
            }
        }
    }
    for (int i = l; i <= r; i++) {
        for (auto &j : v[i]) {
            g[j.first].pop_back();
            g[j.second].pop_back();
        }
    }
    return f;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cin >> p >> k;
    for (int i = 1; i <= p; i++) {
        for (int j = 0; j < k; j++) {
            int a, b;
            cin >> a >> b;
            v[i].push_back({a, b});
        }
    }
    int L = 1;
    for (int i = 0; i < 3; i++) {
        if (check(L, p)) {  // 加入這些觀察員是否為二分圖
            break;
        }
        int l = L - 1, r = p;
        while (r - l > 1) {
            int mid = (l + r) >> 1;
            if (check(L, mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << r << '\n';
        L = r + 1;
    }
}
