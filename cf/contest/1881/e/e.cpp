#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vll v(n); for (auto &i : v) cin >> i;
        constexpr ll INF = 1e13;
        vll dp(n + 1, INF);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = min(dp[i], dp[i + 1] + 1);
            if (i + v[i] + 1 <= n)
                dp[i] = min(dp[i], dp[i + v[i] + 1]);
            else
                dp[i] = min(dp[i], (ll) n - i);
        }

        cout << dp[0] << endl;
    }

    return 0;
}
