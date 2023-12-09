#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll n, k, x; cin >> n >> k >> x;
    vector<ll> v(n); for (auto &i : v) cin >> i;
    sort(v.begin(), v.end());
    vector<ll> breaks;
    for (int i = 0; i < n - 1; i++) {
        if (v[i + 1] - v[i] > x) {
            breaks.push_back(-1 + (v[i + 1] - v[i] + x - 1) / x);
        }
    }
    sort(breaks.begin(), breaks.end());
    int m = breaks.size();
    vector<ll> ps(m + 1, 0); for (int i = 0; i < m; i++) ps[i + 1] = ps[i] + breaks[i];
    cout << m - (upper_bound(ps.begin(), ps.end(), k) - 1 - ps.begin()) + 1 << endl;
    return 0;
}
