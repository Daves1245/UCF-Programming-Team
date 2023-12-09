#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;
        vector<int> ps(n + 1, 0); for (int i = 0; i < n; i++) ps[i + 1] = ps[i] ^ v[i];

        ll cnt = 0;
        for (int m = 0; m * m <= 2 * n - 1; m++) {
            vector<int> f(4 * n, 0);
            f[0] = 1;
            for (int i = 0; i < n; i++) {
                cnt += f[m * m ^ ps[i + 1]];
                f[ps[i + 1]]++;
            }
        }

        cout << n * (n + 1) / 2 - cnt << endl;
    }

    return 0;
}
