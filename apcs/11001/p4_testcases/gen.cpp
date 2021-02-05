#include <bits/stdc++.h>
using namespace std;

void gen(int n, int v_upper) {
    cout << n << '\n';
    vector<int> X, Y;
    for (int i = 0 ; i < n ; i++)
        X.push_back(rand() % v_upper + 1),
        Y.push_back(rand() % v_upper + 1);
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    int t = n / 20;
    while (t--) {
        int i = rand() % n;
        int j = rand() % n;
        swap(Y[i], Y[j]);
    }
    set<pair<int, int>> ps;
    for (int i = 0 ; i < n ; i++)
        ps.insert({X[i], Y[i]});
    while (ps.size() != n) {
        int x = rand() % v_upper + 1;
        int y = rand() % v_upper + 1;
        ps.insert({x, y});
    }
    assert(ps.size() == n);
    vector<pair<int, int>> ps_vec;
    for (auto &v : ps)
        ps_vec.push_back(v);
    random_shuffle(ps_vec.begin(), ps_vec.end());
    for (auto &p : ps_vec)
        cout << p.first << ' ' << p.second << '\n';
}

void testcase1() {
    int n = rand() % 100 + 1;
    int v_upper = 100;
    gen(n, v_upper);
}
void testcase2() {
    int n = rand() % 1000 + 1;
    int v_upper = 1e7;
    gen(n, v_upper);
}
void testcase3() {
    int n = rand() % 200000 + 1;
    int v_upper = 1e7;
    gen(n, v_upper);
}

int main(int argc, char **argv) {
    srand(time(NULL));
    if (argc - 1 != 1) {
        cout << "Usage: " << argv[0] << " #testcase\n";
        exit(1);
    }
    switch (atoi(argv[1])) {
        case 1:
            testcase1();
            break;
        case 2:
            testcase2();
            break;
        case 3:
            testcase3();
            break;
    }
}
