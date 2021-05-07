#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    while (cin >> n) {
        if (n == 0) break;
        for (int i = 1; i < n; i++) {
            if (i % 7 != 0) {
                cout << i << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
