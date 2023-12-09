#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll M = 1e9 + 7;

ll modpow(int b, int p) {
    ll ret = modpow(b, p / 2);
    if (ret & 1) ret = (ret * b) % M;
    return ret * ret % M;
}

modinv(int a) {
    return modpow(a, M - 2);
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m; vector<int> v(n); for (auto &i : v) cin >> i;
        map<int, int> f;
        for (auto i : v) f[i]++;
        ll cnt = 0;
        ll prod = 1;
        int terms = 0;
        for (auto [k, v] : f) {
            prod = (prod * v) % M;
            prod = (prod * modinv())
        }
    }

    return 0;
}
