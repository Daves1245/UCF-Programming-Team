#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<ll> v(n + 1);
        vector<pair<ll, ll>> w(k);
        for (int i = 0; i <= n; i++) v[i] = n;
        for (auto &[a, b] : w) {
            cin >> a >> b;
            if (a > b) swap(a, b);
            v[a - 1] = min(v[a - 1], b - 1);
        }

        for (int i = n - 1; i >= 0; i--) {
            v[i] = min(v[i], v[i + 1]);
        }

        ll cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            cnt += v[i] - (i + 1) + 1;
        }

        cout << cnt << endl;
    }

    return 0;
}
