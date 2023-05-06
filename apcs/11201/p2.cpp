#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int K, Q, R;
    string s;
    vector<string> tmps;

    cin >> K >> Q >> R;
    cin >> s;
    for (int i = 0; i < Q; i++) {
        string tmp(K, ' ');
        for (int j = 0; j < K; j++) {
            int pos;
            cin >> pos;
            tmp[pos - 1] = s[j];
        }
        tmps.push_back(tmp);
        s = tmp;
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < Q; j++) {
            cout << tmps[j][i];
        }
        cout << '\n';
    }

    return 0;
}
