#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;

int n, m;
int G[MAXN][MAXN];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(int x, int y) {
    if (x < 0 || x >= n) return;
    if (y < 0 || y >= m) return;
    if (G[x][y] == 0) {
        G[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            dfs(x + dx[i], y + dy[i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch;
            cin >> ch;
            if (ch == '#') {
                G[i][j] = -1;
            } else if (ch == '.') {
                G[i][j] = 0;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (G[i][j] == 0) {
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}
