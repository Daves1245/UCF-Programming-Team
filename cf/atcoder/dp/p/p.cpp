#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using ll = long long;
using vll = vector<ll>;
constexpr int M = 1e9 + 7;
int main() {
    int n; cin >> n;
    vector<vll> adj(n);
    vector<vector<ll>> dp(n, vll(2, 1));
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vll seen(n, 0);
    auto dfs = [&](auto &&self, int u) -> void {
        seen[u] = 1;
        for (auto v : adj[u]) {
            if (seen[v]) continue;
            self(self, v);

            dp[u][0] = (dp[u][0] * (dp[v][0] + dp[v][1])) % M;
            dp[u][1] = (dp[u][1] * dp[v][0]) % M;
        }
    };

    dfs(dfs, 0);

    cout << (dp[0][0] + dp[0][1]) % M << endl;
    return 0;
}
