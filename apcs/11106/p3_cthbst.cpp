#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

const int N = 30000;

using Mirror = vector<int>;

int n;
vector<Mirror> vx[N * 2 + 5];
vector<Mirror> vy[N * 2 + 5];

void init() {
    set<pair<int, int>> st;
    cin >> n;
    assert(1 <= n && n <= 250000);
    for (int i = 0; i < n; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        assert(0 < x && x <= 30000 && -30000 <= y && y <= 30000);
        assert(0 <= t && t <= 1);
        // assert(0 < x && x <= 100 && -100 <= y && y <= 100);
        y += N;

        vx[x].push_back({x, y, t});
        vy[y].push_back({x, y, t});
        st.insert({x, y});
    }
    assert(n == st.size());

    for (int i = 0; i < 2 * N + 5; i++) {
        sort(vx[i].begin(), vx[i].end());
        sort(vy[i].begin(), vy[i].end());
    }
}

int go_right(int, int);
int go_up(int, int);
int go_left(int, int);
int go_down(int, int);

int go_right(int x, int y) {
    auto it = upper_bound(vy[y].begin(), vy[y].end(), Mirror{x, y, 3});
    if (it == vy[y].end()) return 0;

    Mirror m = *it;
    if (m[2] == 0) {  // m[2] = '/'
        return 1 + go_up(m[0], m[1]);
    } else {
        return 1 + go_down(m[0], m[1]);
    }
}

int go_up(int x, int y) {
    auto it = upper_bound(vx[x].begin(), vx[x].end(), Mirror{x, y, 3});
    if (it == vx[x].end()) return 0;

    Mirror m = *it;
    if (m[2] == 0) {  // m[2] = '/'
        return 1 + go_right(m[0], m[1]);
    } else {
        return 1 + go_left(m[0], m[1]);
    }
}

int go_left(int x, int y) {
    auto it = lower_bound(vy[y].begin(), vy[y].end(), Mirror{x, y, -1});
    if (it == vy[y].begin()) return 0;

    Mirror m = *prev(it);
    if (m[2] == 0) {  // m[2] = '/'
        return 1 + go_down(m[0], m[1]);
    } else {
        return 1 + go_up(m[0], m[1]);
    }
}

int go_down(int x, int y) {
    auto it = lower_bound(vx[x].begin(), vx[x].end(), Mirror{x, y, -1});
    if (it == vx[x].begin()) return 0;

    Mirror m = *prev(it);
    if (m[2] == 0) {  // m[2] = '/'
        return 1 + go_left(m[0], m[1]);
    } else {
        return 1 + go_right(m[0], m[1]);
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    init();
    int ans = go_right(0, 0 + N);
    cout << ans << '\n';

    return 0;
}
