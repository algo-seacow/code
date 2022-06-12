#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[3];

    cin >> a[0];
    cin >> a[1];
    cin >> a[2];

    sort(a, a + 3);

    // calculate P
    int P = 1;
    if (a[0] == a[1] || a[1] == a[2]) {
        P = 2;
    }
    if (a[0] == a[1] && a[1] == a[2]) {
        P = 3;
    }

    cout << P;

    // calculate S
    cout << ' ' << a[2];
    if (a[1] != a[2]) cout << ' ' << a[1];
    if (a[0] != a[1]) cout << ' ' << a[0];
    cout << endl;
}
