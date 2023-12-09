#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define inbounds(x, y) ((x >= 0) && (x < n) && (y >= 0) && (y < m))
int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<string> g(n); for (auto &i : g) cin >> i;
        /*
        auto bfs_end = [&](int i, int j) -> grid {
            using st = tuple<int, int, int>;
            grid dist = grid(n, vi(m, -1));
            queue<st> q;
            q.push({i, j, 0});
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};
            while (q.size()) {
                auto [i, j, d] = q.front(); q.pop();
                if (!inbounds(i, j) || (g[i][j] == '#') || (dist[i][j] != -1)) continue;
                dist[i][j] = d;
                for (int k = 0; k < 4; k++) {
                    int x = i + dr[k], y = j + dc[k];
                    if (!inbounds(x, y) || (g[x][y] == '#') || (dist[x][y] != -1)) continue;
                    q.push({x, y, d + 1});
                }
            }
            return dist;
        };
        */
        constexpr int INF = 1e6;
        using st = tuple<int, int, int>;
        using grid = vector<vi>;
        auto ms_bfs = [&](vector<pair<int, int>> &start) -> grid {
            grid dist = grid(n, vi(m, INF));
            queue<st> q;
            for (auto [i, j] : start) q.push({i, j, 0});
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            while (q.size()) {
                auto [i, j, d] = q.front(); q.pop();
                if (!inbounds(i, j) || (g[i][j] == '#') || (dist[i][j] != INF)) continue;
                dist[i][j] = d;
                for (int k = 0; k < 4; k++) {
                    int x = i + dr[k], y = j + dc[k];
                    if (!inbounds(x, y) || (g[x][y] == '#')) continue;
                    q.push({x, y, d + 1});
                }
            }
            return dist;
        };

        auto bfs_conflict = [&](int i, int j, grid &conflict) -> bool {
            using st = tuple<int, int, int>;
            queue<st> q; q.push({i, j, 0});
            auto dist = grid(n, vi(m, INF));
            while (q.size()) {
                auto [i, j, d] = q.front(); q.pop();
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                while (q.size()) {
                    auto [i, j, d] = q.front(); q.pop();
                    if (!inbounds(i, j) || (g[i][j] == '#') || (dist[i][j] != INF) || (conflict[i][j] <= d)) continue;
                    dist[i][j] = d;
                    for (int k = 0; k < 4; k++) {
                        int x = i + dr[k], y = j + dc[k];
                        if (!inbounds(x, y) || (g[x][y] == '#')) continue;
                        q.push({x, y, d + 1});
                    }
                }
            }
            return dist[n - 1][m - 1] < min(INF, conflict[n - 1][m - 1]);
        };

        vector<pair<int, int>> bad_start;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 'B') bad_start.push_back({i, j});
            }
        }
        auto bad = ms_bfs(bad_start);
        bool f = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 'G') f &= bfs_conflict(i, j, bad);
            }
        }

        cout << (f ? "Yes" : "No") << endl;
        /*
           auto bfs_conflict = [&](vector<pair<int, int>> &start) -> bool {
           using st = tuple<int, int, int>;
           grid dist = grid(n, vi(m, -1));
           queue<st> q;
           for (auto [i, j] : start) q.push({i, j, 0});
           int dr[] = {-1, 0, 1, 0};
           int dc[] = {0, 1, 0, -1};
           while (q.size()) {
           auto [i, j, d] = q.front(); q.pop();
           if (!inbounds(i, j) || (g[i][j] == '#') || (dist[i][j] != -1)) continue;
           dist[i][j] = d;
           if ((g[i][j] == 'B') && (d <= 1)) return 1;
           }
           return 0;
           };
           auto d = bfs_end(n - 1, m - 1);
           vi gd, bd;
           for (int i = 0; i < n; i++) {
           for (int j = 0; j < m; j++) {
           if (g[i][j] == 'B') bd.push_back(d[i][j]);
           if (g[i][j] == 'G') gd.push_back(d[i][j]);
           }
           }

           sort(bd.begin(), bd.end());
           sort(gd.begin(), gd.end());

        /*
        for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
        cout << d[i][j] << " ";
        }
        cout << endl;
        }
        cout << "B ";
        for (auto i : bd) cout << i << " "; cout << endl;
        cout << "G ";
        for (auto i : gd) cout << i << " "; cout << endl;
        int bn = bd.size();
        auto inbounds = [&](int i, int j) 
        -> bool { return (i >= 0) && (i < n) && (j >= 0) && (j < m); };
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        bool f = 1;
        bool necessary = false;
        for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
        necessary |= g[i][j] == 'G';
        if ((g[i][j] == 'G') || ((i == n - 1) && (j == m - 1) && necessary)) {
        for (int k = 0; k < 4; k++) {
        int x = i + dr[k], y = j + dc[k];
        if (!inbounds(x, y)) continue;
        f &= g[x][y] != 'B';
        }
        }
        }
        }

        if (gd.size()) for (auto i : gd) f &= i >= 0;
        cout << (f ? "Yes" : "No") << endl;
        */
    }
    return 0;
}
