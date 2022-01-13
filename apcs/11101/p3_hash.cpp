#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

int pow(int a, int n, int mod) {
    int ret = 1;
    while (n > 0) {
        if (n & 1) ret = 1ll * ret * a % mod;
        a = 1ll * a * a % mod;
        n >>= 1;
    }
    return ret;
}

const int N = 50004;
const int X = 12383;
const int Y = 7123343;
const int M = 102;
const long long P = 1000000007;

long long pw[2][M];
long long iv[2][M];

int n;
string str[N];
vector<pll> h[N];

ll hsub(const vector<pll> &psum, int l, int r) {
    long long val = (psum[r + 1].first - psum[l].first) % P * iv[0][l] % P;
    long long val2 = (psum[r + 1].second - psum[l].second) % P * iv[1][l] % P;

    return val << 32 | val2;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    pw[0][0] = 1;
    for (int i = 1; i < M; i++) pw[0][i] = pw[0][i - 1] * X % P;

    iv[0][0] = 1;
    iv[0][1] = pow(X, P - 2, P);
    for (int i = 2; i < M; i++) iv[0][i] = iv[0][i - 1] * iv[0][1] % P;

    pw[1][0] = 1;
    for (int i = 1; i < M; i++) pw[1][i] = pw[1][i - 1] * Y % P;

    iv[1][0] = 1;
    iv[1][1] = pow(Y, P - 2, P);
    for (int i = 2; i < M; i++) iv[1][i] = iv[1][i - 1] * iv[1][1] % P;

    set<long long> dict;

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        str[i] = s;

        auto &v = h[i];
        v.push_back({0, 0});
        for (size_t j = 0; j < s.size(); j++) {
            v.push_back({v[j].first + s[j] * pw[0][j] % P,
                         v[j].second + s[j] * pw[1][j] % P});
        }
        dict.insert(hsub(v, 0, s.size() - 1));
    }

    int ans = 0;
    for (int it = 0; it < n; it++) {
        const string &s = str[it];
        int len = s.size();
        for (int d = 1; 2 * d + 1 <= len; d++) {
            if (hsub(h[it], 0, d - 1) == hsub(h[it], len - d, len - 1)) {
                long long hmid = hsub(h[it], d, len - d - 1);
                if (dict.count(hmid)) ans++;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
