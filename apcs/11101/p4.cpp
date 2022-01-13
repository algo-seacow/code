#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    vector<int> b(k);
    int mx = 0;
    for (auto &i : v) {
        cin >> i;
        mx = max(mx, i);
    }
    for (auto &i : b) {
        cin >> i;
    }
    int l = 0, r = mx + 1;
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        int ptr = 0;
        int cur = 0;
        for (auto &i : v) {
            if (i >= mid) {
                cur++;
                if (cur == b[ptr]) {
                    ptr++;
                    if (ptr == k) {
                        break;
                    }
                    cur = 0;
                }
            } else {
                cur = 0;
            }
        }
        if (ptr == k) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << '\n';
}
