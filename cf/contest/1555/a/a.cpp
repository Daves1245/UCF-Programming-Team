#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        /*
        vector<int> dp(10000, 0);
        for (int i = 1; i <= 6; i++) dp[i] = 15;
        for (int i = 7; i <= 8; i++) dp[i] = 20;
        for (int i = 9; i <= 10; i++) dp[i] = 25;
        for (int i = 11; i <= n; i++) dp[i] = min({dp[i - 6] + 15, dp[i - 8] + 20, dp[i - 10] + 25});
        for (int i = 0; i < 100; i++) {
            cout << i << " " << dp[i] << endl;
        }
        */
        cout << (max((n % 2 + n - 6) / 2, 0LL)) * 5 + 15 << endl;
    }
    return 0;
}
