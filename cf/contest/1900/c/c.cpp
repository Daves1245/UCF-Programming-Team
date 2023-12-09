#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; getline(cin, s); cin >> s;
        vector<vector<int>> adj(n);
        set<int> children;
        for (int i = 0; i < n; i++) {
            int l, r; cin >> l >> r;
            adj[i].push_back(l);
            adj[i].push_back(r);
            if (!l && !r) children.insert(i);
        }

        auto dfs = [&](auto &&self, int u, int c) -> int {
            if (!u) return INT_MAX;
            u--;
            if (children.count(u)) return c;
            return min(self(self, adj[u][0], c + (s[u] != 'L')), self(self, adj[u][1], c + (s[u] != 'R')));
        };

        cout << dfs(dfs, 1, 0) << endl;
    }

    return 0;
}
