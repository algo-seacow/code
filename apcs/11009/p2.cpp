#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m >> k;
  assert(1 <= n and n <= 100);
  assert(1 <= m and m <= 100);
  assert(1 <= k and k <= 500);

  vector<pair<int, int>> kings;
  vector<vector<vector<int>>> B(n, vector<vector<int>>(m));
  vector<vector<int>> bumb(n, vector<int>(m));
  for (int i = 0; i < k; i++) {
    int x, y, dx, dy;
    cin >> x >> y >> dx >> dy;
    assert(0 <= x and x < n);
    assert(0 <= y and y < m);
    kings.push_back({dx, dy});
    B[x][y].push_back(i);
  }

  while (1) {
    int cnt = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cnt += B[i][j].size();
    if (cnt == 0)
      break;

    vector<vector<vector<int>>> B_tmp(n, vector<vector<int>>(m));
    auto bumb_tmp = bumb;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (B[i][j].size())
          bumb_tmp[i][j] = 1;
        for (auto &v : B[i][j]) {
          int nx = i + kings[v].F;
          int ny = j + kings[v].S;
          if (nx < 0 or nx >= n or ny < 0 or ny >= m)
            continue;
          B_tmp[nx][ny].push_back(v);
        }
      }
    }

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (bumb_tmp[i][j] and B_tmp[i][j].size()) {
          bumb_tmp[i][j] = 0, B_tmp[i][j].clear();
        }
    B = B_tmp;
    bumb = bumb_tmp;
  }

  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      ans += bumb[i][j];

  cout << ans << '\n';
}
