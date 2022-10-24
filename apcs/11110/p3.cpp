#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <iostream>

using namespace std;

long long ans = 0;

int depth = 0;
int dep = 0;

int dfs() {
    dep++;
    depth = max(depth, dep);
    int u;
    if (u == 0) {
        dep--;
        return 0;
    }
    for (int i = 0; i < 2 + (u % 2); i++) {
        int v = dfs();
        if (v != 0) ans += abs(u - v);
    }
    dep--;
    return u;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    dfs();
    cout << ans << '\n';
    assert(depth <= 40);

    return 0;
}
