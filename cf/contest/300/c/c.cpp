#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll M = 1e9 + 7;
int main() {
    ll a, b, n; cin >> a >> b >> n;

    auto modpow = [](auto &&self, ll n, int p) -> ll {
        if (!p) return 1;
        ll ret = self(self, n, p / 2) % M;
        return (p & 1) ? (n * (ret * ret % M)) % M : (ret * ret) % M;
    };

    vector<ll> fact(n + 10, 1);
    for (int i = 1; i < n + 10; i++) fact[i] = (i * fact[i - 1]) % M;

    auto inv = [&modpow](ll a) -> ll {
        return modpow(modpow, a, M - 2);
    };

    auto combo = [&](int n, int k) -> ll {
        // C[n][i] = fact[n]inv(fact[n - i]fact[i])
        return ((fact[n] * inv(fact[k]) % M) * inv(fact[n - k])) % M;
    };

    auto good = [&](ll n, ll a, ll b) -> int {
        int f = 1;
        while (n) {
            f &= ((n % 10) == a) || ((n % 10) == b);
            n /= 10;
        }
        return f;
    };

    auto excellent = [&](ll n, ll a, ll b) -> int {
        int s = 0;
        while (n) {
            s += n % 10;
            n /= 10;
        }
        return good(s, a, b);
    };

    ll ret = 0;
    for (int i = 0; i <= n; i++) {
        if (excellent(b * i + (n - i) * a, a, b)) {
            cout << "excel " << i << endl;
            cout << "adding " << combo(n, i) << endl;
            ret = (ret + combo(n, i)) % M;
        }
    }

    cout << ret << endl;

    return 0;
}
