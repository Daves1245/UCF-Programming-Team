#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vll v(n); for (ll &i : v) cin >> i;
        vll l(n); for (int i = 0; i < n; i++) l[i] = v[i] + i;
        for (int i = 1; i < n; i++) l[i] = max(l[i], l[i - 1]);
        vll r(n); for (int i = 0; i < n; i++) r[i] = v[i] - i;
        for (int i = n - 2; i >= 0; i--) r[i] = max(r[i], r[i + 1]);
        ll ans = 0;
        for (int i = 1; i < n - 1; i++) ans = max(ans, l[i - 1] + v[i] + r[i + 1]);
        cout << ans << endl;
    }

    return 0;
}
