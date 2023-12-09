#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
int main() {
    vll pr(1e5, 1);
    vll primes;
    pr[0] = pr[1] = 0;
    for (int i = 0; i < pr.size(); i++)
        if (pr[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j < pr.size(); j += i) pr[j] = 0;
        }

    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n >> x;
        if (n % x) {
            cout << -1 << endl;
            continue;
        }

        vector<int> v(n);
        for (int i = 0; i < n; i++) v[i] = i + 1;
        v[0] = x;
        v[n - 1] = 1;
        vll f;
        int m = n / x;
        for (auto d : primes) {
            if (d * d > m) break;
            while (!(m % d)) {
                f.push_back(d);
                m /= d;
            }
        }
        if (m != 1) f.push_back(m);
        sort(f.begin(), f.end());

        int k = 0;
        for (int i = 1; i < n - 1; i++) {
            if (!((i + 1) % x)) {
                v[i] = x *= f[k++];
            }
        }

        for (auto i : v) cout << i << " "; cout << endl;
    }
    return 0;
}
