#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        int ud = abs(n - 1);
        int lr = abs(m - 1);
        if ((n == 1 && m > 2) || (m == 1 && n > 2)) {
            cout << -1 << endl;
        } else {
            int base = min(ud, lr);
            if ((max(ud, lr) - base) % 2 == 1) {
                cout << 2 * base + 2 * (max(ud, lr) - base) - 1 << endl;
            } else {
                cout << 2 * base + 2 * (max(ud, lr) - base) << endl;
            }
        }
    }

    return 0;
}

