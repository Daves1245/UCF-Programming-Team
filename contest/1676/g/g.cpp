#include <bits/stdc++.h>

using namespace std;

using vii = vector<pair<int, int>>;
using ll = long long;
using ii = pair<int, int>;

ll dfs(vector<vii> &adj, int u, int k) {
    int c = 0;
    for (auto [v, co] : adj[u]) {
        if (co == k) c++;
        c += dfs(adj, v, co);
    }
    return c;
}

ll solve(vector<vii> &adj) {
    ll ret = 0;
    for (int i = 0; i < adj.size(); i++) {
        ll white = dfs(adj, i, 0);
        ll black = dfs(adj, i, 1);
        if (white == black) ret++;
    }
    return ret;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vii> adj(n);
        vii info(n);
        for (int i = 0; i < n; i++) {
            int tmp; cin >> tmp;
            info[i].first = tmp;
        }
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            info[i].second = s == "B";
        }

        for (int i = 0; i < n; i++) {
            adj[info[i].first].push_back(ii(info[i].first, info[i].second));
        }

        cout << solve(adj) << endl;
    }
    return 0;
}

