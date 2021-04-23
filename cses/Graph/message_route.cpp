#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
#define endl '\n'
const int maxn = 1e5 + 5;

vector<int> edge[maxn];
int deep[maxn];

void bfs(int a, int d) {
    queue<pair<int, int> > qu;
    qu.push(make_pair(1, 1));
    while (qu.size()) {
        if (deep[qu.front().first] == 0) {
            deep[qu.front().first] = qu.front().second;
            for (int y : edge[qu.front().first]) {
                qu.push(make_pair(y, qu.front().second + 1));
            }
        }
        qu.pop();
    }
}

void dfs(int a) {
    for (int x : edge[a]) {
        if (deep[x] == deep[a] - 1) {
            dfs(x);
            break;
        }
    }
    cout << a << ' ';
}

int32_t main() {
    IOS;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].emplace_back(b);
        edge[b].emplace_back(a);
    }
    bfs(1, 1);
    if (deep[n] == 0) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << deep[n] << endl;
    dfs(n);
    cout << endl;
    return 0;
}
/*
5 5
1 2
1 3
1 4
2 3
5 4
*/