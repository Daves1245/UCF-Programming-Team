#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> v(n); for (ll &i : v) cin >> i;
        set<ll> s;
        for (ll i : v) s.insert(i);
        map<ll, ll> f;
        for (ll i : v) f[i]++;
        ll cnt = 0;
        for (ll i : s) {
            cnt += f[i] * (f[i] - 1) / 2;
        }

        cnt += f[1] * f[2];
        cout << cnt << endl;
    }

    return 0;
}
