#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> v(n); for (ll &i : v) cin >> i;
        vector<ll> ps(n + 1, 0); for (int i = 0; i < n; i++) ps[i + 1] = ps[i] + v[i];
        ll mx = *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());
        // for (auto i : v) cout << i << " "; cout << endl;
        // for (auto i : ps) cout << i << " "; cout << endl;
        for (int k = 1; k <= n; k++) {
            if (n % k) continue;
            ll l = ps[n], r = 0;
            for (int i = 0; i < n / k; i++) {
                l = min(l, ps[(i + 1) * k] - ps[i * k]);
                r = max(r, ps[(i + 1) * k] - ps[i * k]);
                mx = max(mx, abs(l - r));
            }
            // cout << k << " " << abs(l - r) << endl;
        }

        cout << mx << endl;
    }

    return 0;
}
