#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n >> x;
        vector<ll> v(n); for (auto &i : v) cin >> i;
        if (accumulate(v.begin(), v.end(), 0LL) % x) {
            cout << n << endl;
            continue;
        }

        int l = 0, r = n - 1;
        while (l < n && !(v[l] % x)) l++;
        while (r >= 0 && !(v[r] % x)) r--;

        if (r < l) {
            cout << -1 << endl;
            continue;
        }

        int ans = min(l + 1, n - r);
        cout << n - ans << endl;
    }
    return 0;
}
