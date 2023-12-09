#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        int c, d; cin >> c >> d;
        int e, f; cin >> e >> f;

        int bx = a - c, by = b - d;
        int cx = a - e, cy = b - f;

        int ans = 1;
        if (bx <= 0 && cx <= 0) {
            ans += -1 * max(cx, bx);
        }

        if (by <= 0 && cy <= 0) {
            ans += -1 * max(cy, by);
        }

        if (bx >= 0 && cx >= 0) {
            ans += min(cx, bx);
        }

        if (by >= 0 && cy >= 0) {
            ans += min(cy, by);
        }

        cout << ans << endl;
    }

    return 0;
}
