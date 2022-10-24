#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

const int M = 100005;

vector<int> g[M];

deque<int> que;
int depth[M];

void push(int x) {
    if (depth[x] >= 39) return;
    que.push_back(x);

    int i = rand() % que.size();
    swap(que[i], que.back());
}

int pop() {
    assert(que.size() > 0);
    int x = que.front();
    que.pop_front();
    return x;
}

int root;
void dfs(int x) {
    if (x != root) cout << ' ';
    cout << x;
    if (x == 0) return;

    assert((int)g[x].size() == 2 + x % 2);
    for (int v : g[x]) {
        dfs(v);
    }
}

int main() {
    srand(clock());
    vector<int> p;
    for (int i = 1; i <= 100000; i++) p.push_back(i);

    std::random_device rd;
    std::mt19937 rg(rd());
    shuffle(p.begin(), p.end(), rg);

    depth[p[0]] = 0;
    push(p[0]);
    push(p[0]);
    if (p[0] % 2) push(p[0]);

    int n = 100000;
    for (int i = 1; i < n; i++) {
        int u = p[i];
        int par = pop();
        g[par].push_back(u);
        depth[u] = depth[par] + 1;
        // cout << "par(" << u << ")=" << par << endl;
        push(u);
        push(u);
        if (u % 2) push(u);
    }

    for (int i = 0; i < M; i++) {
        while ((int)g[i].size() < 2 + i % 2) {
            g[i].push_back(0);
        }
        shuffle(g[i].begin(), g[i].end(), rg);
    }

    root = p[0];
    dfs(root);

    return 0;
}
