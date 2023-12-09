#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> v(n); for (ll &i : v) cin >> i;
        ll mx = *max_element(v.begin(), v.end());
        ll cr = v[0];
        for (int i = 1; i < n; i++) {
            if (((v[i] & 1) != (v[i - 1] & 1))) {
                cr = max(v[i], cr + v[i]);
            } else {
                cr = v[i];
            }
            mx = max(mx, cr);
        }
        cout << mx << endl;
    }

    return 0;
}
