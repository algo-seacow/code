#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int m, n;
string s[MAXN];

int ans;
map<string, int> cnt;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        cnt[s[i]]++;
        if (i >= m) {
            cnt[s[i - m]]--;
            if (cnt[s[i - m]] == 0) {
                cnt.erase(s[i - m]);
            }
        }
        if (cnt.size() == m) {
            ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}
