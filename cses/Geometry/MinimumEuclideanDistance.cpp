#include <bits/stdc++.h>
using namespace std;

using Point = pair<long long, long long>;
#define x first
#define y second

long long sqr(long long x) {
    return x * x;
}
Point operator-(const Point &a, const Point &b) {
    return {a.x - b.x, a.y - b.y};
}
long long dot(Point u, Point v) {
    return u.x * v.x + u.y * v.y;
}
long long cross(Point u, Point v) {
    return u.x * v.y - u.y * v.x;
}
long long len2(Point u, Point v) {
    return dot(u - v, u - v);
}

long long ClosestDistance(vector<Point> p) {
    int n = p.size();
    sort(p.begin(), p.end(), [](Point a, Point b) {
        if (a.y != b.y) return a.y < b.y;
        return a.x < b.x;
    });
    set<Point> S;
    long long D2 = 8e18;
    for (int l = 0, r = 0; r < n; r++) {
        while (l < r && sqr(p[r].x - p[l].x) > D2) {
            S.erase({p[l].x, p[l].y});
            l++;
        }
        Point now = p[r];
        auto it = S.lower_bound(now);
        for (int i = 0; i < 4; i++) {
            if (it == S.end()) break;
            D2 = min(D2, len2(now, *it));
            it++;
        }
        it = S.lower_bound(now);
        for (int i = 0; i < 4; i++) {
            if (it == S.begin()) break;
            it--;
            D2 = min(D2, len2(now, *it));
        }
        S.insert(now);
    }
    return D2;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    long long ans = ClosestDistance(points);
    cout << ans << '\n';
    return 0;
}
