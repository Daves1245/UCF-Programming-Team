/*
 * FML list
 *
 * 1. Breathe
 * 2. Clear data structures after every iteration
 * 3. Iterate desired amount
 * 4. git gud scrub
 * 5. check array types
 * 6.5 change 5s to 6s
 * 7. check signs
 * 8. check epsilon
 * 9. don't be a dumbass
 * 11. there is no #10
 * 12. there is no hope
 * 13. hopefully you fixed it by now because this is the end
 */

#include <bits/stdc++.h>
using ll = long long;
using namespace std;
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
    int t; cin >> t;
    while (t--) {
        string red, green; cin >> red >> green;
        int s = 0, t = red.size() + green.size() + 1;
        Dinic dinic(t + 1);
        for (int i = 0; i < red.size(); i++) {
            dinic.add(s, i + 1, 1);
            for (int j = 0; j < green.size(); j++) {
                if (abs(red[i] - green[j]) >= 3) {
                    dinic.add(i + 1, red.size() + j + 1, 1);
                }
            }
        }
        for (int j = 0; j < green.size(); j++) {
            dinic.add(red.size() + j + 1, t, 1);
        }

        cout << dinic.calc(s, t) << endl;
    }
    return 0;
}

