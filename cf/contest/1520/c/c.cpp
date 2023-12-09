#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n == 2) {
            cout << -1 << endl;
            continue;
        }
        vector<vector<int>> g(n, vector<int>(n));
        int k = 0, v = 1;
        auto toc = [&](int k) -> pair<int, int> { return {k / n, k % n}; };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                auto [x, y] = toc(k);
                g[x][y] = v;
                k += 2;
                if (k >= n * n) k = 1;
                v++;
            }
        }
        for (auto &i : g) { for (auto j : i) cout << j << " "; cout << endl; }
    }
    return 0;
}
