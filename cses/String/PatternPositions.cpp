#include <bits/stdc++.h>
using namespace std;

// remember make_fail() !!!
// notice MLE

const int sigma = 26;
const int MAXC = 500005;

inline int idx(char c) { return c - 'a'; }

struct Node {
    Node *next[sigma], *fail;
    int cnt;  // dp
    int len;
    Node() : fail{}, cnt{INT_MAX}, len{} { fill(next, next + sigma, nullptr); }
};

struct ACautomaton {
    Node buf[MAXC], *bufp, *ori, *root;
    vector<Node *> nodes;

    ACautomaton() {
        bufp = buf;
        ori = new (bufp++) Node();
        root = new (bufp++) Node();
    }

    Node *insert(const string &s) {
        Node *ptr = root;
        for (int i = 0; i < (int)s.size(); i++) {
            int c = idx(s[i]);
            if (ptr->next[c] == nullptr) ptr->next[c] = new (bufp++) Node();
            ptr = ptr->next[c];
            ptr->len = i + 1;
        }
        return ptr;
    }

    Node *trans(Node *o, int c) {
        if (o->next[c]) return o->next[c];
        return o->next[c] = trans(o->fail, c);
    }

    void make_fail() {
        queue<Node *> que;

        for (int i = 0; i < sigma; i++) ori->next[i] = root;
        root->fail = ori;

        que.push(root);
        while (que.size()) {
            Node *u = que.front();
            nodes.push_back(u);
            que.pop();
            for (int i = 0; i < sigma; i++) {
                if (!u->next[i]) continue;
                u->next[i]->fail = trans(u->fail, i);
                que.push(u->next[i]);
            }
        }
    }

    void make_dp(const string &s) {
        Node *ptr = root;
        for (int i = 0; i < (int)s.size(); i++) {
            int c = idx(s[i]);
            ptr = trans(ptr, c);
            ptr->cnt = min(ptr->cnt, i + 1 - ptr->len + 1);
        }
        for (int i = nodes.size() - 1; i >= 0; i--) {
            if (nodes[i]->cnt == INT_MAX) continue;
            Node *f = nodes[i]->fail;
            f->cnt = min(f->cnt, nodes[i]->cnt + nodes[i]->len - f->len);
        }
    }
} ac;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    string s;
    cin >> s;

    int k;
    cin >> k;
    vector<Node *> ptrs;
    for (int i = 0; i < k; i++) {
        string p;
        cin >> p;
        ptrs.push_back(ac.insert(p));
    }
    ac.make_fail();
    ac.make_dp(s);
    for (Node *ptr : ptrs) {
        if (ptr->cnt == INT_MAX) {
            cout << -1 << '\n';
        } else {
            cout << ptr->cnt << '\n';
        }
    }

    return 0;
}
