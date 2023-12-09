#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int l, r; cin >> l >> r;
        if (((l % 2) == 0) && (l != 2)) {
            cout << l / 2 << " " << l / 2 << endl;
            continue;
        }
        if (l <= 2) {
            if (r < 4) {
                cout << -1 << endl;
                continue;
            } else {
                cout << 2 << " " << 2 << endl;
                continue;
            }
        }
        if (r - l >= 1) {
            cout << (l / 2) + 1 << " " << (l / 2) + 1 << endl;
            continue;
        }
        bool f = false;
        for (int i = 2; !f && i * i <= l; i++) {
            if ((l % i) == 0) {
                f = true;
                cout << i << " " << l - i << endl;
            }
        }
        if (f) continue;
        cout << -1 << endl;
    }
    return 0;
}
