#include <array>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

using Edge = pair<int, int>;  // <weight, to>
using Graph = vector<vector<Edge>>;

int n;
int answ, anslen;
Graph g;
vector<array<int, 3>> edges;  // <weight, from, to>
vector<int> dis;              // for bfs

// Disjoint Set
vector<int> par;

int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}

inline int idx(int i, int j) {
    return i * n + j;
}

void init() {
    cin >> n;
    g = Graph(n * n);

    vector<vector<int>> A(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
            if (i > 0) {
                int u = idx(i, j);
                int v = idx(i - 1, j);
                int w = abs(A[i][j] - A[i - 1][j]);
                g[u].push_back({w, v});
                g[v].push_back({w, u});
                edges.push_back({w, u, v});
            }
            if (j > 0) {
                int u = idx(i, j);
                int v = idx(i, j - 1);
                int w = abs(A[i][j] - A[i][j - 1]);
                g[u].push_back({w, v});
                g[v].push_back({w, u});
                edges.push_back({w, u, v});
            }
        }
    }
}

const int M = 1024;
vector<array<int, 3>> bucket[M];
void sortEdges() {
    // sort(edges.begin(), edges.end());

    {
        for (auto e : edges) {
            int w = e[0];
            bucket[w & 1023].push_back(e);
        }
        int pos = 0;
        for (int i = 0; i < M; i++) {
            for (auto e : bucket[i]) {
                edges[pos++] = e;
            }
        }
        for (int i = 0; i < M; i++) bucket[i].clear();
    }
    {
        for (auto e : edges) {
            int w = e[0];
            bucket[w >> 10].push_back(e);
        }
        int pos = 0;
        for (int i = 0; i < M; i++) {
            for (auto e : bucket[i]) {
                edges[pos++] = e;
            }
        }
    }
}

void kruskal() {
    par = vector<int>(n * n);
    for (int i = 0; i < n * n; i++) par[i] = i;

    int src = idx(0, 0);
    int dst = idx(n - 1, n - 1);

    for (auto [w, u, v] : edges) {
        if (find(u) != find(v)) {
            par[find(u)] = find(v);
        }
        if (find(src) == find(dst)) {
            answ = w;
            break;
        }
    }
}

void bfs() {
    dis = vector<int>(n * n, -1);

    int src = idx(0, 0);
    int dst = idx(n - 1, n - 1);

    queue<int> que;
    que.push(src);
    dis[src] = 0;
    while (dis[dst] == -1) {
        int u = que.front();
        que.pop();
        for (auto [w, v] : g[u]) {
            if (w > answ) continue;
            if (dis[v] == -1) {
                dis[v] = dis[u] + 1;
                que.push(v);
            }
        }
    }
    anslen = dis[dst];
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    init();
    sortEdges();
    kruskal();
    bfs();

    cout << answ << '\n';
    cout << anslen << '\n';

    return 0;
}
