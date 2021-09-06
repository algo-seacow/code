#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

struct DSU {
  vector<int> pa;
  DSU(int n) : pa(n, -1) {}

  int find(int x) {
    return pa[x] < 0 ? x : pa[x] = find(pa[x]);
  }

  int size(int x) {
    return -pa[find(x)];
  }

  void merge(int u, int v) {
    int x = find(u);
    int y = find(v);
    if (x == y)
      return ;
    if (pa[x] > pa[y])
      swap(x, y);
    pa[x] += pa[y];
    pa[y] = x;
  }
};

using LL = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  assert(1 <= n and n <= 3e5);
  set<int> st;

  vector<int> arr(n);
  vector<pair<int, int>> pool;
  for (int i = 0; i < n; i++)
    cin >> arr[i], pool.push_back({arr[i], i}), st.insert(arr[i]);

  assert(st.size() == n);

  sort(pool.rbegin(), pool.rend());

  vector<LL> preS{0};
  for (int i = 0; i < n; i++)
    preS.push_back(preS.back() + arr[i]);

  DSU dsu(n);
  vector<int> vis(n, 0);
  vector<pair<pair<int, int>, int>> range;
  for (int i = 0; i < n; i++) {
    int idx = pool[i].S;
    vis[idx] = 1;
    int l = idx, r = idx + 1;
    if (idx - 1 >= 0 and vis[idx - 1]) {
      l -= dsu.size(idx - 1);
      dsu.merge(idx, idx - 1);
    }
    if (idx + 1 < n and vis[idx + 1]) {
      r += dsu.size(idx + 1);
      dsu.merge(idx, idx + 1);
    }

    range.push_back({{l, r}, idx});
  }
  
  int l = 0, r = n;
  while (l + 1 < r) {
    while (range.back().F.F != l or range.back().F.S != r)
      range.pop_back();
    int pivot = range.back().S;
    
    if (preS[pivot] - preS[l] <= preS[r] - preS[pivot+ 1])
      l = pivot + 1;
    else
      r = pivot;
  }
  cout << arr[l] << '\n';
}
