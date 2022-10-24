#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
  cin.tie(0)->sync_with_stdio(0);

  if (argc - 1 != 5) {
    cout << "Usage: " << argv[0] << " <s#> <r> <c> <n> <seed>\n";
    exit(0);
  }

  int sn = atoi(argv[1]);
  int r = atoi(argv[2]);
  int c = atoi(argv[3]);
  int n = atoi(argv[4]);
  int seed = atoi(argv[5]);

  srand(seed);

  cout << r << ' ' << c << ' ' << n << '\n';
  if (sn == 1) {
    for (int i = 0; i < n; i++) {
      cout << 'B' << ' ' << rand() % r << '\n';
    }
  } else if (sn == 2) {
    for (int i = 0; i < n; i++) {
      char op = 'A' + rand() % 3;
      if (op == 'A')
        cout << op << ' ' << rand() % (r - 3) << '\n';
      else if (op == 'B')
        cout << op << ' ' << rand() % r << '\n';
      else if (op == 'C')
        cout << op << ' ' << rand() % (r - 1) << '\n';
    }
  } else {
    for (int i = 0; i < n; i++) {
      char op = 'A' + rand() % 5;
      if (op == 'A')
        cout << op << ' ' << rand() % (r - 3) << '\n';
      else if (op == 'B')
        cout << op << ' ' << rand() % r << '\n';
      else if (op == 'C')
        cout << op << ' ' << rand() % (r - 1) << '\n';
      else if (op == 'D')
        cout << op << ' ' << rand() % (r - 1) << '\n';
      else if (op == 'E')
        cout << op << ' ' << rand() % (r - 2) << '\n';
    }
  }
}
