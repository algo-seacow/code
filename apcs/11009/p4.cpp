#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k; cin >> n >> k;
  assert(1 <= n and n <= 1e6);
  assert(1 <= k and k <= 20);
  assert(1 <= n * k and n * k <= 5e6);
  vector<int> arr(n);
  for (auto &v : arr)
    cin >> v, assert(1 <= v and v <= 1e5);
   
  vector<int> pre(n + 1), cur(n + 1);
  for (int x = 0; x < k; x++) {
    int l = 0, maxv = 0;
    vector<int> app(1e5 + 5, 0);
    for (int r = 0; r < n; r++) {
      while (app[arr[r]])
        app[arr[l]] = 0, l++, maxv = max(maxv, pre[l]);
      app[arr[r]] = 1;
      cur[r + 1] = (r + 1) - l + maxv;
    }
    swap(pre, cur);
  }
  int ans = 0;
  for (int i = 0; i <= n; i++)
    ans = max(ans, pre[i]);
  cout << ans << '\n';
}
