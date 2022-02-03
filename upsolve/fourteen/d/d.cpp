#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<pair<ll, ll>>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t; cin >> t;
    while (t--) {
        int num_dishes, thresh; cin >> num_dishes >> thresh;

        vll dishes(num_dishes + 1);
        int net_time = 0;
        for (int i = 1; i <= num_dishes; i++) {
            cin >> dishes[i].first >> dishes[i].second;
            net_time += dishes[i].second;
        }

        // dp[dishi][time]
        vector<vector<ll>> dp(num_dishes + 1, vector<ll>(net_time + 1, 0));

        int min_time = INT_MAX;
        for (int i = 1; i <= num_dishes; i++) {
            for (int j = 1; j <= net_time; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j - dishes[i].first >= 0 && dp[i - 1][j - dishes[i].first] + dishes[i].second > dp[i][j]) {
                    dp[i][j] = dp[i - 1][j - dishes[i].first] + dishes[i].second;
                }
                if (j < min_time && dp[i][j] >= thresh) {
                    min_time = j;
                    break;
                }
                if (j > min_time) {
                    break;
                }
            }
        }

        cout << min_time << endl;
    }
    return 0;
}
