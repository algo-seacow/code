#include <bits/stdc++.h>
using namespace std;

using Point = pair<long long, long long>;
#define x first
#define y second

Point operator-(const Point &a, const Point &b) {
    return {a.x - b.x, a.y - b.y};
}

long long dot(Point u, Point v) {
    return u.x * v.x + u.y * v.y;
}
long long cross(Point u, Point v) {
    return u.x * v.y - u.y * v.x;
}
int sign(long long x) {
    if (x < 0) {
        return -1;
    } else if (x == 0) {
        return 0;
    } else {
        return 1;
    }
}

bool onseg(Point a, Point b, Point c) {
    if (cross(b - a, c - a) != 0) return false;
    if (sign(dot(b - a, c - a)) < 0) return false;
    if (sign(dot(a - b, c - b)) < 0) return false;
    return true;
}

bool intersection(Point a, Point b, Point c, Point d) {
    int c1 = sign(cross(b - a, c - a)) * sign(cross(b - a, d - a));
    int c2 = sign(cross(d - c, a - c)) * sign(cross(d - c, b - c));
    if (c1 == 1 || c2 == 1) return false;
    if (c1 < 0 && c2 < 0) return true;
    if (onseg(a, b, c)) return true;
    if (onseg(a, b, d)) return true;
    if (onseg(c, d, a)) return true;
    if (onseg(c, d, b)) return true;
    return false;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        Point a, b, c, d;
        cin >> a.x >> a.y;
        cin >> b.x >> b.y;
        cin >> c.x >> c.y;
        cin >> d.x >> d.y;
        bool ans = intersection(a, b, c, d);
        cout << (ans ? "YES" : "NO") << '\n';
    }
}
