#include <bits/stdc++.h>
using namespace std;

void gen(int n, int m, int k) {
}

void subtask1() {
  int n = 1, m = rand() % 10 + 91, k = rand() % 400 + 101;
  cout << n << ' ' << m << ' ' << k << '\n';
  while (k--) {
    cout << rand() % n << ' ' << rand() % m << ' ';
    cout << 0 << ' ' << rand() % 10 - 5 << '\n';
  }
}

void subtask2() {
  int n = rand() % 10 + 91, m = rand() % 10 + 91, k = rand() % 400 + 101;
  cout << n << ' ' << m << ' ' << k << '\n';
  while (k--) {
    cout << rand() % n << ' ' << rand() % m << ' ';
    cout << rand() % 10 - 5 << ' ' << rand() % 10 - 5 << '\n';
  }
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
