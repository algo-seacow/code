#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int maxv = -1, maxt = 0;
    int bad = 0;
    for (int i = 0; i < n; i++) {
        int t, s;
        cin >> t >> s;
        if (s == -1) {
            bad++;
        } else if (maxv < s) {
            maxv = s, maxt = t;
        }
    }
    int ans = maxv - bad * 2 - n;
    if (ans < 0) ans = 0;
    cout << ans << ' ' << maxt << '\n';
}
