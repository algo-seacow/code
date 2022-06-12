#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  auto M = vector<string>(n);
  for (auto &e : M)
    cin >> e;
  reverse(M.begin(), M.end());

  auto T = string{};
  cin >> T;
  cout << '\n';
  for (auto &e : M) {
    auto S = string{};
    for (int i = 0; i < m; i++)
      if (e[i] == '0')
        S += T[i];

    for (int i = m - 1; i >= 0; i--)
      if (e[i] == '1')
        S += T[i];

    cout << S << '\n';

    int cnt = 0;
    for (int i = 0; i < m; i++)
      cnt += e[i] == '1';

    if (cnt % 2) {
      if (m % 2 == 0) {
        T = S.substr(m / 2) + S.substr(0, m / 2);
      } else {
        T = S.substr(m / 2 + 1) + S[m / 2] + S.substr(0, m / 2);
      }
    } else {
      T = S;
    }

    cout << T << '\n';

  }
  cout << T << '\n';
}
