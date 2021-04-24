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
    Node() : fail{}, cnt{0} { fill(next, next + sigma, nullptr); }
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
            ptr->cnt++;
        }
        for (int i = nodes.size() - 1; i >= 0; i--) {
            nodes[i]->fail->cnt += nodes[i]->cnt;
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
        cout << ptr->cnt << '\n';
    }

    return 0;
}
