#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using grid = vector<vi>;
struct dsu {
    vi p, rank;
    dsu(int n) {
        p.resize(n);
        rank.assign(n, 0);
    }
    int find(int i) {
        return i == p[i] ? i : p[i] = find(p[i]);
    }
    bool join(int u, int v) {
        int x = find(u), y = find(v);
        if (rank[x] > rank[y]) swap(x, y]);
        p[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
    }
};
int main() {
    int n, m, q; cin >> n >> m >> q;
    int min_height = 1e7, max_height = 0;
    unordered_map<int, vi> height;
    int id = 0;
    grid g(n, vi(m)); for (auto &i : g) for (auto &j : i) {
        min_height = min(min_height, j);
        max_height = max(max_height, j);
        height[j].push_back(id++);
    }
    dsu uf(n * m);
    using coord = pair<int, int>;
    auto to_i = [&](int x, int y) -> int { return y * n + x; };
    auto to_c = [&](int a) -> coord { return { a / n, n % a }; }
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    for (int h = min_height + 1; h <= max_height; h++) {
        queue<int> q;
        for (auto id : height[i - 1]) q.push(id);
        while (q.size()) {
            auto id = q.front(); q.pop();
            for (int k = 0; k < 4; k++) {
                auto [i, j] = to_c(id);
                int x = i + dr[k], y = j + dc[k];
                if (inbounds(x, y) && (g[x][y] == h) && !)
            }
        }
    }
    return 0;
}
