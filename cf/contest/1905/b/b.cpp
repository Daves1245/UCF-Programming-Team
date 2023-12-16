#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v; u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int leaves = 0;
        vector<int> seen(n, 0);
        auto dfs = [&](auto &&self, int u) -> void {
            seen[u] = 1;
            int leaf = 1;
            for (auto v : adj[u])
                if (!seen[v]) {
                    leaf = 0;
                    self(self, v);
                }
            if (leaf) leaves++;
        };

        dfs(dfs, 0);
        cout << max(1, (leaves + 1 + (adj[0].size() == 1)) / 2) << endl;
    }

    return 0;
}
