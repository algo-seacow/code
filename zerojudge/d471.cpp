#include <bits/stdc++.h>
using namespace std;

int n;
string s;

void print_all(int top) {
    if (top == n) {
        cout << s << '\n';
    } else {
        s[top] = '0';
        print_all(top + 1);
        s[top] = '1';
        print_all(top + 1);
    }
}

int main() {
    while (cin >> n) {
        s.resize(n);
        print_all(0);
    }
    return 0;
}
