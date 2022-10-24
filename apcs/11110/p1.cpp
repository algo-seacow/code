#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

const int INF = 0x3f3f3f3f;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  auto ps = vector<pii>(n);
  for (auto &[x, y] : ps)
    cin >> x >> y;

  int maxv = 0, minv = INF;
  for (int i = 1; i < n; i++) {
    int dst = abs(ps[i - 1].first - ps[i].first) + abs(ps[i - 1].second - ps[i].second);
    maxv = max(maxv, dst);
    minv = min(minv, dst);
  }

  cout << maxv << ' ' << minv << '\n';
}
