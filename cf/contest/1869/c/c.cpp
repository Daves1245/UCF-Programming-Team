#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll t; cin >> t;
    while (t--) {
        ll n, m; cin >> n >> m;
        if ((n == 1) && (m != 1)) {
            cout << 2 << endl;
            for (ll i = 0; i < m; i++) cout << i << " "; cout << endl;
            continue;
        }
        if (m == 1) {
            cout << 0 << endl;
            for (ll i = 0; i < n; i++) cout << 0 << endl;
            continue;
        }
        cout << min(n + 1, m) << endl;
        if (m <= n) {
            for (ll i = 0; i < m; i++) {
                cout << (i - 1 + m) % m << " ";
            }
            cout << endl;
            ll i;
            for (i = 1; i < m - 1; i++) {
                for (ll j = 0; j < m; j++) {
                    cout << (j + i) % m << " ";
                }
                cout << endl;
            }
            ll cp = i;
            for (; i < n; i++) {
                for (ll j = 0; j < m; j++) {
                    cout << (cp + j) % m << " ";
                }
                cout << endl;
            }
        } else {
            for (ll i = 0; i < n; i++) {
                for (ll j = 0; j < m; j++) {
                    cout << (i + j + 1) % m << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}
