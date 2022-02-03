#include <bits/stdc++.h>

using namespace std;
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
    int t; cin >> t;
    while (t--) {
        int sidekicks, thugs; cin >> sidekicks >> thugs;
        vector<int> search_time(sidekicks);
        vector<vector<int>> targets(sidekicks);

        int src = 0, snk = sidekicks + thugs + 1;

        // sidekicks + thugs + source + sink
        for (int i = 0; i < sidekicks; i++) {
            cin >> search_time[i];
            int ntargets; cin >> ntargets;
            targets[i].resize(ntargets);
            for (int j = 0; j < ntargets; j++) {
                cin >> targets[i][j];
            }
        }

        ll lo = 1, hi = (ll) 1e18, mid;
        for (int i = 0; i < 70; i++) {
            mid = lo + (hi - lo) / 2;
            
            Dinic dinics(sidekicks + thugs + 2);
            for (int j = 0; j < sidekicks; j++) {
                dinics.add(src, j + 1, mid / search_time[j]);
                for (int k = 0; k < targets[j].size(); k++) {
                    dinics.add(j + 1, sidekicks + targets[j][k], 1);
                }
            }
            for (int j = 0; j < thugs; j++) {
                dinics.add(sidekicks + j + 1, snk, 1);
            }
            // set up weights
            int flow = dinics.calc(src, snk);
            if (flow < thugs) {
                lo = mid;
            } else {
                hi = mid;
            }

            /*
            cout << "flow " << flow << endl;
            cout << "thugs " << thugs << endl;
            cout << "time " << mid << endl;
            */
        }

        cout << mid + 1 << endl;

    }
    return 0;
}

