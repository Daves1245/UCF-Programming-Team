#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m; vector<ll> v(m); for (ll &i : v) cin >> i;
        vector<int> f(n + 1, 0); for (ll i : v) f[i]++;

        auto bs = [&](int t) -> int {
            ll free = 0, need = 0;
            for (int i = 1; i <= n; i++) {
                if (f[i] > t) {
                    need += f[i] - t;
                } else {
                    free += (t - f[i]) / 2;
                }
            }

            return need <= free;
        };

        int l = 1, h = 2 * m + 1;
        int t;
        int ans;
        for (int i = 0; i < 100; i++) {
            t = (l + h) / 2;
            if (bs(t)) {
                ans = t;
                h = t;
            } else {
                l = t;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
