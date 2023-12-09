#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vi> v(n, vi(5));
        for (auto &i : v) for (auto &j : i) cin >> j;

        auto wins = [&](vi &a, vi &b) -> bool {
            int cnt = 0;
            for (int i = 0; i < 5; i++) cnt += a[i] < b[i];
            return cnt >= 3;
        };

        auto mx = v[0];
        int mi = 0;
        for (int i = 0; i < n; i++) {
            if (wins(v[i], mx)) {
                mx = v[i];
                mi = i;
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += wins(mx, v[i]);
        }

        cout << (cnt == n - 1 ? mi + 1 : -1) << endl;
    }
    return 0;
}
