#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int n, q; cin >> n >> q;
    vector<ll> a(n); for (auto &i : a) cin >> i;

    while (q--) {
        int k; cin >> k;
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans &= a[i];
        }

        auto gcost(int n, int i) -> int {
            for (int j = 0; j < n; j++) {
                if (!((1 << i) & a[j])) {
                    ll reduced = ~a[j] & ((1 << (j + 1)) - 1);
                    cost += reduced + 1;
                }
            }

        };

        for (int i = 31; i >= 0; i--) {
            ll cost = 0;
            for (int j = 0; j < n; j++) {
                if (!((1 << i) & a[j])) {
                    ll reduced = ~a[j] & ((1 << (j + 1)) - 1);
                    cost += reduced + 1;
                }
            }
            if (cost <= k) {
                k -= cost;
                ans |= (1 << i);
            }
        }

        cout << ans << endl;
    }

    return 0;
}
