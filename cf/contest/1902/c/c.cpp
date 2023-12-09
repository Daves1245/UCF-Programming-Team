#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> v(n); for (auto &i : v) cin >> i;
        vector<ll> r;

        ll mx = *max_element(v.begin(), v.end());
        ll ans = 0;
        int seen = 0;
        for (auto &i : v) {
            if (i == mx) ans++;
            else r.push_back(mx - i);
        }

        if (!r.size()) {
            cout << 1 << endl;
            continue;
        }

        ll d = r[0];
        for (auto i : r) d = gcd(d, i);

        for (auto i : v) seen |= i == mx - d;
        if (!seen) ans = 0;

        for (auto i : v) {
            if (i == mx) continue;
            ans += (mx + d * seen - i) / d;
        }

        cout << ans + !seen << endl;
    }

    return 0;
}
