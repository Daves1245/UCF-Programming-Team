#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
using lll = __int128;
using ll = long long;
int main() {
    auto get_sum = [](ll k, int len) -> lll {
        lll ret = 1;
        cout << "k " << k << " len " << len << endl;
        for (int i = 0; i < len; i++) {
            if (ret * k > 1e27) return 1e27;
            ret *= k;
        }
        if (ret < 1e18)
            cout << "returning sum of " << (ll)(ret - 1) / (ll)(k - 1) << endl;
        return (ret - 1) / (lll)(k - 1);
    };

    auto bs = [&](int len, lll n) -> lll {
        ll l = 2, r = 1e18;
        ll m;
        lll ret = -1;
        ll val;
        for (int i = 0; i < 70; i++) {
            m = l + (r - l) / 2;
            if (get_sum(m, len) >= n) {
                ret = get_sum(m, len);
                val = m;
                cout << "left" << endl;
                r = m;
            } else {
                cout << "right" << endl;
                l = m + 1;
            }
            cout << l << " " << r << endl;
        }

        cout << "end of bs, l = " << l << " and r = " << r << " and best k = " << val << endl;
        return ret;
    };

    bs(3, 10101);

    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        int found = 0;


        /*
           for (int len = 3; len < 64; len++) {
           lll val = bs(len, (lll) n);
           if (val < 1e18) {
           ll tmp = (ll) val;
           cout << "for len " << len << " best val is " << tmp << " but n is " << n << endl;
           }
           found |= val == (lll)n;
           }
           */

        cout << (found ? "YES" : "NO") << endl;
    }

    return 0;
}
