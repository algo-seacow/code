#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
#define endl '\n'

const int maxn = 1e3 + 5;
int graph[maxn][maxn];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m;
void gogo(int x, int y) {
    if (x >= 0 && y >= 0 && x < n && y < m && graph[x][y] == 0) {
        graph[x][y] = 1;
        for (int i = 0; i < 4; i++)
            gogo(x + dx[i], y + dy[i]);
    }
}

int32_t main() {
    IOS;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch;
            cin >> ch;
            if (ch == '#')
                graph[i][j] = -1;
            else if (ch == '.')
                graph[i][j] = 0;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 0) {
                gogo(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}