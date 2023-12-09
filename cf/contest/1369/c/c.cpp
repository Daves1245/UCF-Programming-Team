#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<ll> a(n); for (auto &i : a) cin >> i;
        vector<ll> w(k); for (auto &i : w) cin >> i;
        deque<ll> dq;
        sort(a.begin(), a.end());
        for (auto i : a) dq.push_back(i);
        sort(w.begin(), w.end());
        ll ans = 0;
        for (int i = 0; (i < k) && (w[i] == 1); i++) {
            ans += 2 * dq.back();
            dq.pop_back();
        }

        for (int i = k - 1; (i >= 0) && (w[i] > 1); i--) {
            ans += dq.front(); dq.pop_front();
            for (int j = 0; j < w[i] - 2; j++) dq.pop_front();
            ans += dq.back(); dq.pop_back();
        }

        cout << ans << endl;
    }
    return 0;
}
