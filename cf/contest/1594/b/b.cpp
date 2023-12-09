#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int M = 1e9 + 7;
ll p(int a, int b) {
    if (!b) return 1;
    else return (a * p(a, b - 1)) % M;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        ll ans = 0;
        for (int i = 0; i < 32; i++) {
            if (k & (1 << i)) {
                ans = (ans + p(n, i)) % M;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
