#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n >> x;
        vector<ll> v(n); for (auto &i : v) cin >> i;

        auto bs = [&](ll m) -> bool {
            ll ret = 0;
            for (int i = 0; i < n; i++) {
                ret += max(0LL, m - v[i]);
            }
            return ret <= x; 
        };

        ll l = 1, h = 1e10;
        ll m = (l + h) / 2;
        ll ans = 1;
        for (int i = 0; i < 200; i++) {
            m = (l + h) / 2;
            if (bs(m)) {
                l = m + 1;
                ans = m;
            } else {
                h = m;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
