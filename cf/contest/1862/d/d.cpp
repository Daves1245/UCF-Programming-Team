#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        ll x; cin >> x;
        ll a;

        auto bs = [&](ll n) -> bool {
            a = n * (n + 1) / 2;
            return
                a <= x;
        };

        ll l = 1, h = 2648956421, m = l + (h - l) / 2;
        for (int i = 0; i < 100; i++) {
            m = (l + h) / 2;
            if (bs(m)) l = m + 1;
            else h = m - 1;
        }

        // cout << "m " << m << endl;
        cout << m + (x - a + 1) << endl;
    }
    return 0;
}
