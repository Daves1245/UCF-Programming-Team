#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int w, f; cin >> w >> f;
        int n; cin >> n; vector<int> v(n); for (auto &i : v) cin >> i;
        ll s = accumulate(v.begin(), v.end(), 0LL);
        vector<ll> dp(s + 1, 0); dp[0] = 1;
        for (auto i : v) for (int j = s; j >= i; j--) dp[j] |= dp[j - i];
        int best = 1e6;
        for (int i = 0; i <= s; i++) if (dp[i])
            best = min(best, (int) max(ceil(i / (double) w), ceil((s - i) / (double) f)));
        cout << best << endl;
    }

    return 0;
}
