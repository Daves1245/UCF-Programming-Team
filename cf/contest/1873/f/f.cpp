#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<ll> a(n), h(n); for (auto &i : a) cin >> i; for (auto &i : h) cin >> i;
        vector<ll> div(n, 1);
        vector<ll> ps(n + 1, 0);
        vector<ll> psdiv(n + 1, 0);
        for (int i = 0; i < n; i++) ps[i + 1] = ps[i] + a[i];
        for (int i = 0; i < n - 1; i++) {
            div[i] = (h[i] % h[i + 1]) == 0;
        }
        for (int i = 0; i < n; i++) {
            psdiv[i + 1] = psdiv[i] + div[i];
        }

        int mx = 0, cur = 0;
        for (int i = 0; i < n; i++) {
            if (div[i]) cur++;
            mx = max(mx, cur);
            if (!div[i]) cur = div[i];
        }

        auto bs = [&](ll m) -> bool {
            bool ret = 0;
            for (int i = 0; i <= n - m; i++) {
                // cout << "i " << i << " m " << m << " ps " << ps[i + m] - ps[i] << " k " << k << endl;
                if (psdiv[i + m - 1] - psdiv[i] == m - 1) {
                    ret |= ps[i + m] - ps[i] <= k;
                }
            }
            return ret;
        };

        /*
        cout << "div "; for (auto i : div) cout << i << " "; cout << endl;
        cout << "psdiv "; for (auto i : psdiv) cout << i << " "; cout << endl;
        cout << "ps "; for (auto i : ps) cout << i << " "; cout << endl;
        */
        ll lo = 1, hi = mx + 10;
        ll m = (lo + hi) / 2;
        ll ans = 0;
        for (int i = 0; i < 20; i++) {
            m = (lo + hi) / 2;
            if (bs(m)) {
                ans = max(ans, m);
                lo = m;
            } else {
                hi = m;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
