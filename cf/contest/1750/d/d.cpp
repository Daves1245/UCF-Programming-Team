#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int M = 998244353;
int main() {
    vector<int> isprime(1e6, 1);
    isprime[0] = isprime[1] = 0;
    vector<int> primes;
    for (int i = 2; i < isprime.size(); i++)
        if (isprime[i]) {
            primes.push_back(i);
            for (int j = i + i; j < isprime.size(); j += i) isprime[j] = 0;
        }

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m; vector<int> v(n); for (auto &i : v) cin >> i;
        ll ans = m / v[0];
        if (n == 1) { cout << ans << endl; continue; }

        vector<int> f;
        ll n = v[0] / v[1];
        for (ll p : primes) {
            if (p * p > n) break;
            if (!(n % p)) f.push_back(p);
            while (!(n % p)) n /= p;
        }
        if (n > 1) f.push_back(n);

        for (int i = 1; i < n; i++) {
            ans *= !(v[i] % v[i - 1]);
            ans = (ans * inc_exc(f, )) % M;
        }
    }

    return 0;
}
