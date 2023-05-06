#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MAXV = 100'000'000'000'000'000;

ll eval(const string &expr, int l, int r) {
    if (l == r) return 0;

    // split *
    {
        int bracket = 0;
        for (int i = l; i < r; i++) {
            if (expr[i] == '(')
                bracket++;
            else if (expr[i] == ')')
                bracket--;

            if (bracket != 0) continue;

            if (expr[i] == '*') {
                auto ret = 1.0 * eval(expr, l, i) * eval(expr, i + 1, r);
                assert(ret <= MAXV);
                return ret;
            }
        }
    }
    // split +
    {
        int bracket = 0;
        for (int i = l; i < r; i++) {
            if (expr[i] == '(')
                bracket++;
            else if (expr[i] == ')')
                bracket--;

            if (bracket != 0) continue;

            if (expr[i] == '+') {
                auto ret = eval(expr, l, i) + eval(expr, i + 1, r);
                assert(ret <= MAXV);
                return ret;
            }
        }
    }

    if (expr[l] != 'f') return stoi(expr.substr(l, r - l));

    assert(expr[l] == 'f');
    assert(expr[l + 1] == '(');
    assert(expr[r - 1] == ')');

    auto split = vector<int>{l + 1};
    int bracket = 0;
    for (int i = l; i < r; i++) {
        if (expr[i] == '(')
            bracket++;
        else if (expr[i] == ')')
            bracket--;

        if (bracket != 1) continue;
        if (expr[i] == ',') split.emplace_back(i);
    }
    split.emplace_back(r - 1);
    auto val = vector<ll>{};
    for (int i = 1; i < split.size(); i++) {
        val.emplace_back(eval(expr, split[i - 1] + 1, split[i]));
        assert(val.back() <= MAXV);
    }

    return *max_element(val.begin(), val.end()) -
           *min_element(val.begin(), val.end());
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string expr;
    cin >> expr;
    assert(expr.size() <= 500);

    std::cout << eval(expr, 0, expr.size()) << '\n';
}
