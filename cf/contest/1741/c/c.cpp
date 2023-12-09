#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define lsum(l) (ps[l + 1])
#define rsum(r) (ps[n - 1 + 1] - ps[r - 1])
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        ll m = 0, s = 0;
        int mth = 0, cth = 0;
        vector<ll> v(n); for (auto &i : v) cin >> i, m = max(m, i);
        vector<ll> ps(n + 1, 0); for (int i = 0; i < n; i++) ps[i + 1] = ps[i] + v[i];
        int l = 0, r = n - 1;
        while (l < r) {
            if (lsum(l) == rsum(r)) l--, r--, mth = max({mth, r - l + 1, n - (r - l) + 1});
            else if (lsum(l) < r) l++;
            else r--;
        }

        cout << mth << endl;
    }
    return 0;
}
