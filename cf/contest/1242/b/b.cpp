#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
set<pair<int,int>> adj;
vector<int> seen;
int n;
void bfs(int s) {
    seen[s] = true;
    queue<int> q;
    set<int> tovisit;
    for (int i = 0; i < n; i++) {
        tovisit.insert(i);
    }
    q.push(s);
    while (q.size()) {
        auto u = q.front(); q.pop();
        seen[u] = true;
        vector<int> toremove;
        for (auto v : tovisit) {
            if (!seen[v])
                if (!adj.count({u, v}) && !adj.count({v, u})) {
                    q.push(v);
                    toremove.push_back(v);
                }
        }
        for (auto u : toremove) {
            tovisit.erase((int) u);
        }
    }
}
int main() {
    int m; cin >> n >> m;
    seen = vector<int>(n, false);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj.insert({u, v});
    }
    int cc = 0;
    for (int u = 0; u < n; u++) {
        if (!seen[u]) {
            cc++;
            bfs(u);
        }
    }
    cout << cc - 1 << endl;
    return 0;
}
