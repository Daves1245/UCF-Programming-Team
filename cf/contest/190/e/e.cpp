#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using st = set<pair<int,int>>;
vll seen;
st adj;
set<int> tovisit;
int id;
struct ufds {
    vll p, rank;
    int find(int i) { return p[i] == i ? i : p[i] = find(p[i]); }
    bool join(int i, int j) {
        int x = find(i), y = find(j);
        if (x == y) return false;
        if (rank[x] > rank[y]) swap(x, y);
        p[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
        return true;
    }
    ufds(int n) {
        p.assign(n, 0);
        rank.assign(n, 0);
        for (int i = 0; i < n; i++) {
            p[i] = i;
            rank[i] = 0;
        }
    }
};
void dfs(int u) {
    seen[u] = id;
    vll next;
    for (auto v : tovisit) {
        cout << "v " << v << endl;
        if (!seen[v] && !adj.count({u, v})) {
            next.push_back(v);
        }
    }
    for (auto v : next) tovisit.erase(v);
    for (auto v : next) dfs(v);
}
int main() {
    int n, m; cin >> n >> m;
    seen = vll(n, false);
    for (int i = 0; i < n; i++) tovisit.insert(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj.insert({u, v});
        adj.insert({v, u});
    }
    ufds dsu(n);
    for (int u = 0; u < n; u++) {
        if (!seen[u]) {
            id++;
            dfs(u);
        }
    }
    vector<vll> ans(n);
    for (int u = 0; u < n; u++) {
        ans[seen[u]].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        if (ans[i].size()) {
            cout << ans[i].size() << " ";
            for (auto u : ans[i]) cout << u << " ";
            cout << endl;
        }
    }
    return 0;
}
