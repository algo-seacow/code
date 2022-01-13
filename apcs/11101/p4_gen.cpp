#include<iostream>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("18.in", "w", stdout);
    int n, k;
    //cin >> n >> k;
    n = 1LL * rand() * rand() % 200000 + 1; k = 5000;
    cout << n << ' ' << k << '\n';
    for (int i = 0 ; i < n ; i++) {
        cout << rand() + 1 <<' ';
    }
    cout << '\n';
    for (int i = 0 ; i < k ; i++) {
        cout << rand() % (n / k) + 1<<' ';
    }
    cout << '\n';
}