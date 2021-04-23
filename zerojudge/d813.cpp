#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50005;

vector<int> pa;

int find(int x) {
    return pa[x] = (pa[x] == x) ? x : find(pa[x]);
}

void _union(int x, int y) {
    int px = find(x);
    int py = find(y);

    pa[px] = py;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    pa.resize(MAXN);

    int n, m;
    int T = 1;
    while (cin >> n >> m && n && m) {
        for (int i = 0; i < n; i++)
            pa[i] = i;

        int x, y;
        while (m--) {
            cin >> x >> y;
            _union(x, y);
        }

        set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(find(i));
        }

        cout << "Case " << T++ << ": " << st.size() << '\n';
    }
}
