#include <bits/stdc++.h>

using namespace std;

using vii = vector<pair<int, int>>;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<ll>;

constexpr ll INF = (ll) 1e13;

vi dijkstra(int s, vector<vii> &adjlist) {
    vi dist(adjlist.size(), INF);
    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq; pq.push({dist[s], s});
    while (pq.size()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adjlist[u]) {
            if (d + w >= dist[v]) continue;
            dist[v] = d + w;
            pq.push({dist[v], v});
        }
    }

    return dist;
}

int main() {
    int t; cin >> t;

    while (t--) {
        int n, m, k; cin >> n >> m >> k;

        k++;
        vector<vii> adjlist(n);
        vector<vector<ll>> reduced(k, vector<ll>(k));
        vi friends(k);

        int s = 0;
        friends[0] = s;
        for (int i = 1; i < k; i++) {
            cin >> friends[i];
            friends[i]--;
        }

        for (int i = 0; i < m; i++) {
            int u, v, w; cin >> u >> v >> w;
            u--, v--;
            adjlist[u].push_back(make_pair(v, w));
            adjlist[v].push_back(make_pair(u, w));
        }

        for (int i = 0; i < k; i++) {
            vi tmp = dijkstra(friends[i], adjlist);
            for (int j = 0; j < friends.size(); j++) {
                reduced[i][j] = tmp[friends[j]];
            }
        }

         /*
        cout << "reduced: " << endl;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                cout << reduced[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
         */

        // dp[currNode][mask]
        int max_mask = (1 << k) - 1;
        vector<vector<ll>> dp(k, vector<ll>(max_mask + 1, INF));
        dp[s][(1 << s)] = 0;
        for (int mask = 0; mask <= max_mask; mask++) {
            for (int curr = 0; curr < k; curr++) {
                if ((mask & (1 << curr)) == 0) continue;
                for (int next = 0; next < k; next++) {
                    if ((mask & (1 << next)) > 0) continue;
                    auto &state = dp[next][mask | (1 << next)];
                    state = min(state, dp[curr][mask] + reduced[curr][next]);
                    /*
                    cout << "next " << next << endl;
                    cout << "curr " << curr << endl;
                    cout << "mask " << mask << endl;
                    */
                }
            }
        }

        /*
        cout << "dp: " << endl;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j <= max_mask; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        cout << "end" << endl;
        */

        ll ans = INF;
        for (int i = 0; i < k; i++) {
            ans = min(ans, dp[i][max_mask] + reduced[i][s]);
            // cout << dp[i][max_mask] << " ";
        }

        cout << ans << endl;
    }

    return 0;
}
