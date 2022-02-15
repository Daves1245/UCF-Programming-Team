/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;

#define lsb(x) ((x) & -(x))

using ll = long long;

struct bit {
    vector<ll> ft;
    bit(ll n) {
        ft.assign(n + 2, 0);
    }

    void update(ll i, ll v) {
        for (; i < ft.size(); i += lsb(i)) {
            ft[i] += v;
        }
    }

    ll query(ll i) {
        ll ret = 0;
        for (; i; i -= lsb(i)) {
            ret += ft[i];
        }
        return ret;
    }

    ll query(int i, int j) {
        return query(j) - query(i - 1);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll n, k; cin >> n >> k;
    bit ft(n);
    for (ll i = 0; i < k; i++) {
        char c; cin >> c;
        if (c == '+') {
            ll x, v; cin >> x >> v;
            x++;
            ft.update(x, v);
        }
        if (c == '?') {
            ll x; cin >> x;
            cout << ft.query(x) << '\n';
        }
    }
    return 0;
}

