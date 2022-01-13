#include <bits/stdc++.h>
using namespace std;

const int N = 50004;

int n;
string str[N];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    set<string> dict;

    cin >> n;
    assert(2 <= n && n <= 50000);

    for (int i = 0; i < n; i++) {
        cin >> str[i];
        dict.insert(str[i]);
    }
    assert(dict.size() == n);

    int ans = 0;
    for (int it = 0; it < n; it++) {
        const string &s = str[it];
        int len = s.size();
        for (int d = 1; 2 * d + 1 <= len; d++) {
            if (s.substr(0, d) == s.substr(len - d, d)) {
                string mid = s.substr(d, len - 2 * d);
                if (dict.count(mid)) ans++;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
