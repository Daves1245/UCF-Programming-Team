#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    constexpr int N = 2e5;
    vector<vector<ll>> ps(N + 1, vector<ll>(32, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 32; j++) {
            ps[i][j] = ps[i - 1][j] + ((i & (1 << j)) > 0);
        }
    }
    int t; cin >> t;
    while (t--) {
        int l, r; cin >> l >> r;
        int n = r - l + 1;
        ll ans = n;
        for (int i = 0; i < 32; i++) {
            ans = min(ans, n - (ps[r][i] - ps[l - 1][i]));
        }
        cout << ans << endl;
    }
    return 0;
}
