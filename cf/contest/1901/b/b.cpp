#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n; vector<ll> v(n); for (auto &i : v) cin >> i;
        ll ans = v[0] - 1;
        int prev = v[0];
        for (int i = 0; i < n; i++) {
            if (v[i] > prev) {
                ans += v[i] - prev;
            }
            prev = v[i];
        }

        cout << ans << endl;
    }

    return 0;
}
