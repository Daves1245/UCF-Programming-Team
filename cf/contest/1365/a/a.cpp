#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m));
        for (auto &i : v) for (auto &j : i) cin >> j;
        auto inbounds = [&](int i, int j) -> bool {
            return (i >= 0) && (i < n) && (j >= 0) && (j < m);
        };
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bool f = true;
                for (int k = 0; k < n; k++) f &= !v[k][j];
                for (int k = 0; k < m; k++) f &= !v[i][k];
                cnt += f;
                if (f) v[i][j] = 1;
            }
        }
        cout << ((cnt % 2) ? "Ashish" : "Vivek") << endl;
    }
    return 0;
}
