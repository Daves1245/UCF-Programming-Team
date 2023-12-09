#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int k, n; cin >> k >> n;
        vector<ll> v(n); for (auto &i : v) cin >> i, i = k - i;
        sort(v.begin(), v.end());
        vector<ll> ps(n + 1, 0); for (int i = 0; i < n; i++) ps[i + 1] = ps[i + 1] = ps[i] + v[i];
        cout << lower_bound(ps.begin(), ps.end(), k) - ps.begin() - 1 << endl;
    }
    return 0;
}
