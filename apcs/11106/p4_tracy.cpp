#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int get_max_dot(vector<int> & A, vector<int> & B) {
    // -----A-----    : shift + ptr
    //    -----B----- : ptr
    int maxV = INT_MIN;
    for (int shift = 0; shift < A.size(); shift++) {
        int cur = A[shift] * B[0];
        maxV = max(maxV, cur);
        for (int ptr = 1; shift + ptr < A.size() && ptr < B.size(); ptr++) {
            cur = max(A[shift + ptr] * B[ptr], cur + A[shift + ptr] * B[ptr]);
            maxV = max(maxV, cur);
        }
    }
    // cout << maxV << endl;
    return maxV;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> A(n), B(m), revA, revB;

    // input
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < m; i++)
        cin >> B[i];

    // reverse
    revA = A;
    reverse(revA.begin(), revA.end());
    revB = B;
    reverse(revB.begin(), revB.end());

    int ans = INT_MIN;
    ans = max(ans, get_max_dot(A, B));
    ans = max(ans, get_max_dot(revA, B));
    ans = max(ans, get_max_dot(B, A));
    ans = max(ans, get_max_dot(B, revA));

    cout << ans << endl;
}
