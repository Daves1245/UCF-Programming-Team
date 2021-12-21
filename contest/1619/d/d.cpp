#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<long long>> v(n, vector<long long>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> v[i][j];
            }
        }

        auto possible = [&](long long cutoff) -> bool {
            vector<bool> columns(m, false);

            bool has_pair = false;
            for (int i = 0; i < n; i++) {
                int row_count = 0;
                for (int j = 0; j < m; j++) {
                    columns[j] = columns[j] || v[i][j] >= cutoff;
                    row_count += v[i][j] >= cutoff;
                }
                has_pair = has_pair || row_count >= 2;
            }
            return has_pair && all_of(columns.begin(), columns.end(), [](bool x) { return x; });
        };

        long long lo = 0, hi = 1'000'000'000;
        while (lo < hi) {
            long long mid = lo + (hi - lo + 1) / 2;
            if (possible(mid)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
            // cout << lo << " " << mid << " " << hi << '\n';
        }

        cout << lo << '\n';
    }
    return 0;
}

