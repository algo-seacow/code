#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> A(n);
    vector<int> B(m);

    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < m; i++)
        cin >> B[i];

    int maxV = INT_MIN;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int cur = 0;
            for (int r = 0; i + r < n && j + r < m; r++) {
                cur += A[i + r] * B[j + r];
                maxV = max(maxV, cur);
            }
        }
    }

    reverse(A.begin(), A.end());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int cur = 0;
            for (int r = 0; i + r < n && j + r < m; r++) {
                cur += A[i + r] * B[j + r];
                maxV = max(maxV, cur);
            }
        }
    }

    cout << maxV << endl;
}
