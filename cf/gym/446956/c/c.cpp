#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        ll n, k, b, s; cin >> n >> k >> b >> s;
        if ((s < b * k) || (s > k * b + (k - 1) * n)) {
            cout << -1 << endl;
            continue;
        }

        vector<ll> ans(n, 0);
        ans[0] = b * k;

        ll rsum = s - b * k;
        for (int i = 0; i < n; i++) {
            ll tmp = min(k - 1, rsum);
            ans[i] += tmp;
            rsum -= tmp;
        }

        for (auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
