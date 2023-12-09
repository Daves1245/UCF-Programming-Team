#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        ll n, x, y; cin >> n >> x >> y;
        string a, b; cin >> a >> b;
        string c;
        for (int i = 0; i < n; i++) {
            c += '0' + (a[i] != b[i]);
        }

        // cout << "s " << c << endl;

        int cnt = count(c.begin(), c.end(), '1');
        if (cnt & 1) {
            cout << -1 << endl;
            continue;
        }


        ll cost = 0;
        if (cnt == 2) {
            for (int i = 0; i < n; i++) {
                if ((c[i] == '1') && (c[i + 1] == '1')) {
                    cost = min(x, 2 * y);
                }
            }
            if (!cost) cost = y;
        } else {
            cost = y * cnt / 2;
        }

        cout << cost << endl;
    }

    return 0;
}
