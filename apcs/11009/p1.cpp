#include <bits/stdc++.h>
using namespace std;

bool check_A(auto &arr) {
  return arr[0][2] != arr[0][4] and arr[0][2] == arr[0][6]
     and arr[1][2] != arr[1][4] and arr[1][2] == arr[1][6];
}

bool check_B(auto &arr) {
  return arr[0][7] == 1
     and arr[1][7] == 0;
}

bool check_C(auto &arr) {
  return arr[0][2] != arr[1][2]
     and arr[0][4] != arr[1][4]
     and arr[0][6] != arr[1][6];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  assert(1 <= t and t <= 30);
  while (t--) {
    vector<vector<int>> arr(2, vector<int>(8));
    for (int i = 0; i < 2; i++)
      for (int j = 1; j <= 7; j++)
        cin >> arr[i][j], assert(0 <= arr[i][j] and arr[i][j] <= 1);
    bool ok = true;
    if (not check_A(arr))
      cout << 'A', ok = false;
    if (not check_B(arr))
      cout << 'B', ok = false;
    if (not check_C(arr))
      cout << 'C', ok = false;
    if (ok)
      cout << "None";
    cout << '\n';
  }
}
