#include <bits/stdc++.h>
using namespace std;

void Manacher(int n, char s[], int d[]) {
    int m = 0, r = 0;
    for (int i = 0; i < n; i++) {
        if (i < r) d[i] = min(d[m - (i - m)], r - i);
        if (i + d[i] >= r) {
            while (0 <= i - d[i] - 1 && i + d[i] + 1 < n) {
                if (s[i - d[i] - 1] != s[i + d[i] + 1]) break;
                d[i]++;
            }
            m = i;
            r = i + d[i];
        }
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    string s;
    cin >> s;
    string t;
    for (char c : s) {
        t.push_back('$');
        t.push_back(c);
    }
    t.push_back('$');

    int n = t.size();
    vector<int> d(n);
    Manacher(n, t.data(), d.data());

    auto it = max_element(d.begin(), d.end());
    int m = it - d.begin();
    int r = *it;
    cout << s.substr((m - r) / 2, r) << '\n';

    return 0;
}
