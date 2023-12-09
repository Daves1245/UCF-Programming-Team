#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> v(n); for (auto &i : v) cin >> i;
        ll last = v[0];
        ll sum = 0;
        ll cur = INT_MIN;
        for (auto i : v) {
            if ((i > 0) ^ (last > 0)) {
                sum += cur;
                cur = i;
            } else {
                cur = max(cur, i);
            }
            last = i;
        }
        cout << sum + cur << endl;
    }
    return 0;
}
