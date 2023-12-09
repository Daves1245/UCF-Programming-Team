#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> v(n); for (auto &i : v) cin >> i;
        sort(v.begin(), v.end());
        ll mx = v[0];
        for (int i = 1; i < n; i++) {
            mx = max(mx, v[i] - v[i - 1]);
        }
        cout << mx << endl;
    }
    return 0;
}
