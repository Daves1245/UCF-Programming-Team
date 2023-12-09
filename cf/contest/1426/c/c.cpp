#include <bits/stdc++.h>
using namespace std;
int f(int d, int n) {
    return d - 1 + ((n - 1) / d);
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int ans = INT_MAX;
        if (n == 1) {
            cout << 0 << endl;
            continue;
        }
        for (int i = (int) sqrt(n) - 10; i <= (int) sqrt(n) + 10; i++) {
            if (!i || i < 0) continue;
            ans = min(ans, f(i, n));
        }
        cout << ans << endl;
    }
    return 0;
}
