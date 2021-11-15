#include <bits/stdc++.h>
using namespace std;

int b[105][105];
int line[105][105][2];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, h;
    cin >> n >> m >> h;
    int maxv = 0;
    for (int i = 0; i < h; i++) {
        int x, y, op;
        cin >> x >> y >> op;
        if (!op) {
            b[x][y] = 1;
            line[x][y][0] = line[x][y][1] = 0;
            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                while (nx >= 0 && nx < n && ny >= 0 && ny < m && !b[nx][ny]) {
                    nx += dx[j];
                    ny += dy[j];
                }
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int px = x + dx[j];
                    int py = y + dy[j];
                    while (px != nx || py != ny) {
                        line[px][py][j % 2] = 1;
                        px += dx[j];
                        py += dy[j];
                    }
                }
            }
        } else {
            b[x][y] = 0;
            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                while (nx >= 0 && nx < n && ny >= 0 && ny < m && !b[nx][ny]) {
                    nx += dx[j];
                    ny += dy[j];
                }
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int px = x + dx[j];
                    int py = y + dy[j];
                    while (px != nx || py != ny) {
                        line[px][py][j % 2] = 0;
                        px += dx[j];
                        py += dy[j];
                    }
                }
            }
        }

        int cur = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (b[i][j] || line[i][j][0] || line[i][j][1]) {
                    cur++;
                }
            }
        }
        maxv = max(maxv, cur);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[i][j] || line[i][j][0] || line[i][j][1]) {
                ans++;
            }
        }
    }
    cout << maxv << '\n' << ans << '\n';
}
