#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
    int N = (1 << n);  // 2**n
    for (int S = 0; S < N; S++) {
        for (int i = n - 1; i >= 0; i--) {
            if (S & (1 << i)) {
                cout << '1';
            } else {
                cout << '0';
            }
        }
        cout << '\n';
    }
}

int main() {
    int n;
    while (cin >> n) {
        solve(n);
    }
    return 0;
}
