#include <bits/stdc++.h>
using namespace std;

const int N = 1003;

int n, m;
long long s[N];
long long t[N];
int blood[N];

int p_cnt, w_cnt, l_cnt;
int p[N], w[N], l[N];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> m;
    assert(2<=n && n<=1000);
    assert(1<=m && m <= 5);
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 1; i <= n; i++) blood[i] = m;
    p_cnt = n;
    for (int i = 0; i < n; i++) cin >> p[i];

    while (p_cnt > 1) {
        // for (int i = 1; i <= n; i++) cout << blood[i] << ' ';
        // cout << '\n';

        w_cnt = 0;
        l_cnt = 0;
        for (int i = 0; i + 1 < p_cnt; i += 2) {
            int a = p[i], b = p[i + 1];
            if (s[a] * t[a] < s[b] * t[b]) {
                // a 輸b 贏
                swap(a, b);
            }
            // a 贏 b 輸
            int new_sa = s[a] + s[b] * t[b] / (2 * t[a]);
            int new_ta = t[a] + s[b] * t[b] / (2 * s[a]);
            s[a] = new_sa;
            t[a] = new_ta;
            s[b] += s[b] / 2;
            t[b] += t[b] / 2;

            // 放入 w[], l[]
            w[w_cnt++] = a;

            blood[b]--;
            if (blood[b] > 0) {
                l[l_cnt++] = b;
            }
        }
        // 合併 w[], l[]
        if (p_cnt % 2 == 1) {
            w[w_cnt++] = p[p_cnt - 1];
        }
        p_cnt = 0;
        for (int i = 0; i < w_cnt; i++) p[p_cnt++] = w[i];
        for (int i = 0; i < l_cnt; i++) p[p_cnt++] = l[i];
    }
    cout << p[0] << '\n';

    return 0;
}
// 一開始就只有一個人
// long long
