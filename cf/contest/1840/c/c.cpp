#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, k, q; cin >> n >> k >> q;
        vector<ll> v(n); for (auto &i : v) cin >> i;
        vector<ll> w;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] <= q) cnt++;
            else {
                if (cnt >= k) {
                    w.push_back(cnt);
                }
                cnt = 0;
            }
        }
        if (cnt >= k) w.push_back(cnt);
        ll ret = 0;
        for (auto i : w) {
            ret += (i - k + 1) * (i - k + 2) / 2;
        }
        cout << ret << endl;
    }
    return 0;
}
