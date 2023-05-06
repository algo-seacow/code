#include <iostream>
#include <set>

using namespace std;

const int maxn = 200005;

int n, k;
int l[maxn], r[maxn];

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> l[i];
    for (int i = 0; i < n; i++) cin >> r[i];

    vector<int> v;
    for (int i = 0; i < n; i++) v.push_back(i);
    sort(v.begin(), v.end(), [&](int x, int y) { return r[x] < r[y]; });

    multiset<int> st;
    for (int i = 0; i < k; i++) {
        st.insert(0);
    }
    int ans = 0;
    for (auto &i : v) {
        int start = l[i];
        if (st.lower_bound(start) == st.begin()) {
            continue;
        } else {
            ans++;
            st.erase(prev(st.lower_bound(start)));
            st.insert(r[i]);
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    solve();
}
