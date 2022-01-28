/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * Description: Compute maximum flow in a graph. The basic principle is that a Maximum flow = minimum cut and Breadth First Search is used as a sub-routine.
 * Time: $O(EV^2)$
 * Memory: $O(E + V)$
 */

using ll = long long;

struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
        Edge(int tt, int rr, ll cc, ll oo){
            to = tt; rev = rr; c = cc; oc = oo;
        }
	};
	vector<int> lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void add(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back(Edge((ll)b, adj[b].size(), c, c));
		adj[b].push_back({a, (int)adj[a].size() - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < adj[v].size(); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {        
		ll flow = 0; q[0] = s;
		for(int L = 0; L < 31; L++) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vector<int>(q.size());
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

int main() {
    int n, m; cin >> n >> m;
    Dinic dinic(n);
    set<pair<int, int>> seen;
    for (int i = 0; i < m; i++) {
        int u, v, c; cin >> u >> v >> c;
        u--;
        v--;
        dinic.add(u, v, c);
    }

    cout << dinic.calc(0, n - 1) << endl;
    return 0;
}
