#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/**
 * Author: chilli, pajenegod
 * Date: 2020-02-20
 * License: CC0
 * Source: Folklore
 * Description: Data structure for computing lowest common ancestors in a tree
 * (with 0 as root). C should be an adjacency list of the tree, either directed
 * or undirected.
 * Time: $O(N \log N + Q)$
 * Status: stress-tested
 */

/**
 * Author: Johan Sannemo, pajenegod
 * Date: 2015-02-06
 * License: CC0
 * Source: Folklore
 * Description: Range Minimum Queries on an array. Returns
 * min(V[a], V[a + 1], ... V[b - 1]) in constant time.
 * Usage:
 *  RMQ rmq(values);
 *  rmq.query(inclusive, exclusive);
 * Time: $O(|V| \log |V| + Q)$
 * Status: stress-tested
 */

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

struct LCA {
	int T = 0;
	vi time, path, ret;
	RMQ<int> rmq;
	LCA(vector<vi>& C) : time(sz(C)), rmq((dfs(C,0,-1), ret)) {}
	void dfs(vector<vi>& C, int v, int par) {
		time[v] = T++;
		for (int y : C[v]) if (y != par) {
			path.push_back(v), ret.push_back(time[v]);
			dfs(C, y, v);
		}
	}

	int lca(int a, int b) {
		if (a == b) return a;
		tie(a, b) = minmax(time[a], time[b]);
		return path[rmq.query(a, b)];
	}
	// int dist(int a, int b){return depth[a] + depth[b] - 2 * depth[lca(a,b)];}
};
int main() {
    int n, q; cin >> n >> q;
    vector<vi> adj(n);
    vector<int> red(n, 0), dist(n, 0), depth(n, 0);
    red[0] = 1;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi seen(n, 0);
    auto dfs = [&](auto &&self, int u = 0, int d = 0) -> void {
        seen[u] = 1;
        depth[u] = d;
        for (auto v : adj[u]) if (!seen[v]) self(self, v, d + 1);
    };

    dfs(dfs);
    auto bfs = [&](vi &s) -> void {
        using st = pair<int, int>;
        queue<st> q;
        for (auto u : s) q.push({u, 0});
        vi seen(n, 0);
        while (q.size()) {
            auto [u, d] = q.front(); q.pop();
            if (seen[u]) continue;
            seen[u] = 1;
            dist[u] = d; 
            for (auto v : adj[u]) if (!seen[v]) q.push({v, d + 1});
        }
    };

    auto process = [&]() -> void {
        vi start;
        for (int u = 0; u < n; u++) {
            if (red[u]) start.push_back(u);
        }

        bfs(start);
    };

    LCA lca(adj);

    int del = sqrt(q);
    int i = 0;
    process();

    vi buck;
    while (q--) {
        if (++i >= del) {
            process();
            i = 0;
            buck = vi();
        }
        int t, v; cin >> t >> v; v--;
        if (t == 1) {
            red[v] = 1;
            buck.push_back(v);
        } else {
            int &ret = dist[v];
            for (auto u : buck) {
                ret = min(ret, depth[u] + depth[v] - 2 * depth[lca.lca(u, v)]);
            }
            cout << ret << endl;
        }
    }
    return 0;
}
