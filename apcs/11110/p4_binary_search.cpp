#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

using pii = pair<int, int>;

int bfs(int M, auto &vec) {
    int n = vec.size();
    auto vis = vector<vector<int>>(n, vector<int>(n, -1));
    vis[0][0] = 0;
    queue<pii> q;
    q.emplace(0, 0);

    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
            if (vis[nx][ny] != -1) continue;
            if (abs(vec[x][y] - vec[nx][ny]) > M) continue;
            vis[nx][ny] = vis[x][y] + 1;
            q.emplace(nx, ny);
        }
    }
    return vis[n - 1][n - 1];
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n;
    cin >> n;
    auto vec = vector<vector<int>>(n, vector<int>(n));

    for (auto &vv : vec)
        for (auto &v : vv) cin >> v;

    int L = -1, R = 1e6 + 5;
    while (R - L > 1) {
        int M = (L + R) / 2;
        (bfs(M, vec) != -1 ? R : L) = M;
    }
    cout << R << '\n';
    cout << bfs(R, vec) << '\n';
}
