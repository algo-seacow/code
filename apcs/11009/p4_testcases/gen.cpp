#include <bits/stdc++.h>
using namespace std;

void gen(int n, int k) {
  cout << n << ' ' << k << '\n';
  for (int i = 0; i < n; i++)
    cout << rand() % 100000 + 1 << " \n"[i + 1 == n];
}

void subtask1() {
  gen(rand() % 1000 + 1e6 - 999, 1);
}

void subtask2() {
  int x = rand() % 1000 + 5e6 - 999;
  int k = rand() % 10 + 20 - 9;
  int n = x / k;
  gen(n, k);
}

int main(int argc, char **argv) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <subtask> <seed>\n";
    exit(0);
  }

  srand(atoi(argv[2]));
  switch(atoi(argv[1])) {
    case 1:
      subtask1();
      break;
    case 2:
      subtask2();
      break;
    default:
      cout << "illegal subtask\n";
      assert(false);
  }
}
