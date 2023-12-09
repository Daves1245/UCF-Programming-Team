#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;

    vector<bool> prime(1e6, 1);
    prime[0] = prime[1] = 0;
    for (int i = 2; i < prime.size(); i++)
        if (prime[i])
            for (int j = i + i; j < prime.size(); j += i) prime[j] = false;

    while (t--) {
        int n, e; cin >> n >> e;
        vector<ll> l(n), r(n), v(n); for (auto &i : v) cin >> i;
        for (int i = 0; i < e; i++) {
            int c = i;
            int cnt = 0;
            while (c < n) {
                if (v[c] != 1) l[c] = cnt + 1, cnt = 0;
                else cnt++;
                c += e;
            }

            c -= e;
            cnt = 0;
            while (c >= 0) {
                if (v[c] != 1) r[c] = cnt + 1, cnt = 0;
                else cnt++;
                c -= e;
            }
        }

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if (prime[v[i]]) ans += l[i] * r[i] - 1;
        }

        cout << ans << endl;
    }
    return 0;
}
