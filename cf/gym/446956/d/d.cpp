#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        ll cur = 1;
        ll ans = 0;
        while (cur < k) {
            cur += min(cur, k);
            ans++;
        }
        cout << ans + (n - cur + k - 1) / k << endl;
    }

    return 0;
}
