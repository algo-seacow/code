#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, d;
    cin >> n >> d;
    int ans = 0;
    int cur = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cur = v[0];
    int f = 1;
    for (int i = 1; i < n; i++) {
        if (f) {
            if (v[i] >= cur + d) {
                ans += v[i] - cur;
                f = 0;
                cur = v[i];
            }
        } else {
            if (v[i] <= cur - d) {
                cur = v[i];
                f = 1;
            }
        }
    }
    cout << ans << '\n';
}
