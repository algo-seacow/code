#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  cin.tie(0)->sync_with_stdio(0);

  if (argc - 1 != 2) {
    cout << "Usage: " << argv[0] << " <n> <seed>\n";
    exit(0);
  }
  int n = atoi(argv[1]);
  int seed = atoi(argv[2]);
  srand(seed);
  
  cout << n << '\n';
  for (int i = 0; i < n; i++) {
    cout << rand() % 201 - 100 << ' ' << rand() % 201 - 100 << '\n';
  }
}
