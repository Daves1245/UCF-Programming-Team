#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> v(1);
        cin >> v[0];
        int k = 0;
        for (int i = 0; i < n - 1; i++) {
            ll tmp; cin >> tmp;
            // cout << "tmp " << tmp << endl;
            if ((tmp >= 0) == (v[k] >= 0)) {
                v[k] += tmp;
                // cout << "add " << v[k] << endl;
            } else {
                v.push_back(tmp);
                k++;
                // cout << "pb " << v[k] << endl;
            }
        }

        cout << "v ";
        for (auto i : v) cout << i << " ";
        cout << endl;

        vector<ll> ps(1);
        ps[0] = v[0];
        for (int i = 1; i < v.size(); i++) {
            ps.push_back(ps[i - 1] + v[i]);
        }

        cout << "ps ";
        for (auto i : ps) cout << i << " ";
        cout << endl;

        auto bs = [&](int k) -> ll {
            ll ret = 0;
            bool reached = false;
            for (int i = 0; i < ps.size(); i++) {
                ret += ps[i];
                reached |= ret >= k;
                if (reached && ret < k) ret = k;
            }

            return ret;
        };

        ll l = 0, r = 100, m;
        ll best = 0;
        for (int i = 0; i < 10; i++) {
            m = l + (r - l) / 2;
            cout << "k " << m << " bs " << bs(m) << endl;
            if (bs(m) > best) {
                l = m;
                cout << "l" << endl;
            } else {
                r = m;
                cout << "r" << endl;
            }

            best = max(best, bs(m));
            cout << "best " << best << endl;
        }

        cout << m - 1 << endl;
    }

    return 0;
}
