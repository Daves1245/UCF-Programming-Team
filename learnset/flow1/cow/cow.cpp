#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;
using ll = long long;
using point = pair<ii, ii>;

#define xx first
#define yy second
#define initial first
#define terminal second

void print(point &a) {
    cout << "P{(" << a.initial.xx << ", " << a.initial.yy << "), (" << 
        a.terminal.xx << ", " << a.terminal.yy << ")}" << endl;
}

bool intersecting(point &a, point &b) {
    point &horizontal = (a.initial.xx == a.terminal.yy) ? a : b;
    point &vertical = (a.initial.xx == a.terminal.yy) ? b : a;
    if (horizontal.terminal < horizontal.initial) swap(horizontal.initial, horizontal.terminal);
    if (vertical.terminal.yy > vertical.initial.yy) swap(vertical.initial, vertical.terminal);
    /*
    cout << "Horizontal point is ";
    print(horizontal);
    cout << "Vertical point is ";
    print(vertical);
    cout << "HIx <= VIx ? " << (horizontal.initial.xx <= vertical.initial.xx) << endl;
    cout << "VIx <= HTx ? " << (vertical.initial.xx <= horizontal.terminal.xx) << endl;
    cout << "VIy >= HIy ? " << (vertical.initial.yy >= horizontal.initial.yy) << endl;
    cout << "VTy <= HIy ? " << (vertical.terminal.yy <= horizontal.initial.yy) << endl;
    */
    return horizontal.initial.xx <= vertical.initial.xx &&
        vertical.initial.xx <= horizontal.terminal.xx &&
        vertical.initial.yy >= horizontal.initial.yy &&
        vertical.terminal.yy <= horizontal.initial.yy;
}

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
        vector<point> horizontal, vertical;
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            int a, b, c, d; cin >> a >> b >> c >> d;
            point p = {{a, b}, {c, d}};
            if (a == c)
                horizontal.push_back(p);
            else
                vertical.push_back(p);
        }
        Dinic dinics(n + 2);
        int s = 0, t = horizontal.size() + vertical.size() + 1;
        for (int i = 0; i < horizontal.size(); i++) {
            dinics.add(s, i + 1, 1);
//            print(horizontal[i]);
            for (int j = 0; j < vertical.size(); j++) {
                print(vertical[j]);
                cout << "intersect? " << intersecting(horizontal[i], vertical[j]) << endl;
                if (!intersecting(horizontal[i], vertical[j])) {
                    cout << i << " and " << j << " don't intersect! constructing an edge of 1" << endl;
                    dinics.add(i + 1, horizontal.size() + j + 1, 1);
                    // dinics.add(horizontal.size() + j + 1, i + 1, 1);
                } else {
                    dinics.add(i + 1, t, 1);
                    dinics.add(horizontal.size() + j + 1, t, 1);
                }
            }
        }
        for (int j = 0; j < vertical.size(); j++) {
            dinics.add(horizontal.size() + j + 1, t, 1);
        }

        cout << dinics.calc(s, t) << endl;
    }
    return 0;
}

