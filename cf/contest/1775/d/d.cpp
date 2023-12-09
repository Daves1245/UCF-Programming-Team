#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using ii = pair<ll, ll>;
#define INF 1e13
int main() {
    vector<bool> isprime(1e5, 1);
    vll primes;
    isprime[0] = isprime[1] = 0;
    for (int i = 0; i < isprime.size(); i++)
        if (isprime[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j < isprime.size(); j += i)
                isprime[j] = 0;
        }

    int n; cin >> n;
    vll v(n); for (ll &i : v) cin >> i;
    vector<vll> adj(6e5 + 10);
    unordered_map<int, int> id;

    int m = *max_element(v.begin(), v.end());
    vll dist(adj.size(), INF);
    vll prev(adj.size());

    for (int i = 0; i < n; i++) {
        ll u = v[i];
        vll f;
        for (ll d : primes) {
            if (d * d > u) break;
            if (!(u % d)) f.push_back(d);
            while (!(u % d)) u /= d;
        }
        if (u != 1) f.push_back(u);
        for (int j = 0; j < f.size(); j++) {
            ll p = n + f[j];
            adj[i].push_back(p);
            adj[p].push_back(i);
        }
    }

    /*
    for (int i = 0; i < n; i++) {
        cout << v[i] << ": ";
        for (auto u : adj[i]) cout << u - n << " "; cout << endl;
    }

    cout << "P" << endl;
    for (int i = n; i < n + m; i++) {
        if (adj[i].size()) {
            cout << i - n << ": ";
            for (auto v : adj[i]) cout << v << " "; cout << endl;
        }
    }
    */

    int p = -1;
    auto bfs = [&](int s, int e) -> void {
        using ii = pair<int, int>;
        queue<ii> q; q.push({s, 0});
        while (q.size()) {
            auto [u, d] = q.front(); q.pop();
            dist[u] = d++;
            if (u == e) return void(p = u);
            for (ll v : adj[u]) {
                if (d < dist[v]) {
                    dist[v] = d;
                    prev[v] = u;
                    q.push({v, d});
                }
            }
        }
    };

    int s, e; cin >> s >> e; s--, e--;
    /*
    if ((v[s - 1] == v[e - 1]) && (v[s - 1] == 1) && (s != e)) {
        cout << -1 << endl;
        return 0;
    }

    if (s == e) {
        cout << 1 << endl;
        cout << s << endl;
        return 0;
    }
    */

    bfs(s, e);
    /*
    cout << "dist: ";
    for (auto d : dist) cout << d << " "; cout << endl;
    */
    if (dist[e] == INF) {
        cout << -1 << endl;
        return 0;
    }
    if (s == e) {
        cout << 1 << endl;
        cout << s + 1 << endl;
        return 0;
    }

    vll ans;
    int cnt = 1;
    prev[s] = s;
    do {
        if (cnt & 1)
            ans.push_back(p + 1);
        p = prev[p];
        cnt++;
    } while (p != s);
    ans.push_back(s + 1);

    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for (auto i : ans) cout << i << " "; cout << endl;
    return 0;
}
