#include <bits/stdc++.h>
using namespace std;

void subtask1() {
  int n = rand() % 1000 + 3e5 - 999;
  vector<int> vec(n);
  iota(vec.begin(), vec.end(), 1);
  random_shuffle(vec.begin(), vec.end());

  cout << n << '\n';
  for (int i = 0; i < n; i++)
    cout << vec[i] << " \n"[i + 1 == n];
}

void subtask2() {
  int n = rand() % 1000 + 3e5 - 999;
  set<int> st;
  while (st.size() < n) {
    st.insert(rand() % 10000000 + 1);
  }
  vector<int> vec(st.begin(), st.end());
  random_shuffle(vec.begin(), vec.end());

  cout << n << '\n';
  for (int i = 0; i < n; i++)
    cout << vec[i] << " \n"[i + 1 == n];
}

void subtask3() {
  int n = rand() % 1000 + 3e5 - 999;
  set<int> st;
  while (st.size() < n) {
    st.insert(rand() % 10000000 + 1);
  }
  vector<int> vec(st.begin(), st.end());

  int t = 100;
  while (t--) {
    int x = rand() % n, y = rand() % n;
    swap(vec[x], vec[y]);
  }
  cout << n << '\n';
  for (int i = 0; i < n; i++)
    cout << vec[i] << " \n"[i + 1 == n];
}

void subtask4() {
  int n = rand() % 1000 + 3e5 - 999;
  set<int> st;
  while (st.size() < n) {
    st.insert(rand() % 10000000 + 1);
  }
  vector<int> vec(st.rbegin(), st.rend());

  int t = 100;
  while (t--) {
    int x = rand() % n, y = rand() % n;
    swap(vec[x], vec[y]);
  }
  cout << n << '\n';
  for (int i = 0; i < n; i++)
    cout << vec[i] << " \n"[i + 1 == n];
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
    case 3:
      subtask3();
      break;
    case 4:
      subtask4();
      break;
    default:
      cout << "illegal subtask\n";
      assert(false);
  }
}
