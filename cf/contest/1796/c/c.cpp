#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int l, r; cin >> l >> r;
        int n = 1;
        while ((l << n) <= r) n++;
        int ans = (r / (1 << (n - 1)) - l + 1);
        if (n > 1) ans += (n - 1) * max(0, (r / (1 << (n - 2)) / 3 - l + 1));
        cout << n << " " << ans << endl;
    }

    return 0;
}
