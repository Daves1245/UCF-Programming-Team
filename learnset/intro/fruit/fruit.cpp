/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        int lo = 0, hi = 1001, mid;
        int mres;
        for (int i = 0; i < 50; i++) {
            mid = lo + (hi - lo) / 2;
            int res = 0;
            int m = 0;
            for (int j : v) {
                res += mid;
                res -= j;
                m = max(m, res);
                if (res < 0) {
                    break;
                }
            }

            if (res < 0) {
                lo = mid + 1;
            } else {
                hi = mid;
                mres = m;
            }
        }
        cout << mid << " " << mres << endl;
    }
    return 0;
}

