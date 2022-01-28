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

#define MAX_LEN 500 * 1000 + 10 

struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
        Edge(int tt, int rr, ll cc, ll oo){
            to = tt; rev = rr; c = cc; oc = oo;
        }
	};

    // modifying Dinic's, just to spite Tyler.
    vector<vector<int>> ans;
    // 0 1 2 3 4 5
    // 0 3 9 1 2 5
    // 0
    vector<int> path;

	vector<int> lvl, ptr, q;

	vector<vector<Edge>> adj;
    vector<bool> visited;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n), visited(n){}
	void add(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back(Edge((ll)b, adj[b].size(), c, c));
		adj[b].push_back({a, (int)adj[a].size() - 1, rcap, rcap});
	}

    ll dfs(int v, int t, ll f) {
        if (v == t || !f) {
            return f;
        }

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


    void __dfs(int v, int t, int i) {
        path.push_back(v + 1);
        i++;
        if (v == t) {
            ans.push_back(path);
            path = vector<int>();
            return;
        }

        visited[v] = true;
        for (auto &e : adj[v]) {
            if (!visited[e.to] && e.c >= 0) {
                __dfs(e.to, t, i);
            } 
        }
        visited[v] = false;
        i--;
        path.resize(i);
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

    Dinic dinics(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        dinics.add(u, v, 1);
    }

    int ans = dinics.calc(0, n - 1);
    dinics.__dfs(0, n - 1, 0);
    cout << ans << endl;
    for (auto &s : dinics.ans) {
        cout << s.size() << endl;
        for (auto &i : s) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}

