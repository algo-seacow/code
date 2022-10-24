#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
vector<vector<pii>> shape = {
  {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
  {{0, 0}, {0, -1}, {0, -2}},
  {{0, 0}, {0, -1}, {1, 0}, {1, -1}},
  {{0, 0}, {1, 0}, {1, -1}, {1, -2}},
  {{0, 0}, {1, 0}, {2, 0}, {1, -1}, {2, -1}}
};

bool check(auto &app, char t, int x, int y) {
  y--;
  int r = app.size(), c = app[0].size();
  for (auto &[dx, dy] : shape[t - 'A']) {
    int nx = x + dx;
    int ny = y + dy;
    if (nx < 0 or nx >= r or ny < 0 or ny >= c)
      return false;
    if (app[nx][ny])
      return false;
  }
  return true;
}

bool push(auto &app, char t, int y) {
  int r = app.size(), c = app[0].size();
  if (not check(app, t, y, c))
    return false;
  for (int x = c - 1; x >= 0; x--) {
    if (check(app, t, y, x))
      continue;
    for (auto &[dx, dy] : shape[t - 'A']) {
      int nx = y + dx;
      int ny = x + dy;
      assert(not app[nx][ny]);
      app[nx][ny] = 1;
    }
    break;
  }
  return true;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int r, c, n;
  cin >> r >> c >> n;
  auto app = vector<vector<int>>(r, vector<int>(c));

  int fail = n;
  for (int i = 0; i < n; i++) {
    char t; int y;
    cin >> t >> y;
    fail -= push(app, t, y);
  }
  int cnt = 0;
  for (auto &vv : app)
    for (auto &v : vv)
      cnt += v == 0;
  cout << cnt << ' ' << fail << '\n';
}
