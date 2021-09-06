#include <bits/stdc++.h>
using namespace std;

void line() {
  vector<vector<int>> arr(2, vector<int>(7));
  for (auto &vv : arr)
    for (auto &v : vv)
      v = rand() % 2;

  if (rand() % 15 == 0) {
    arr[0][6] = 1;
    arr[1][6] = 0;
    arr[0][3] = arr[0][1] ^ 1;
    arr[0][5] = arr[0][1];
    arr[1][1] = arr[0][1] ^ 1;
    arr[1][3] = arr[0][3] ^ 1;
    arr[1][5] = arr[0][5] ^ 1;
  }
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 7; j++)
      cout << arr[i][j] << " \n"[j + 1 == 7];
}
int main(int argc, char **argv) {
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " <seed>\n";
    exit(1);
  }
  srand(atoi(argv[1]));
  int t = 30;
  cout << t << '\n';
  while (t--) {
    line();
  }
}
