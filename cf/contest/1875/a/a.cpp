#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        ll a, b, n; cin >> a >> b >> n;
        vector<ll> v(n); for (auto &i : v) cin >> i;
        ll ret = b - 1;
        for (int i = 0; i < n; i++) {
            ret += min(a - 1, v[i]);
        }
        cout << ret + 1 << endl;
    }
    return 0;
}
