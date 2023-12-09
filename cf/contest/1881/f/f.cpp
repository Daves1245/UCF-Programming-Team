#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<vector<int>> adj(n);
        vector<int> red(n), reds;
        vector<int> depth(n);
        for (int i = 0; i < k; i++) {
            int u; cin >> u; u--;
            reds.push_back(u);
            red[u] = 1;
        }
        for (int i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v; u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if (k == 1) {
            cout << 0 << endl;
            continue;
        }

        vector<int> seen(n, 0);
        auto dfs = [&](auto &&self, int u, int d = 0) -> void {
            seen[u] = 1;
            depth[u] = (red[u] ? d : 0);
            for (auto v : adj[u]) if (!seen[v]) self(self, v, d + 1);
        };

        dfs(dfs, reds[0]);

        int i = max_element(depth.begin(), depth.end()) - depth.begin();

        seen = depth = vector<int>(n, 0);
        dfs(dfs, i);

        cout << (*max_element(depth.begin(), depth.end()) + 1) / 2 << endl;
    }
    return 0;
}
