#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> v(n); for (auto &i : v) cin >> i;

        ll mx = *max_element(v.begin(), v.end());
        ll mn = *min_element(v.begin(), v.end());

        if (mx != mn) 
            cout << 2 * (ll) count(v.begin(), v.end(), mx) * (ll) count(v.begin(), v.end(), mn) << endl;
        else 
            cout << n * (n - 1) << endl;
    }

    return 0;
}
