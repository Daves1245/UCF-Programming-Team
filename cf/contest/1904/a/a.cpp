#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        ll a, b; cin >> a >> b;

        ll dr[] = {a, a, -a, -a, b, b, -b, -b};
        ll dc[] = {b, -b, b, -b, a, -a, a, -a};

        ll kx, ky; cin >> kx >> ky;
        ll qx, qy; cin >> qx >> qy;

        ll cnt = 0;
        for (int i = 0; i < 8; i++) {
            ll x = kx + dr[i], y = ky + dc[i];
            for (int j = 0; j < 8; j++) {
                if ((x + dr[j] == qx) && (y + dc[j] == qy)) {
                }
                cnt += ((x + dr[j] == qx) && (y + dc[j] == qy));
            }
        }

        cout << cnt / (1 + 3 * (a == b))<< endl;
    }

    return 0;
}
