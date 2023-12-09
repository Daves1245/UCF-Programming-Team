#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> v(n);
        for (auto &i : v) cin >> i;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            while (!(v[i] % 2)) cnt++, v[i] /= 2;
        }
        sort(v.begin(), v.end());
        while (cnt--) v[n - 1] *= 2;
        cout << accumulate(v.begin(), v.end(), 0LL) << endl;
    }
    return 0;
}
