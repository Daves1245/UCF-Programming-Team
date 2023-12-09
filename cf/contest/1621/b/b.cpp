#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        using st = tuple<int, int, int>;
        vector<st> v(n); 

        int mn = INT_MAX, mx = INT_MIN;
        int mnc = mn, mxc = mx;
        int l = 0, lc = INT_MAX;
        int f;
        for (int i = 0; i < n; i++) {
            auto &[a, b, c] = v[i]; cin >> a >> b >> c;
            f = a < mn && b > mx;
            if (f) {
                mn = a;
                mx = b;
                l = b - a + 1;
                mnc = mxc = lc = c;
            }
            if (a < mn) {
                mn = a;
                mnc = c;
                l = mx - mn + 1;
                lc = mnc + mxc;
            } else if (a == mn) {
                mnc = min(mnc, c);
                lc = min(lc, mnc + mxc);
            }
            if (b > mx) {
                mx = b;
                mxc = c;
                l = mx - mn + 1;
                lc = mnc + mxc;
            } else if (b == mx) {
                mxc = min(mxc, c);
                lc = min(lc, mnc + mxc);
            }

            cout << min(lc, mnc + mxc) << endl;
        }
    }
    return 0;
}
