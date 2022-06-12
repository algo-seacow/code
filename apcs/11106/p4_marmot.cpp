#include <bits/stdc++.h>
using namespace std;
 
const int INF = 0x3f3f3f3f;
 
int solve(vector<int> &A, vector<int> &B) {
  int n = A.size(), m = B.size();
 
  int maxv = -INF;
  for (int os = -n-m; os <= n+m; os++) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
      if (0 <= i + os and i + os < n) {
        sum += A[i + os] * B[i];
        maxv = max(maxv, sum);
        sum = max(sum, 0);
      }
    }
  }
 
  return maxv;
}
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  auto A = vector<int>(n);
  auto B = vector<int>(m);
 
  for (auto &v : A)
    cin >> v;
  for (auto &v : B)
    cin >> v;
 
  int maxv = -INF;
  maxv = max(maxv, solve(A, B));
  reverse(A.begin(), A.end());
  maxv = max(maxv, solve(A, B));
 
  cout << maxv << '\n';
}
