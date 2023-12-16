#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
int main() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n, 0);
    vector<int> seen(n, 0);
    auto dfs = [&](auto &&self, int u, int d, vector<int> &depth) -> void {
        seen[u] = 1;
        depth[u] = d;
        for (auto v : adj[u]) if (!seen[v]) self(self, v, d + 1, depth);
    };

    dfs(dfs, 0, 0, dist);
    auto i = max_element(dist.begin(), dist.end()) - dist.begin();
    seen = vector<int>(n, 0);
    vector<int> dist2(n, 0);
    dfs(dfs, i, 0, dist2);
    i = max_element(dist2.begin(), dist2.end()) - dist2.begin();
    seen = vector<int>(n, 0);
    dfs(dfs, i, 0, dist);

    vector<int> max_dist(n);
    vector<int> cnt(n, 0);
    for (int i = 0; i < n; i++) {
        max_dist[i] = max(dist[i], dist2[i]);
        cnt[max_dist[i] - 1]++;
    }

    for (int i = n - 2; i >= 0; i--) cnt[i] += cnt[i + 1];
    for (auto i : cnt) cout << min(n, n - i + 1) << " "; cout << endl;
    return 0;
}
