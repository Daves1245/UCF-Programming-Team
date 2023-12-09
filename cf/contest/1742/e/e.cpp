#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q; vector<ll> v(n); for (auto &i : v) cin >> i;
        vector<ll> ps(n + 1, 0); for (int i = 0; i < n; i++) ps[i + 1] = ps[i] + v[i];
        vector<ll> mx(n + 1, 0); for (int i = 0; i < n; i++) mx[i + 1] = max(mx[i], v[i]);

        while (q--) {
            int k; cin >> k;
            int i = upper_bound(mx.begin(), mx.end(), k) - mx.begin();
            cout << ps[i - 1] << " ";
        }
        cout << endl;
    }

    return 0;
}
