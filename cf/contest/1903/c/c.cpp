#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> v(n); for (ll &i : v) cin >> i;
        vector<ll> ps(n + 1, 0); for (int i = 0; i < n; i++) ps[i + 1] = ps[i] + v[i];

        ll sum = accumulate(v.begin(), v.end(), 0LL);
        ll roll_sum = 0;
        ll k = 1;
        /*
        cout << "v ";
        for (ll i : v) cout << i << " "; cout << endl; cout << "ps ";
        for (int i = 0; i < n; i++) cout << ps[n] - ps[i + 1] << " "; cout << endl;
        */
        for (int i = 0; i < n - 1; i++) {
            ll val = ps[n] - ps[i + 1];
            if (val >= 0) {
                // cout << " break at " << v[i] << endl;
                sum += val;
            }
        }
        cout << sum << endl;
    }

    return 0;
}
