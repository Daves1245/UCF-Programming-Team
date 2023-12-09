#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> v(n); for (auto &i : v) cin >> i;
        if (n == 1) {
            cout << 0 << endl;
            continue;
        }
        ll ret = INT_MIN;
        for (int i = 0; i < n; i++) {
            ret = max(ret, v[i] - v[(i + 1) % n]);
        }
        cout << max({
            ret,
            -v[0] + *max_element(v.begin() + 1, v.end()),
            v[n - 1] - *min_element(v.begin(), v.end() - 1)
            }) << endl;
    }
    return 0;
}
