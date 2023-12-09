#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> v(n); for (auto &i : v) cin >> i;
        ll sum = accumulate(v.begin(), v.end(), 0LL);
        sum %= n;
        cout << sum * (n - sum) << endl;
    }
    return 0;
}
